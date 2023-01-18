# 24. Write a shell script, which displays a list of all files in the current directory to which you have read,
# write and executes permissions.

files=$(ls -l "/" | tr -s ' ' | cut -d ' ' -f 9 | sort | head -n -1)

for file in $files; do
    if [ -f "/$file" ]; then
        echo $file
        if [ -r $file -a -w $file -a -x $file ]; then
            echo $file
        fi
    fi
done
