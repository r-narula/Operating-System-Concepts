#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h>   
#include <pthread.h> 
 
int g;
 
// A normal C function that is executed as a thread  
// when its name is specified in pthread_create() 
void *myThread(void *vargp) 
{ 
int i;
   // sleep(1); 
    for(i=0;i<10;i++)
	{if( i%2==0)
		printf("%d is even\n",i);}
// printf("%s\n", (char *)vargp);
    return NULL; 
} 


int main() 
{ 
    int i;
    pthread_t thread_id[4] ; //declared the thread identifier
    printf("Before Thread\n"); 
  
for(i=0;i<4;i++)
{
   pthread_create(&thread_id[i], NULL, myThread,NULL); //create the threads
   pthread_join(thread_id[i], NULL); 
   
}
exit(0); 
} 
