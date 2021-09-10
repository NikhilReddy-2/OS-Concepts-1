#include<stdio.h>
#include<stdlib.h>

#define MIN_PID 300
#define MAX_PID 5000

//Creates and inits a data structure for representing PIDs, returns 1-failure 0- success
int allocate_map(int * pid_map){
    for (int i=0;i<(MAX_PID-MIN_PID);i++){
        pid_map[i] = 0;
    }
    return 0;
}
int allocate_pid(void);     //Allocates and returns a PID, returns 1-failure 0-success
void release_pid(int pid);  //Releases a PID



int main(){
    int pid_map[MAX_PID-MIN_PID];

    if((allocate_map(pid_map)) == 0){
        printf("Map populated with 0s\n");
    }

    return 0;
}
