#include<iostream>
#include<algorithm>

using namespace std;

int index(int val, int arr[],int len)
{
   int i;
   for(i=0; i<len; i++)
        if(val==arr[i])
            break;
   return i;
}

int main()
{
    int arr[]={6,8,7,3};
    int len=sizeof(arr)/sizeof(int);
    int arr2[len];
    int wait=0;
    int total=0;
    for(int i=0; i<len; i++)
    {
        arr2[i]=arr[i];
    }
    sort(arr2,arr2+len);
    for(int i=0; i<len; i++)
    {
        int x=index(arr2[i],arr,len);
        arr[x]=wait;
        wait=wait+arr2[i];
        total=total+wait;
    }
    for(int i=0; i<len; i++)
    {
        cout<<"Waiting Time for Process "<<i+1<<" = "<<arr[i]<<endl;
    }
    total=total-wait;
    cout<<"Average waiting time : "<<total/len<<endl;
    return 0;
}
