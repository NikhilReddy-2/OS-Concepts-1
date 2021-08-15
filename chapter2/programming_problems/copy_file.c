/*
This file contains the copy program problem from the book OS-Concepts.

./copy <file1 Path> <file2 Path> [-c] [-option2]

*/

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

static void usage();
static int openFile();
static void error();

int main(int argc, char * argv[])
{
    if(argc < 3){
        usage();
    }
        
    int ret;
    
    openFile(argv[1],argv[2]);
    

    return 0;
}

static void openFile(char * file_one_path, char * file_two_path){
    int fd1,fd2;

    if((fd1 = open( file_one_path, S_IRUSR)) == -1){
        error("Error while opening File 1");
    }
    if((fd2 = open( file_two_path, O_CREAT, S_IWUSR)) == -1){
        error("Error while creating File 2");
    }
    return 1;
}

static void usage()
{
    fprintf(stderr,"usage: ./copy <FILE1> <FILE2> [-options]");
    exit(-1);
}

static void error(char error_msg[]){
    fprintf(stderr,"%s", error_msg);
    exit(-1);
}


