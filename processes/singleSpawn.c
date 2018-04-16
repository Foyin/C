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
   int i;
   int pid;
   int cpid;
   int sum = 0;
   int status; 

   unsigned int toRead;
   unsigned char readString[100];
   FILE *bin;
   bin = fopen(argv[1],"rb");

   if(argc < 2){
	printf("Program expects one file as input \n");
	printf("  --  ./singlePrime [filename]\n");
	return 2;
   }

   if(!(argc == 2)){
	printf("Program expects one file as input \n");
	printf("  --  ./singlePrime [filename]\n");
	exit(1);
   }

   if (fexists(argv[1])) {
   printf("Ready to fork...\n");
   cpid = fork();
   if (cpid == 0) {
      printf("Child exectuion thread\n");
      fread(&toRead,sizeof(int),1,bin);
      sprintf(readString, "%d", toRead);
      morph(readString);
      
      
      sum = -5;
      printf("Child sum=%d\n",sum);
      sleep(2);

      // return sum to parent
      exit(sum);
   }  else {
      // parent code 
      pid=wait(&status);
      printf("Parent exectuion thread\n");

      // showing the returned pid from  wait() is the same as the pid 
      // from fork() 
      printf("Parent: return pid =%d cpid = %d\n",pid, cpid);

      // checking if the program was signalled to terminate 
      printf("Child exited with WIFSIGNALED(%d)\n",WIFSIGNALED(status));

      // checking if the program existed normally (using return() from main 
      // or exit()
      printf("Child exited with WIFEXITED(%d) \n",WIFEXITED(status));

      // showing the return code from a child (e.g., return(-5) or exit(-5)) 
      // when the value can be positive or negative (i.e., signed value) 
      printf("Child exited with WEXITSTATUS(%d)\n",(char)WEXITSTATUS(status));
      
      // showing the return code from a child (e.g., return(-5) or exit(-5)) 
      // when the value is interpreted as unsigned value 
      printf("Child exited with WEXITSTATUS(%d)\n",WEXITSTATUS(status));
   }
}
   else return 3;

if ( WEXITSTATUS(status) == 1) {
	printf("The number is prime\n");	
      }
      else if (WEXITSTATUS(status) == 0){
	printf("The number is not prime\n");	
      }
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

