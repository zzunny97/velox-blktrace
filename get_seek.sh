for i in {3..10}; do
    ./seekwatcher_seek -t eternity$i/sdb.blktrace* >& eternity$i/seekwatcher_seek &
done

wait
