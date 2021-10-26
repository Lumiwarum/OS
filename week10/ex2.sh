#!/bin/sh
rm -r week01
rm -r week10
mkdir week01
mkdir week10
var_name="Anton Kirilin"
echo $var_name  >> ./week01/file.txt
link ./week01/file.txt ./week10/_ex2.txt
find . -inum $(stat -c '%i' ./week01/file.txt)
find . -inum $(stat -c '%i' ./week01/file.txt) -exec rm {} \;
