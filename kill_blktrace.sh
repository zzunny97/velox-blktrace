for i in {3..10}; do
    ssh eternity$i sudo pkill blktrace &
done

wait
