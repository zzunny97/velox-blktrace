#if [ $1 == "" ]; then
#    echo "Usage: ./script [input file name]"
#    echo "exit"
#    exit 1
#fi


while read line
do
    flag=`echo $line | awk '{print $6}'`
    if [ "$flag" == "C" ]; then
#a=`echo $line | awk '{print $4}'`
#       b=`echo $line | awk '{print $8}'`
#       echo -e "$a\t$b"
		echo "$line"
    fi
done < $1
