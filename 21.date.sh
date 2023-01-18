h=$(date +"%H")

if [ $hr -gt 0 ] && [ $hr -lt 12 ];then
    echo "Good Morning"
elif [ $hr -gt 12 ] && [ $hr -lt 18 ]
then
    echo "Good Afternoon"
else
    echo "Good Evening"
fi
