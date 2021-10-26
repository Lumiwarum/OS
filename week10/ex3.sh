#!/bin/sh
echo 'Anton kirilin' > _ex3.txt
echo 'Initial permissions of the file' > ex3.txt
ls -l _ex3.txt >> ex3.txt

echo '\nRemoving execute permission for everyone' >> ex3.txt
chmod -x+X _ex3.txt
ls -l _ex3.txt >> ex3.txt

echo '\nGranting all permissions for owner and others' >> ex3.txt
chmod u=rwx,o=rwx _ex3.txt
ls -l _ex3.txt >> ex3.txt

echo '\n Group permissions now are equal to user permissions' >> ex3.txt
chmod g=u _ex3.txt
ls -l _ex3.txt >> ex3.txt

echo '\n ANSWER:' >> ex3.txt
echo 'chmod 660 ex3.txt Sets permissions for ex3.txt such that user and groups can read&write, others cannot do anything' >> ex3.txt
echo 'chmod 770 ex3.txt Grant all permissions of ex3.txt to everyone, except write for others' >> ex3.txt
echo 'chmod 777 ex3.txt Grant all permissions of ex3.txt to everyone' >> ex3.txt
