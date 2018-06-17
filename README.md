# fsyncfreeze

gcc -shared -fPIC freeze.c -o freeze.so -Wimplicit-function-declaration  -ldl
gcc test.c -o test
LD_PRELOAD=./freeze.so  ./test
