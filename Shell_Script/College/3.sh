#!/usr/bin/env bash
# Write a shell program that takes a number from user and prints the reverse of the number.

read -p "Enter any number: " num
rev=0
while (( $num > 0 ))
do
    x=$(( $num % 10 ))
    rev=$(( $rev * 10 + $x ))
    num=$(( $num / 10 ))
done
echo "Reverse is $rev"