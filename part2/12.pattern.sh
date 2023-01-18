#!bin/usr/env bash
i=0
read n   
x=$(( $n * 2 + 1 ))
while (( $i < $x))
do    
    k=$i    
    while(( $k < $x ))
    do     
        echo -n " "
        k=$(( $k + 1 ))
    done   
        j=1
        while(( $j < $i ))
        do    
            echo -n "*"
            echo -n " "
            j=`expr $j + 1`
        done  
    echo
        i=$(( $i + 2 ))
    done