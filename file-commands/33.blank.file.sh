# Write a shell script to check the entered file is a blank file or not. If not found blank then display 
# the contents of the fileThe awk command takes two types of input: input text files and program instructions. Searching and actions are performed on input text files. The files are specified by: Specifying the File variable on the command line.


file=$1

if [ -s $file ];then
    echo "$file is not blank"
    cat $file
else
    echo "$file is blank"
fi
