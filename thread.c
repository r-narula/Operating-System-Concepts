#include<stdio.h>
#include<stdlib.h>

// thread function to generate sum of 0 to N
void* sum_runner(void* arg)
{
    long long* limit_ptr = (long long*)arg; // type casting void* to a long long *
    long long limit = *limit_ptr;

    long long sum = 0;
    for (long long i=0;i<=limit;i++)
    {
        sum +=i;
    }
    // ToDO: what to do with the answer 
}
int main(int argc,char ** argv)
{
    if (argc<2)
    {
        printf("Usage :%s <num>\n",argv[0]);
        exit(-1);
    }
    long long limit = atoll(argv[1]); // atoll converts the interger to a long long int 

    // thread ID
    pthread_t tid;

    // Attributes
    pthread_attr_t attr;
    

     
}