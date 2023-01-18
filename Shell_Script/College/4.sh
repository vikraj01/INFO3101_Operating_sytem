#!/usr/bin/env bash
# Write a shell script to check whether a given number is prime or not.
echo -n "Enter Number : "
read n
for((i=2; i<=$n/2; i++))
do
  ans=$(( n%i ))
  if [ $ans -eq 0 ]
  then
    echo "$n is not a prime number."
    exit 0
  fi
done
echo "$n is a prime number."

