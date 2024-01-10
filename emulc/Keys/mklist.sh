#!/bin/sh

#
# create a prototype keylist.txt from curses.h
#

CURSES_H=/usr/local/include/curses.h
KEYLIST_TXT=keylist.txt

grep '# *define  *\(KEY\|ALT\|SHF\|CTL\|PAD\)' $CURSES_H | \
  sed -e 's/# *define *//' | cut -f1 -d\ | sort | uniq | \
  grep -v KEY_F\( > $KEYLIST_TXT


