#! /bin/bash

DIR="/media/cdrom"
if [ ! -e $DIR ]
then
	mkdir -p cdrom 
else
	echo "have DIR"
fi
