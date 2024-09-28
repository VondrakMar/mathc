if [ -f mathc.out  ]; then
    rm mathc.out 
fi
gcc main.c linalg.c -o mathc.out
./mathc.out 
