#!/bin/bash
VFSNAME="lofsdisk"
sudo echo "Anton" > $VFSNAME/file1
sudo echo "Kirilin" > $VFSNAME/file2
sh ex1.sh
gcc ex2.c -o ex2.out
sudo cp ex2.out $VFSNAME

#copying needed files
if [ ! -d $VFSNAME/bin ]
then
	sudo mkdir $VFSNAME/bin
fi
sudo cp /bin/bash $VFSNAME/bin
sudo cp /bin/ls $VFSNAME/bin
sudo cp /bin/cat $VFSNAME/bin
sudo cp /bin/echo $VFSNAME/bin
if [ ! -d $VFSNAME/lib ]
then
	sudo mkdir $VFSNAME/lib
	sudo mkdir $VFSNAME/lib/x86_64-linux-gnu
fi
if [ ! -d $VFSNAME/lib64 ]
then
	sudo mkdir $VFSNAME/lib64
fi
#libraries for bash
sudo cp /lib/x86_64-linux-gnu/libtinfo.so.6 $VFSNAME/lib/x86_64-linux-gnu
sudo cp /lib/x86_64-linux-gnu/libdl.so.2 $VFSNAME/lib/x86_64-linux-gnu
sudo cp /lib/x86_64-linux-gnu/libc.so.6 $VFSNAME/lib/x86_64-linux-gnu
sudo cp /lib64/ld-linux-x86-64.so.2 $VFSNAME/lib64
#libraries for ls
sudo cp /lib/x86_64-linux-gnu/libselinux.so.1 $VFSNAME/lib/x86_64-linux-gnu
sudo cp /lib/x86_64-linux-gnu/libpcre2-8.so.0 $VFSNAME/lib/x86_64-linux-gnu
sudo cp /lib/x86_64-linux-gnu/libpthread.so.0 $VFSNAME/lib/x86_64-linux-gnu

echo "With chroot" > ex2.txt
sudo chroot ./lofsdisk ./ex2.out >> ex2.txt
echo "Without chroot" >> ex2.txt
./ex2.out >> ex2.txt
