#!bin/usr/env bash
str="HLELJELJLEJLEJLJL"
x=`echo -n $str | wc -c`
echo $x
if [ $# -eq 1 ]
then
    x=`echo -n $str | wc -c`
    if [ $x -le 9 ]
    then 
        echo "Input has less than 10 characters"
    fi
fi 