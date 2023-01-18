# . Write a shell script, which reports names and sizes of all files in a directory (directory should be
# supplied as an argument to the shell script) which size exceeds 500 bytes. The filenames should
# be printed in decreasing order of their sizes. The total number of such files should also be
# reported.

if [ $# -ne 1 ]; then
    echo "Invalid input"
    exit 1
fi

dir="$1"
if [ ! -d $dir ]; then
    echo "$dir directory doesn't exist"
fi

ls -l $dir | tr -s ' ' | cut -d " " -f 5,9 | sort -nr >temp.txt
count=0
while IFS= read -r line; do
    size=$(echo $line | cut -d " " -f 1)
    if [ $size -gt 500 ] 
    then
        echo "$line"
        count=$((count + 1))
    fi
done <temp.txt

echo "No. of size with size > 500Bytes : $count"

rm temp.txt
