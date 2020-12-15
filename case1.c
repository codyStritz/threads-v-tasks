#include <stdio.h> 
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    unsigned long long i = 0;
    unsigned long long sum = 0;

    /* iterate to sum numbers from 0 to number passed as argument */
    for(i = 0; i < strtoull(argv[1], NULL, 10); i++){
        sum += i;
    }

    printf("%llu\n", sum);
    return 0;
}