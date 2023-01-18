#!/usr/bin/env bash
# First line of the script is the shebang which tells the system how to execute
# Write a shell script to calculate the sum of digits of any number entered through keyboard.

# Method 1
# echo -n "Enter any number "
# read num

# Method 2 (read variable)
read -p "Enter any number " num

sum=0
while [ $num -gt 0 ]; do
    mod=$((num % 10))
    sum=$((sum + mod))
    num=$((num / 10))
done
echo $sum
