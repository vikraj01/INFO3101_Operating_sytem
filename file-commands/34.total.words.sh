#  Write a shell script to find the total number of words, characters, lines in the given file (supplied as 
# command line argument) and check if it is a regular file or not.

file=$1

if [ -f $file ];then
    echo "$file is Regular File"
    w=$(wc -w < $file)
    l=$(wc -l < $file)
    c=$(wc -c < $file)
    echo "$w $l $c"
else
    echo "$file is not regular file"
fi