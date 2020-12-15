#include <stdio.h> 
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    
    unsigned long long i = 0;
    unsigned long long sum = 0;

    /* takes first arg passed as start number and second arg as end number */
    for(i = strtoull(argv[1], NULL, 10); i < strtoull(argv[2], NULL, 10); i++){
        sum += i;
    }
   
    printf("%llu\n", sum);
    return 0;
}