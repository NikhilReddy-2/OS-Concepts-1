#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>


int main()
{
    pid_t childPID, parentPID;

    printf("Parent PID: %d\n",getpid());
    
    childPID = fork();
    if(childPID < 0)
    {
        fprintf(stderr,"Could not fork the parent process : %d",getpid());
    }else if(childPID == 0)
    {
        printf("\t|\t\\\n\t|\tChild PID: %d\n\t|\t/\n",getpid());  // Bad formatting but good output :)
    }else
    {
        wait(NULL);
        printf("Parent PID: %d\n",getpid());
        printf("Child complete");
    }

    return 0;
}
