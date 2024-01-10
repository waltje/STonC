/*
 * interrupt.c : 68000-family interrupt management
 *
 * (C) 2002 Laurent Vogel - GPL version 2 or later (see file COPYING)
 */

/*
 * taken from [68000UM.pdf]
 *
 * 6.3.2 Interrupts
 *
 * Seven levels of interrupt priorities are provided, numbered from 
 * 1-7. All seven levels are available except for the 48-pin version 
 * for the MC68008.
 *
 *   NOTE
 *   The MC68008 48-pin version supports only three interrupt
 *   levels: 2, 5, and 7. Level 7 has the highest priority.
 *
 * Devices can be chained externally within interrupt priority levels, 
 * allowing an unlimited number of peripheral devices to interrupt the 
 * processor. The status register contains a 3-bit mask indicating the 
 * current interrupt priority, and interrupts are inhibited for all 
 * priority levels less than or equal to the current priority.
 *
 * An interrupt request is made to the processor by encoding the 
 * interrupt request levels 1-7 on the three interrupt request lines; 
 * all lines negated indicates no interrupt request.
 * 
 * Interrupt requests arriving at the processor do not force immediate 
 * exception processing, but the requests are made pending. Pending 
 * interrupts are detected between instruction executions. If the 
 * priority of the pending interrupt is lower than or equal to the 
 * current processor priority, execution continues with the next 
 * instruction, and the interrupt exception processing is postponed 
 * until the priority of the pending interrupt becomes greater than 
 * the current processor priority.
 *
 * If the priority of the pending interrupt is greater than the current 
 * processor priority, the exception processing sequence is started. 
 * A copy of the status register is saved; the privilege mode is set 
 * to supervisor mode; tracing is suppressed; and the processor priority
 * level is set to the level of the interrupt being acknowledged. The 
 * processor fetches the vector number from the interrupting device 
 * by executing an interrupt acknowledge cycle, which displays the 
 * level number of the interrupt being acknowledged on the address bus.
 *
 * If external logic requests an automatic vector, the processor 
 * internally generates a vector number corresponding to the interrupt 
 * level number. If external logic indicates a bus error, the interrupt 
 * is considered spurious, and the generated vector number references 
 * the spurious interrupt vector. The processor then proceeds with the 
 * usual exception processing, saving the format/offset word (MC68010 
 * only), program counter, and status register on the supervisor stack. 
 * The offset value in the format/offset word on the MC68010 is the 
 * vector number multiplied by four. The format is all zeros. The saved 
 * value of the program counter is the address of the instruction that 
 * would have been executed had the interrupt not been taken. The 
 * appropriate interrupt vector is fetched and loaded into the program 
 * counter, and normal instruction execution commences in the interrupt
 * handling routine. 
 *
 * Priority level 7 is a special case. Level 7 interrupts cannot be 
 * inhibited by the interrupt priority mask, thus providing a 
 * "nonmaskable interrupt" capability. An interrupt is generated each 
 * time the interrupt request level changes from some lower level to 
 * level 7. A level 7 interrupt may still be caused by the level 
 * comparison if the request level is a 7 and the processor priority 
 * is set to a lower level by an instruction.
 *
 */

/*
 * this interrupt manager (IM) is really a part of the CPU emulation.
 * however, since the interrupt sources and the CPU emulation may 
 * live in different "threads", they are separated here.
 *
 * the IM maintains a copy of the Interrupt priority Level (IPL).
 * Whenever SR changes, the CPU gives the new IPL value to the IM.
 * Interrupt sources can at any time request an interrupt to the IM.
 * Whenever the IPL changes, or new interrupts are requested, the IM
 * determines whether an interrupt should occur.
 * Regularly (at least after instructions that change SR, at most 
 * before every instruction) the CPU asks the IM to know if an 
 * interrupt processing should occur.
 *
 * Finally, the IM implements the STOP instruction ???
 */

 


/* mask of pending interrupt requests */
static int pending_mask;

/* a copy of the IPL value */
static int ipl;

/* the level of the highest interrupt pending, if allowed.
 * this will be updated when interrupts are requested of whan ipl changes.
 */
static int top_irq;

/* initialises the IM */
void init_interrupts(void);

/* called by the CPU to update the IPL value (may not change) */
void update_ipl(int new_ipl);

/* called by the CPU to ask if an interrupt handling should happen.
 * returns 0 if not, non null if yes.
 * level holds the new IPL, vector holds the vector number.
 */
int check_interrupt(int *level, int *vector);

/* called by an interrupt source to request an interrupt */
void request_interrupt(int level);



/* initialises the IM */
void init_interrupts(void)
{
  pending_mask = 0;
  ipl = 0;
  top_irq = 0;
}

static int highest_bit(int a)
{
  int b = 0;
  while(a) {
    b++;
    a>>=1;
  }
  return b;
}

static void update_top(void)
{
  if(pending_mask & 0x80) {
    /* NMI */
    top_irq = 7;
  } else if(pending_mask >= (1 << ipl)) {
    top_irq = highest_bit(pending_mask);
  } else {
    top_irq = 0;
  }
}
  

/* called by the CPU to update the IPL value (may not change) */
void update_ipl(int new_ipl)
{
  assert(new_ipl >= 1 && new_ipl <= 7);
  ipl = new_ipl;
  update_top();
}

#define SPURIOUS_VECTOR 24
#define AUTO_VECTOR 25

/* called by the CPU to ask if an interrupt handling should happen.
 * returns 0 if not, the new IPL if yes.
 * vector holds the vector number.
 * the interrupt request is removed from the pending mask.
 */
int check_interrupt(int *vector);
{
  switch(top_irq) {
    case 0: 
      return 0; 
    case 2: 
    case 4: 
      *vector = AUTO_VECTOR + top_irq;
      break;
    case 6: 
      *vector = mfp_do_interrupt();
      if(*vector == 0) {
        *vector = SPURIOUS_VECTOR;
      }
      break;
    default:
      *vector = SPURIOUS_VECTOR;
      break;
  }
  pending_mask ^= (1 << top_irq);
  return top_irq;
}
    
/* called by an interrupt source to request an interrupt */
void request_interrupt(int level)
{
  pending_mask |= (1 << level);
  update_top();
}


/*
when SR changes, check whether interrupt should occur.
STOP:
to implement inside the alarm manager:
- while the next alarm is after the period by which I can pause,
  pause.
- if there is an alarm, execute it immediately, adding to the
  delta time the delay.

stop: while no interrupt occurs, loop.
*/

void stop(void)
{
  int vector;
  while(! check_interrupt(&vector)) {
    next_alarm();
  }
  INTERRUPT(vector);
}

/*
 todo, handle alarms with long ints 
*/


/*
* trace:
*
* quand on change sr et qu'on met trace à 1,
* l'interruption trace se produit après l'instruction suivante???

*
* ma proposition,
* une boucle qui teste de temps en temps les flags;
* une boucle qui teste après chaque instruction les flags;
* quand, dans la boucle rapide, SR est modifié, on teste 
* pour les interuptions, et ...
* si en modifiant SR le bit trace est mis, alors
* on sort de cette boucle et on va dans l'autre.
* => il faut que SET_SR soit la dernière instruction de
* l'opcode, car il peut y avoir un longjmp dedans.
*/

todo:
mettre spent_cycles() après l'instruction?



These paragraphs describe the processing that occurs when multiple 
exceptions arise simultaneously. Exceptions can be grouped by their 
occurrence and priority. 

The group 0 exceptions are reset, bus error, and address error. These 
exceptions cause the instruction currently being executed to abort and 
the exception processing to commence within two clock cycles. 

The group 1 exceptions are trace and interrupt, privilege violations, 
and illegal instructions. Trace and interrupt exceptions allow the 
current instruction to execute to completion, but pre-empt the 
execution of the next instruction by forcing exception processing to 
occur. A privilege-violating instruction or an illegal instruction is 
detected when it is the next instruction to be executed. 

The group 2 exceptions occur as part of the normal processing of 
instructions. The TRAP, TRAPV, CHK, and zero divide exceptions are in 
this group. For these exceptions, the normal execution of an instruction 
may lead to exception processing.

Group 0 exceptions have highest priority, whereas group 2 exceptions have 
lowest priority. Within group 0, reset has highest priority, followed 
by address error and then bus error. Within group 1, trace has priority 
over external interrupts, which in turn takes priority over illegal 
instruction and privilege violation. Since only one instruction can be 
executed at a time, no priority relationship applies within group 2.

The priority relationship between two exceptions determines which is 
taken, or taken first, if the conditions for both arise simultaneously. 
Therefore, if a bus error occurs during a TRAP instruction, the bus 
error takes precedence, and the TRAP instruction processing is aborted. 
In another example, if an interrupt request occurs during the execution 
of an instruction while the T bit is asserted, the trace exception has 
priority and is processed first. Before instruction execution resumes, 
however, the interrupt exception is also processed, and instruction 
processing finally commences in the interrupt handler routine.

As a general rule, the lower the priority of an exception, the sooner 
the handler routine for that exception executes. For example, if 
simultaneous trap, trace, and interrupt exceptions are pending, the 
exception processing for the trap occurs first, followed immediately by
exception processing for the trace and then for the interrupt. When the 
processor resumes normal instruction execution, it is in the interrupt 
handler, which returns to the trace handler, which returns to the trap 
execution handler. This rule does not apply to the reset exception; its 
handler is executed first even though it has the highest priority, 
because the reset operation clears all other exceptions.

trace:

The trace facility is controlled by the T bit in the supervisor 
portion of the status register. If the T bit is cleared (off), 
tracing is disabled and instruction execution proceeds from
instruction to instruction as normal. If the T bit is set (on) at 
the beginning of the execution of an instruction, a trace 
exception is generated after the instruction is completed. If the
instruction is not executed because an interrupt is taken or because 
the instruction is illegal or privileged, the trace exception does 
not occur. The trace exception also does not occur if the instruction 
is aborted by a reset, bus error, or address error exception. If the
instruction is executed and an interrupt is pending on completion, 
the trace exception is processed before the interrupt exception. 
During the execution of the instruction, if an exception is forced 
by that instruction, the exception processing for the instruction
exception occurs before that of the trace exception. 

As an extreme illustration of these rules, consider the arrival of 
an interrupt during the execution of a TRAP instruction while 
tracing is enabled. First, the trap exception is processed, then 
the trace exception, and finally the interrupt exception. Instruction
execution resumes in the interrupt handler routine.


todo:
trouver les flags utilisés de cpu, les retirer.


