#!/bin/sh

#
# create keys.h from keylist.txt
#

KEYLIST_TXT=keylist.txt
KEYS_H=keys.h

TMP=/tmp/mkkeys$$

rm -f $TMP

sort $KEYLIST_TXT | uniq | grep -v KEY_F\( > $TMP


sed -e 's/\(.*\)/#ifndef \1\
#define \1 0\
#endif/' $TMP > $KEYS_H

echo >> $KEYS_H
echo 'struct { int key; char *name; } keys[] = {' >> $KEYS_H

sed -e 's/\(.*\)/  {\1,"\1"},/' $TMP >> $KEYS_H

i=0
while test `echo $i` -le 63 ; do
  echo "  {KEY_F($i),\"KEY_F$i\"}," >> $KEYS_H
  i=`expr $i + 1`
done

keys=`wc -l < $TMP`
keys=`expr $keys + 65`

echo "};" >> $KEYS_H

echo >> $KEYS_H
echo "#define NR_KEYS $keys" >> $KEYS_H

rm -f $TMP




