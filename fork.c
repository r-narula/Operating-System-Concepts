#include <stdio.h> 
#include<stdlib.h>
#include <sys/types.h> 
#include<sys/wait.h>
#include <unistd.h> 
int main() 
{ 
  
    printf("Current running process %d \n",(int)getpid());
    pid_t pid = fork();
    printf("fork return %d\n",(int)pid);

    if (pid ==0)
    {
        printf("i am the child with pid %d\n",(int) getpid());
        sleep(3);
        printf("child exiting now\n");
        exit(42); // exit the program after finishing the if statement
    }
    // we must be parent to execute this thing
    printf("I am the parent\n");
    // pid_t childid = wait(NULL); 
    // wait returns the pid of the termianted child
    // this wait command blocks the calling process until the child as done finishing the workk
    // then its begans execution
    int status = 0;
    pid_t childpid = wait(&status); // wait masks of the integer value of the status with the status info the child process that has just terminated.
     // In wait we store the status info of the returned value from the child process that has terminated

    printf("the parent was waiting for %d pid to end with status %d\n",(int)childpid,status);
    // to access the exit information with it we have to use the WEXITSTATUS() it takes the integer that has the status info of the wait system call implementation.
    int value = WEXITSTATUS(status); // it takes an int value
    printf("it must return the exit status of child %d\n",value);
    printf("Parent ending\n");
} 