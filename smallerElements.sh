smallerElements() {

    arrayLength=${#array[@]}
    counter=0
    for (( c=0; c<=$arrayLength; c++ ))
    do

        for (( a=0; a<=$arrayLength; a++ ))
        do
        if ((${array[a]} > ${array[$((a+1))]})) 2>/dev/null
        then
            #Swap Algorithm
            swap=${array[$a]}
            array[$a]=${array[$((a+1))]}
            array[$((a+1))]=$swap
        Fi

        done

    done
    printing

}

printing() {
    echo ${array[*]}", "
    echo "The size of your array is $i"
    return 0
}
#Main
echo "Please enter numbers:"
echo "Enter 0 to exit."
declare -a array
read scannedNumber
i=0
k=0
while [ $scannedNumber -ne $k ]
do
    array[i]="$scannedNumber"
    read scannedNumber
    i=$((i+1))
done
smallerElements
