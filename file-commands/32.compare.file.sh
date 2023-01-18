# 32. Write a shell script which reads a directory name and compares the files in the current directory
# which has more files and how much more files

dir1=/d/test/$1/
dir2=/d/test/$2/
ls -l $dir1 | tr -s ' ' | cut -d ' ' -f 9 | sort >temp1
ls -l $dir2 | tr -s ' ' | cut -d ' ' -f 9 | sort >temp2

cat temp1 temp2
count1=0
count2=0

while read file; do
    
    if [ -f $dir1$file ]; then
        count1=$(($count1 + 1))
    fi
done <temp1

while read file; do
    if [ -f $dir2$file ]; then
        count2=$(($count2 + 1))
    fi
done <temp2

echo "$count1 $count2"
