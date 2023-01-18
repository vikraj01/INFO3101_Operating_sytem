echo "Enter a number"
read n
rev=0
while (( $n > 0 ))
do
    sd=$(( $n % 10 ))
    rev=$(( $rev * 10 + $sd ))
    n=$(( $n / 10 ))
done
echo "Reverse number of entered digit is $rev"