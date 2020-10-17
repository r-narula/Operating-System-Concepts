#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[])
{
    char *str1=argv[1]; // array1
    char *str2=argv[2]; // array2
     if (argc !=3)
    {
        printf("arguments not given");
    }
    else{
    FILE *ptr,*ptr2; // for performing operations on the file this pointer is used.
    char ans;
    ptr = fopen(str1,"r+"); // if not exist fopen returns NULL
    if (ptr == NULL){
        printf("File Not present!");
        printf("Do you want to create file(Y/N):");
        scanf("%c",&ans);
        if (ans=='Y'){
            printf("Files Created \n");
            ptr2 = fopen(str2,"w");
            ptr = fopen(str1,"w");
            fclose(ptr);
            fclose(ptr2);
            exit(402);
        }
        else
        {
        printf("Files not created!");
        exit(404);
        }
    }
    // Now we have the files created and we want things
    else{
    char ch;
    ptr = fopen("dg.txt","r");
    ptr2 = fopen("gd.txt","w");
    while((ch = getc(ptr)) != EOF)
    {
        fputc(ch, ptr2);
    }
    fclose(ptr2);
    fclose(ptr);
    return 0;
    }
    }
}

// Now we want to copy contents from 1 file to another
