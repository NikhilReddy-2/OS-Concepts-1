#include<stdio.h>
#include<stdlib.h>

#define MIN_PID 300
#define MAX_PID 5000

int allocate_map(void);     //Creates and inits a data structure for representing PIDs, returns 1-failure 0- success
int allocate_pid(void);     //Allocates and returns a PID, returns 1-failure 0-success
void release_pid(int pid);  //Releases a PID