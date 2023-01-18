#. Write a shell command that accept a filename as argument and displays the last modification 
# time, if the file exists and a suitable message if it does not.

file=$1
time=`ls -l $file | tr -s ' ' | cut -d ' ' -f 6,7,8`
echo "Last modification time: $time"