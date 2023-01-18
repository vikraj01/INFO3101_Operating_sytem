# Develop a shell script which displays all files with all attributes those have created or modified in
# the month of November

ls -l | tr -s ' ' | cut -d ' ' -f 1,6-9 >temp
count=0
while read line; do
    month=$(echo $line | cut -d ' ' -f 2)
    if [ $month = "Nov" ]; then
        echo $(echo $line | cut -d ' ' -f 5)
        count=$(expr $count + 1)
    fi

done <temp
echo "Total number of files in november : $count"
rm temp
