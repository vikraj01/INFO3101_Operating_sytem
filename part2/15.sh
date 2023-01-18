read word
read filename
if [ -e $filename ]
then
    cat $filename | grep -v $word
else
   echo 'text here'
fi