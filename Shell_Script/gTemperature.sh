n=7
sum=0
while (( $n > 0 ))
do
    read temp
    sum=$(( $sum + $temp ))
    n=$(( $n - 1 ))
done
echo "scale=2; $sum/7" | bc