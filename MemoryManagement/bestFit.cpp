#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    // cin>>n;
    int processSize[4]={212, 417, 112, 426};
    int blocksize[5]={100, 500, 200, 300, 600};

    for (int i = 0; i < sizeof(processSize)/sizeof(processSize[0]); i++) // for the process
    {
        int flag = 0;
        int min  = INT_MAX;
        int great = 0;
        for (int j = 0; j < sizeof(blocksize)/sizeof(blocksize[0]); j++) // for the block
        {
            if (processSize[i]<blocksize[j])
            {
                // update the minimum..
                int a = blocksize[j] - processSize[i];
                if (a<min)
                {
                    min = a;
                    great = blocksize[j];
                }
            }
        }
        cout<<"Min is:"<<min<<endl;
        cout<<"Great is :"<<great<<endl;
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
        

    }    
}
/*
blocksize[j] -= processSize[i];
                flag = 1;
                break;
*/