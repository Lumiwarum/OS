#!/bin/bash
if [ ! -e numbers.txt ]; then echo 0 > numbers.txt; fi
while true; do
if [ -e numbers.lock ]
then
	sleep 2
else
	ln numbers.txt numbers.lock #goes into the critica region
	count=0
	while [ $count -lt 100 ]; do
		count=$(expr $count + 1)
		n=$(tail -1 numbers.txt)
		echo $(expr $n + 1) >> numbers.txt
	done
	rm numbers.lock #leaves the critical region
	break
fi
done
