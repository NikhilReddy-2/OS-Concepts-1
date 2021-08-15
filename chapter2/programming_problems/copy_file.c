/*
This file contains the copy program problem from the book OS-Concepts.

./copy <file1 Path> <file2 Path> [-option1] [-option2]
*/

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>


/*
Struct to store the file descriptors of both the
files together.(For convenience)
*/
typedef struct both_files{
    int file1;
    int file2;
} Files;


static void usage();
static void error();

/*
brief: This function opens file with the appropriate permissions.
        -> File 1 Permissions = Read only
        -> File 2 Permissions = Truncate and Write only
    The function takes the struct 'Files' and the path to the files as arguments
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
brief: This function copies the characters from one file to another one
       one character at a time.
    This function does not store the string copied from the first file in a buffer as of now.
*/
void copyFile(Files * copy_files){

    char c;
    while((read(copy_files->file1, &c,1)) != 0){
        if((write(copy_files->file2, &c,1)) == -1){
            error("Error copying the file to destination path");
        }
    }
}

/*
brief: Should have 3 arguments passed to it.
    
    Will be adding support for additional options soon.
*/
int main(int argc, char * argv[])
{
    if(argc < 3){
        usage();
    }
        
    int ret;
    
    Files copy_files;
        
    openFile(&copy_files,argv[1],argv[2]);
    copyFile(&copy_files);
    
    close(copy_files.file1);
    close(copy_files.file2);

    return 0;
}

/*
brief: Displays proper usage of the command.
*/
static void usage()
{
    fprintf(stderr,"usage: ./copy <FILE1> <FILE2> [-options]");
    exit(-1);
}

/*
brief: Displays errors in the code.
*/
static void error(char error_msg[]){
    fprintf(stderr,"ERROR: %s with code: %d", error_msg, errno);
    exit(-1);
}


