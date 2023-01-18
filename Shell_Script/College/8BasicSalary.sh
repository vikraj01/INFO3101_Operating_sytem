#!usr/bin/env bash
# Ramesh’s basic salary (BASIC) is input through keyboard. His dearness allowance (DA) is 52% of
# BASIC. House rent allowance (HRA) is 15% BASIC. Contributory provident fund is 12% of (BASIC
# + DA). Write a shell script to calculate his gross salary and take home salary using the following
# formula:
# Gross salary = BASIC + DA + HRA + (BASIC + DA) * 0.12
# Take home salary = BASIC + DA + HRA - (BASIC + DA) * 0.12

read -p "Enter the basic salary : " sal
da=a=$(echo "scale=2.0; 0.52*$sal" | bc )
hra=a=$(echo "scale=2.0; 0.15*$sal" | bc )

gs=$(echo "scale=2.0; ($da + $hra + (($da+$hra)*0.12))" | bc )
echo $gs
