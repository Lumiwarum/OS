#!/bin/bash
if [ -e file.txt ]; then
.
else
echo 0 >> file.txt
fi
for i in 0 1 2 3 4 5 6 7 8 9 10
do
number=$(tail -n 1 file.txt)
echo $((number+1)) >> file.txt
done
