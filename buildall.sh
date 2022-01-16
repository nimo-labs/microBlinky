#!/bin/bash
for d in */
do
	echo "Processing $d..."
	cd $d
	cd ../../
	pwd
	ls -l
	../../umake.py clean
	../../umake.py
	make
	if [ $? -eq 0 ]; then
		echo -------------------
    	echo Build of $d passed
		echo -------------------
		cd ..
	else
    	echo build of $d failed
		exit 1
	fi
done
echo -------------------
echo All builds completed successfully
echo -------------------