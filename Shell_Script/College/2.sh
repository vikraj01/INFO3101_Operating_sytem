#!/usr/bin/env bash
# Write a program that displays the result of division of one integer by another and informs if the
# user tries to divide an integer by zero.

read -p "Enter two numbers : " num1 num2 

if [ $num2 -eq 0 ]
then
    echo "error: divide by 0"
else
    echo "scale=2; $num1/$num2" | bc
fi