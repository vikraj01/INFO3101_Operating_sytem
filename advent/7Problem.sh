total=0
temp=0
MAX=100000
while IFS= read -r line; do
    second=$(echo $line | cut -d ' ' -f 2)
    num=$(echo $line | tr -dc '0-9')
    total=$((total+num ))
    
    if [ $second = "ls" ];then
        temp=0
    fi
done < file.txt
echo $total
