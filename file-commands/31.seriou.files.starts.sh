#Write a shell script that accepts two directory names bar1 and bar2 as arguments and deletes
# those files in bar2 which are identical to their names in bar1

root="/d/test/"
dir1="$1/"
dir2="$2/"

ls -l $root$dir1 | tr -s ' ' | cut -d ' ' -f 9 | sort >temp

while read file; do
    echo $root$dir2$file
    if [ -f $root$dir2$file ]; then
        echo "Deleting $root$dir2$file"
        rm ../../../../../../..$root$dir2$file
    fi
done <temp

rm temp*
