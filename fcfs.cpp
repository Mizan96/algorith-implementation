#include<iostream>

using namespace std;

int main()
{
    int arr[]={24,3,3};
    int wait=0;
    int total=0;
    int len=sizeof(arr)/sizeof(int);
    for(int i=0; i<len; i++)
    {
        cout<<"Waiting Time for Process "<<i+1<<" = "<<wait<<endl;
        wait=wait+arr[i];
        total=total+wait;
    }
    total=total-wait;
    cout<<"Average waiting time : "<<total/len<<endl;
    return 0;
}
