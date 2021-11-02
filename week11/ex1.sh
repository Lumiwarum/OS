#!/bin/sh
dd if=/dev/zero of=lofs.img bs=1M count=50
losetup -fP lofs.img
mkfs.ext4 ./lofs.img
mkdir lofsdisk
sudo mount -o loop lofs.img lofsdisk
df -hP lofsdisk
