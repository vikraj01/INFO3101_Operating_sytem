#27. Write a shell script to display the files created or updated fourteen days before from the current 
# date

find . -type f -mtime -14 -ls | tr -s ' ' | cut -d ' ' -f 11 | sort -nr > temp
cat temp
echo "Total number of files : $(wc -l < temp)"
rm temp