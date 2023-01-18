#  Write a shell script that shows the names of all the non-directory files in the current directory and
# calculates the sum of the size of them
dir="/c/Users/vikas/downloads/"
ls -l $dir | tr -s ' ' | cut -d ' ' -f 5,9 >temp

size=0
while read line; do
    filename=$(echo $line | cut -d ' ' -f 2)
    if [ -f "$dir$filename" ]; then
        s=$(echo $line | cut -d ' ' -f 1)
        size=$(($size + $s))
        echo $filename
    fi
done <temp

echo "Total File Size in the Directory $dir : $size"

rm temp*
