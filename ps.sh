for i in {1..10}; do
    echo eternity$i
    ssh eternity$i ps -ef | grep blktrace 
done

wait
