#!/bin/bash
# Write a shell script, which reports names and sizes of all files in a directory (directory should be
# supplied as an argument to the shell script) which size exceeds 500 bytes. The filenames should
# be printed in decreasing order of their sizes. The total number of such files should also be
# reported.

read -p "Enter path : " -r filep
echo " file path   -   size "
for i in $(find "$filep" -depth); do
    size=$(stat -c%s "$i")
    if [ $size -gt 1000 ]; then
        echo $i " - " $size
    fi
done
