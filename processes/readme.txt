Purpose: To understand how to spawn, morph and fork processes

Developer: 
Foyin Ogbara

Software organisation:
isPrime.c – the base program for checking whether a number is a prime number
prime.bin – a file that contains 12 unsigned numbers in binary format
prime.txt – a file that contains 12 unsigned numbers in ASCII format. The numbers correspond to the numbers in the file
prime.bin
createBinary.c – a program that creates a binary file from a given set of numbers. Assuming that the executable is a.out the
usage is: a.out filename num1 num2 etc. where filename is the binary file name, num1 is the first unsigned number num2 is the second unsigned number etc.
singlePrime.c - This file takes a binary file as input and morphs itself into the isPrime.c. The file takes one command line parameter in as input (prime.bin)
singleSpawn.c - This file spawns a child process, morphs it into the isPrime program and uses isPrime.c to tell if the input was a prime number. The file takes one command line parameter in as input (prime.bin)
multiSpawn - This file spawns multiple child processes and morphs each into the isPrime program. The file takes one command line parameter in as input (prime.bin)


Compilation:
Task 1:-
To compile -> make -f Makefile1
To run -> ./singleMorph prime.bin

Task 2:-
To compile -> make -f Makefile2
To run -> ./singleSpawn prime.bin

Task 3:-
To compile -> make -f Makefile3
To run -> ./multiSpawn prime.bin

Usage:
Im using a linux 64-bit system so if i compile isPrime.c on my system the executable wont run on a 32-bit system (which the school VMs use)
so create the isPrime executable on your system with
gcc -o isPrime isPrime.c
