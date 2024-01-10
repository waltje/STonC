/*
 * ui.h : user interface for STonC.
 *
 * Part of STonC (C) 1998-2002 Laurent Vogel
 * Covered by the GPL version 2 or later; see COPYING for details
 */

#ifndef UI_H
#define UI_H

void kill_ui(void);
void ui_loop(void);
void init_ui(void);
void ui_welcome(char *msg);
void ui_config_file(char *fname);
/* returns 0 if the file could not be opened */
int ui_try_startup_file(char *fname);

void ui_do_command(char *p);

void ui_register_command(char *cmd, int (*func)(int,char**), char *help);
void ui_register_help(char *topic, char *help);


/* commands */

void ui_cmd_help(int argc, char **argv);


#endif /* UI_H */

