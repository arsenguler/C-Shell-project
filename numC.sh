if [ $# -ne 1 ]
then
	echo "Wrong use. use: numc [command-name]"
fi
count=0
for input in `history`
do
	if [ $1 = $input ] 2>/dev/null
	then
		count=$(($count+1));
	fi
done
echo You used $1 $count times recently.
