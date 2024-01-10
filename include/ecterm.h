/* 
 * ecterm.c - EmulC terminal stuff 
 *
 * Part of STonC (C) 1998-2002 Laurent Vogel
 * Covered by the GPL version 2 or later; see COPYING for details
 */

#ifndef H_ECTERM
#define H_ECTERM

typedef short te_wchar;

#include "emulc.h"

#define EC_ROWS 25
#define EC_COLS 80

#define TE_CHAR_MASK 0x0FF
#define TE_ATTR_MASK 0xF00
#define TE_ATTR_BOLD 0x100
#define TE_ATTR_UC   0x200
#define TE_ATTR_REV  0x400
#define TE_ATTR_SO   0x800

/* functions analogous to escape sequences */
void te_clear(Term t);
void te_clrtobot(Term t);
void te_clrtoeol(Term t);
void te_del_n_chars(Term t, int n);
void te_del_one_char(Term t);
void te_ins_n_chars(Term t, int n);
void te_ins_one_char(Term t);
void te_del_n_lines(Term t, int n);
void te_ins_n_lines(Term t, int n);
void te_ins_one_line(Term t);
void te_del_one_line(Term t);
void te_move(Term t, int row, int col);
void te_set_attr(Term t, int attr);

void te_replace_line(Term t, int row, te_wchar *line);

void te_redraw(Term t);
void te_refresh(Term t);

void te_curs_set(Term t, int visibility);

#endif /* H_ECTERM */

