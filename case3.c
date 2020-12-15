#include <stdio.h> 
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    /* first passed argument will be n; second passed argument will be number of tasks */
    unsigned long long n = strtoull(argv[1], NULL, 10);
    int num_tasks = atoi(argv[2]);

    unsigned long long slices[num_tasks];
    unsigned long long ans = 0;
    unsigned long long sum = 0;
    char command[num_tasks][200];
    int i = 0;
    FILE* fp[num_tasks];

    /* create "slices" of n for each task to sum */
    for(i = 0; i < num_tasks; i++){
        slices[i] = (n/num_tasks)*(i+1);
    }

    /* run mtask.c and pass arguments for beginning and end of its slice */
    for(i = 0; i < num_tasks; i++){
        sprintf(command[i], "./mtask %llu %llu", slices[i]-(slices[i]/(i+1)), slices[i]);
        fp[i] = popen(command[i], "r");
    }
    
    /* Retrieve results from each task and add them to the total sum */
    for(i=0; i < num_tasks; i++){
        fscanf(fp[i], "%llu", &ans);
        printf("ans: %llu\n", ans);
        sum += ans;
        pclose(fp[i]);
    }
    
    printf("Total Sum: %llu\n", sum);
    
    return 0;
}