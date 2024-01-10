/*
 * ocr.h - atari video buffer rendering by means of poor man's OCR 
 * techniques 
 *
 * Part of STonC (C) 1998-2002 Laurent Vogel
 * Covered by the GPL version 2 or later; see COPYING for details
 */

#ifndef OCR_H
#define OCR_H
 
void ocr_init(void);

void ocr_screen_open(void);
void ocr_screen_shifter(void);
void ocr_screen_close(void);

#endif
