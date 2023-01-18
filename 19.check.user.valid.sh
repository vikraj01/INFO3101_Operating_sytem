# while IFS= read -r line; do
#     echo "$line"
# done < /path/ro/file

read uname
who | grep $uname > /dev/null 
if [ $? -eq 0 ]
    then
        echo "Valid User"
    else 
        echo "Invalid User"
fi
