for i in {40..59}; do
    rm -f dumbo0$i/parse
done

echo "blkparse start"
for i in {40..59}; do
    blkparse dumbo0$i/*blktrace* >& dumbo0$i/total_parse 
done

#wait

echo "grep eclipse_node start"

for i in {40..59}; do
	grep -rn "eclipse_node" dumbo0$i/total_parse >& dumbo0$i/eclipse_parse 
done

#wait

echo "c++ script start"

for i in {40..59}; do
	c++script/parse_blkparse dumbo0$i/eclipse_parse >& dumbo0$i/final_output 
done

#wait

