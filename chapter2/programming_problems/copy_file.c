#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

static void usage();

int main(int argc, char * argv[])
{
    if( argc < 2){
        usage();
    }
    
}

/*
brief: Error message to display correct usage
*/
static void usage(){
    fprintf(stderr,"usage: ./copy <file1> <file2> \n");
    exit(-1);
}