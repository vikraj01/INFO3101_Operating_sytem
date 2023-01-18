file1=$1
file2=$2

cat $file1 $file2 >temp
c=$(wc -c <temp)
w=$(wc -w <temp)
l=$(wc -l <temp)

echo "Total no. of character : $c"
echo "Total no. of words : $w"
echo "Total no. of line : $l"


