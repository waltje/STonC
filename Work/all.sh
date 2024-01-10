#!/bin/sh

# perform a transformation on most source code files

tmp=/tmp/all$$
rm -f $tmp

# for i in `find . -perm 644 | sed -e 's/^\.\///;/~$/d;/^all.sh/d;/^obj\//d'`

for i in */*.[ch] */*.m4
do
  cp $i $tmp
  
  # the transformation is here: 
  # do not alter $i, and write the result in $tmp
  
  sed -e 's/doc\/license.txt/COPYING/g' $i > $tmp
  
  # only replace $i if different from $tmp
  
  if ! cmp -s $i $tmp
  then
    rm -f $i~
    mv $i $i~
    mv $tmp $i
    echo $i
  fi
  rm -f $tmp
done


