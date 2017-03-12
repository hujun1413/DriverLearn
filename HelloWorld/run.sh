#!/bin/bash
#Usage: ./run.sh Hujun 3
# dmesg to see the output message

if [ $# != 2 ]; then
	echo "Usage: $0 whom(charp) howmany(int)" 
	exit;
fi

whom=$1
howmany=$2

echo -e "===== Make clean ====="
make clean
echo -e "===== Start make ====="
make

echo -e "===== Insmod Hello.ko "
sudo insmod Hello.ko whom=$whom howmany=$howmany

sleep 1

echo -e "===== Rmmod Hello.ko ====="
sudo rmmod Hello
