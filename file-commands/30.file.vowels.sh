#  Write a shell script to list the name of files under the current directory started with vowels
dir="/c/Users/vikas/downloads/"

files=$(ls -l $dir | tr -s ' ' | cut -d ' ' -f 9)
ls -l $dir | tr -s ' ' | cut -d ' ' -f 9 | sort > temp

while read file; do
    if [ -f "$dir$file" ]; then
        if [[ $file =~ ^[aeiouAEIOU] ]]; then
            echo $file
        fi
    fi
done <temp
