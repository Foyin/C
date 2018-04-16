// INCLUDE FILES
//
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include <unistd.h>

int fexists(const char * filename);
int morph(char *number);

int main(int argc, char **argv)

{
    unsigned int toRead;
    unsigned char readString[100];
    FILE *bin;
    bin = fopen(argv[1],"rb");  // r for read, b for binary

    if(argc < 2){
	printf("Program expects one file as input \n");
	printf("  --  ./singlePrime [filename]\n");
	return 2;
    }

    if(!(argc == 2)){
	printf("Program expects one file as input \n");
	printf("  --  ./singlePrime [filename]\n");
    }
    
    if (fexists (argv[1]))
    {
      printf ("File exists\n");
      fread(&toRead,sizeof(int),1,bin);
      sprintf(readString, "%d", toRead);
      morph(readString);
      
    }
    else 
      printf ("File dosen't exist\n");
      return 3;
}

int fexists(const char * filename){
    /* try to open file to read */
    FILE *file;
    if (file = fopen(filename, "r")){
        fclose(file);
        return 1;
    }
    return 0;
    
    
}


int morph(char *number){
char *primeArgv[] = {
    "./isPrime",  // First argument is the name of the program
    number,         // The actual first argument
    NULL,           // Array must be `NULL` terminated
};

execvp("./isPrime", primeArgv);

}

