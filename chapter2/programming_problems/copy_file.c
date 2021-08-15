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
#include<unistd.h>


typedef struct both_files{
    int file1;
    int file2;
} Files;


static void usage();
static void error();

/*
*/
void openFile(Files * copy_files,char * file_one_path, char * file_two_path){

    if((copy_files->file1 = open( file_one_path, S_IRUSR)) == -1){
        error("Error while opening File 1");
    }
    if((copy_files->file2 = open( file_two_path, O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1){
        error("Error while creating File 2");
    }
}


/*

*/
void copyFile(Files * copy_files){

    char c;
    char d;
    while((read(copy_files->file1, &c,1)) != 0){
        d = c;
        if((write(copy_files->file2, &d,1)) == -1){
            error("FUCK");
        }
        //printf("%s",&c);
    }
}


int main(int argc, char * argv[])
{
    if(argc < 3){
        usage();
    }
        
    int ret;
    
    Files copy_files;
        
    openFile(&copy_files,argv[1],argv[2]);
    //printf("%d <-------File Desciptor\n",copy_files.file2);
    
    copyFile(&copy_files);
    
    close(copy_files.file1);
    close(copy_files.file2);

    return 0;
}

static void usage()
{
    fprintf(stderr,"usage: ./copy <FILE1> <FILE2> [-options]");
    exit(-1);
}

static void error(char error_msg[]){
    fprintf(stderr,"ERROR: %s with code: %d", error_msg, errno);
    exit(-1);
}


