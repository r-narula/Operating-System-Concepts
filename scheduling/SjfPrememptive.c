#include<stdio.h>
#include<stdlib.h>

int secondMin(int s[],int size)
{   
    int first = 999;
    int second = 999;
    for(int i=0;i<size;i++)
    {
        if(s[i]<first)
        {
            first = s[i];
        }
    }
    for(int i=0;i<size;i++)
    {
        if (s[i]>first && s[i]<second)
        {
            second = s[i];
        }
    }
    return second;
}

int main()
{
    int n = 4;// number of processes

    int burst[4] = {5,3,4,1}; // Burst time of the processes.
    int wait[4];
    int arrival[4] = {0,1,2,4};// the arrival time of the 4 processes 
    int quantum = 1; // 1 time quantum is the shortest time required..
    int insertion = 0;
    // at each arrrival time of the process we have 
    // to make a check point to find the smallest between the processes.

    //
    // At time 0 we comapre with the arrival time and see the things.
    //
   int minimum = burst[0];
   for (int i=0;i<4;i++) // for time ....
   {
       // compare with arr[j]
       printf("                For time:%d          \n",i);
       for (int j = 0; j < 4; j++)
       {
        if (arrival[j]==i)
            {
            // here we have new process incoming ... find the shortest burst time process.
                // insert the element in wait as it comes.
                wait[insertion]=burst[i];
                insertion++;
                if (wait[insertion]<minimum)
                {
                    //update the minimum
                    minimum = wait[insertion];
                }
                    printf("The minimum is:%d\n",minimum);
            }

        // this thing gets executed every time..

        for(int y=0;y<sizeof(wait)/sizeof(wait[0]);y++)
        {
            printf("%d    ",wait[i]);
        }
        printf("\n");

            {
                // reduce the minimum by 1.
                // if it becomes zero then again update the minimum from the wait array and this time the one with zero is not considered. I mean remove it .. or find the second smallest one..
                int time =0;
                for(int q=0;q<sizeof(wait)/sizeof(wait[0]);q++)
                {
                    if (minimum==wait[time])
                    {
                        // reduce the min and wait insertion by 1
                        minimum--;
                        wait[time]--;
                        break;
                    }
                    time++;
                }
                for(int k=0;k<(sizeof(wait)/sizeof(wait[0]));k++)
                {
                    // find the second minimum if minimum = 0;
                    int second = secondMin(wait,sizeof(wait)/sizeof(wait[0]));
                    if (minimum == 0)
                    {
                        minimum = second;
                    }
                }
            }
        
       }
       
   }
   printf("This code is currently not working and thus will do it later...");
}
