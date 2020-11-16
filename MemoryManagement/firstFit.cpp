#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    // cin>>n;
    int processSize[4]={212, 417, 112, 426};
    int blocksize[5]={100, 500, 200, 300, 600};

    for (int i = 0; i < 4; i++) // for the process
    {
        int flag = 0;
        for (int j = 0; j < 5; j++) // for the block
        {
            if (processSize[i]<blocksize[j])
            {
                blocksize[j] -= processSize[i];
                cout<<"Process allocated of size: "<<processSize[i]<<"  In block "<<j+1<<endl;
                flag = 1;
                break; // now move to next
            }
        }
        // here it reaches when the process has traversed all the blocks and not find its block to get allocated.
        if (flag==0)
        {
        cout<<"The Process of size : "<<processSize[i]<<" Is not allocated"<<endl;
        }
    }
    
}