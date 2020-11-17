#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int processSize[4]={212, 417, 112, 426};
    int blocksize[5]={100, 500, 200, 300, 600};

    for (int i = 0; i < sizeof(processSize)/sizeof(processSize[0]); i++) // for the process
    {
        int flag = 0;
        int max  = 0;
        int great = 0;

        for (int j = 0; j < sizeof(blocksize)/sizeof(blocksize[0]); j++) // for the block
        {
            if (processSize[i]<blocksize[j])
            {
                // update the maximum of the available
                int a = blocksize[j] - processSize[i]; 
                if (a>max) // we want to get the max
                {
                    max = a;
                    great = blocksize[j];
                }
            }
        }
        // now we have the first greatest blockSize from the processSize
        // update the blocksize 
        for (int j = 0; j < sizeof(blocksize)/sizeof(blocksize[0]); j++)
        {
            if (great == blocksize[j])
            {
                blocksize[j] -= processSize[i];
                cout<<"Process"<<processSize[i]<<" fitted in memory at  " << j+1<<endl;
                break;
            }            
        }
        //for not allocated -> the process is not allocated when the process size not less than any of the block size in the array.
    }    
}