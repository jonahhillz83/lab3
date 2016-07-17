/*
*
*Lab4
*Program:Binary search
*Author: Pratyush Nepal
*Ref:http://www.cprogrammingcode.com/2014/08/write-cc-code-to-implement-binary.html
*
*/


#include<stdio.h>
void binsrch(int array[],int num, int low, int high)
{
    int mid;
    if(low>high){
        printf("invalid!");
    }
    else{
        mid=(low+high)/2;
        if(array[mid]==num){
            printf("found at the location %d",mid);
            exit(0);
        }
        else if(array[mid]>num){
            binsrch(array,num,low,mid-1);
        }
        else{
            binsrch(array,num,mid+1,high);
        }
    }
}
int main(){
int array[100],i,n,num,low,high;
printf("enter array size");
scanf("%d",&n);
printf("enter the values");
for(i=0;i<n;i++)
{
    scanf("%d",&array[i]);
}
low=0;
high=n-1;
printf("enter to search");
scanf("%d",&num);
binsrch(array,num,low,high);
}

