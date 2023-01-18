#!/bin/bash
echo "Enter two number"
read num1
read num2

if (( $num2==0 ))
then 
   echo 'division by 0 not allowed'
else 
   echo "scale=2; $num1/$num2" | bc
#    echo "division is $div"
fi

   
   
