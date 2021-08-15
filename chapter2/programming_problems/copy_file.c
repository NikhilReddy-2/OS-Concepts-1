/*
This file contains the copy program problem from the book OS-Concepts.

./copy <file1 Path> <file2 Path> [-option1] [-option2]

*/

#include<stdio.h>
#include<stdlib.h>


static void usage();

int main(int argc, char * argv[])
{
    if(argc < 3){
        usage();
    }


    return 0;
}

static void usage()
{
    fprintf(stderr,"usage: ./copy <FILE1> <FILE2> [-options]");
    exit(-1);
}



