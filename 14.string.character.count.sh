# Accept a string from the terminal and echo a suitable message if it doesn’t have at least ten 
# characters.
if [ $# -eq 1 ]
then
    x=`echo -n $1 | wc -c`
    if [ $x -le 9 ]
        then
            echo "Input has less than 10 characters"
        fi

else
    echo "INVALID ARGUMENTS"
fi