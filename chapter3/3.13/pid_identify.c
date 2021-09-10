#include<stdio.h>
#include<stdlib.h>

#define MIN_PID 300
#define MAX_PID 5000

void usage(){
    fprintf(stderr,"USAGE : ./pid {PID}");
}

//Creates and inits a data structure for representing PIDs, returns 1-failure 0- success
int allocate_map(int * pid_map){
    for (int i=0;i<(MAX_PID-MIN_PID);i++){
        pid_map[i] = 0;
    }
    return 0;
}

//Allocates and returns a PID, returns 1-failure 0-success
int allocate_pid(int * pid_map ,int pid){
    if(pid_map[pid] == 0){
        pid_map[pid] = 1;
        return 0;
    }else{
        return 1;
    }
}
void release_pid(int pid);  //Releases a PID



int main(int argc, char * argv[]){

    if(argc < 2){
        usage();
        exit(0);
    }

    int pid = atoi(argv[1]);

    int pid_map[MAX_PID-MIN_PID];

    if((allocate_map(pid_map)) == 0){
        printf("Map populated with 0s\n");
    }

    if((allocate_pid(pid_map,pid)) == 0){
        printf("PID Allocated\n");
    }else{
        printf("Could not allocate PID\n");
    }

    
    return 0;
}
