#!usr/bin/env bash
# Write a shell script to determine whether two numbers input through keyboard are prime to each other.

read -p "Enter two numbers: " x y
hcf=1
for(( i=1 ; i <= x ; i++))
do
    if(( $x % $i == 0 && $y % $i == 0))
    then
        hcf=$i
    fi
done

if(( $hcf==1 ))
then
    echo "$x and $y are CO-PRIME NUMBERS" 
else
    echo "$x and $y are not CO-PRIME NUMBERS."
fi