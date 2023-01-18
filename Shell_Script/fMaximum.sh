if (( $# == 3 ))
then 
   if (( $1 > $2 && $1 > $3 ))
   then
        echo "$1 is maximum"
    elif (( $2 > $1 && $2 > $3 ))
    then
        echo "$2 is maximum"
    else
        echo "$3 is maximum"
    fi
else
    echo "Invalid command line argument"
fi
   