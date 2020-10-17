#include <stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void example()
{   if (fork() == 0)
    {   
        printf("I am the child\n");
        printf("%d\n",(int) getpid());
    }
    else
    {
        printf("I am the parent\n");
        printf("%d\n",(int) getpid());
        exit(0);
    }
    printf("helllo");
}

int main()
{
    example();
    // return 0;
}
// fork returns the process id of the child created

 