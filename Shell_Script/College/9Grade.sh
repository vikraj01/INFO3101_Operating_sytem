#!usr/bin/env bash
# if else / switch case
# Write a shell script to calculate the grade of students from average marks, where the marks will be
# taken from another file. Determine the grade as per the following rule:


# or file=`cat marks.txt`
file=$(<marks.txt)
i=0
sum=0

# awk '{ sum += $1 } END { print sum }' $file


while read line
do
    # sum=$(( $sum + $line ))
    # i=$(( $i+1 ))
    num=$(($line))
    echo $num
    
done < marks.txt


# avg=$(( $sum / $i ))
echo $avg





