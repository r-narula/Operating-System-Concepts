#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include <unistd.h>

// my turn your turn every 1 second
// This program never prints out concurrently
void* myturn(void *arg)
{
    int i=0;
    while(i<5)
    {
    sleep(1);
    // printf("My turn\n");
    printf("%p\n",&arg);   // & gives the address of the pointer * gives the value of the pointer.
    i++;
    }
    return NULL;
}

void yourturn()
{
    int i=0;
    while(i<2)
    {
    sleep(2);
    printf("Your turn\n");
    i++;
    }
}
void papaturn()
{
    int i = 0;
    while (1)
    {
        sleep(1);
        printf("hello World from papa\n");
    }
}
void mummaturn()
{
    int i = 0;
    while (1)
    {
        sleep(1);
        printf("hello World from mumma!!!!!!!!!!!!!!!!!!\n");
    }
}

// Now we are creating a new thread 
int main()
{   
    pthread_t newthread;  // new thread name created
    char choice;
    printf("DO you want the pthread_join to run(Y/N)");
    scanf("%c",&choice);
    // pthread_create(&newthread,NULL,myturn,"HELLO WORLD\n");
    // printf("%c",choice);
    if (choice=='Y')
    {
        pthread_create(&newthread,NULL,myturn,"HELLO WORLD\n");
        yourturn();
        pthread_join(newthread,NULL);
    }
    else
    {
        pthread_create(&newthread,NULL,myturn,"HELLO WORLD\n");
        yourturn();
    }
    
    // arguments expained for the thread ...
    // 1) thread id
    // 2) second argument is beyond my scope
    // 3) the function at whom we want to thread out.
    // 4) The argument for the function its in pointer form ..

    /*                          PROBLEM
    This statement is executed first and then the yourturn 
    But as the code is divided into different Threads hence your turn also starts executing .
    BUt the situation arises different when the yourturn program finishes first...
    As the yourturn program finishes first hence the next line is executed and that is the end of the program we are looking for
    */
    // we see that if the second function exits first then the thread does not continue and it also exits the program why?
    // main finishes ..
    // TO counter this thing we use the pthread_join function...
    return 0;
}