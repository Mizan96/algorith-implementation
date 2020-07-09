#include<iostream>

using namespace std;

int main()
{
    int p,r;
    int p_r=0;
    cout<<"Enter The Number of Process:"<<endl;
    cin>>p;
    cout<<"Enter The Number of Resource:"<<endl;
    cin>>r;
    cout<<"Enter the number of instance of each process:"<<endl;
    int ins[r];
    int p_s[r];
    for(int i=0; i<r; i++)
    {
     p_s[i]=0;
    }
    for(int i=0; i<r; i++)
        cin>>ins[i];
    cout<<"Enter resource allocation table:"<<endl;
    int allo[p][r];
    for(int i=0; i<p; i++)
    {
        for(int j=0; j<r; j++)
        {
            cin>>allo[i][j];
        }
    }
    cout<<"Enter the max table:"<<endl;
    int maxi[p][r];
    for(int i=0; i<p; i++)
    {
        for(int j=0; j<r; j++)
        {
            cin>>maxi[i][j];
        }
    }
    int choice;
   while(1)
   {
        cout<<"Here is need table:"<<endl;
    int need[p][r];
    for(int i=0; i<p; i++)
    {
        for(int j=0; j<r; j++)
        {
            if(p_r==i)
            {
                need[i][j]=maxi[i][j]-allo[i][j]+p_s[j];
                cout<<need[i][j]<<" ";
            }
            else{
                need[i][j]=maxi[i][j]-allo[i][j];
                cout<<need[i][j]<<" ";
            }

        }
        cout<<endl;
    }
    int work[r];
    for(int i=0; i<r; i++)
    {
        work[i]=0;
        for(int j=0; j<p; j++)
        {
                work[i]=work[i]+allo[j][i];
        }
    }
    cout<<"Present Available Resource:"<<endl;
    for(int i=0; i<r; i++)
        {
            work[i]=ins[i]-work[i];
            cout<<work[i]<<" ";
        }
        cout<<endl;
    int se[p],c=0;
    int visit[p];
    for(int i=0;i<p; i++)
        {
            se[i]=-1;
            visit[i]=0;
        }
    for(int i=0; i<p; i++)
    {
        for(int j=0; j<p; j++)
        {
            if(visit[j]==0)
            {
            int counter=0;
            for(int k=0; k<r; k++)
            {
                if(need[j][k]<=work[k])
                    counter++;
            }
            if(counter==r)
            {
                visit[j]=1;
                se[c]=j;
                c++;
                for(int k=0; k<r; k++)
                {
                    work[k]=work[k]+allo[j][k];
                }
            }
            }
        }
    }
    if(c==p)
    {
        cout<<"Your system is in safe state:"<<endl;
        for(int i=0; i<p; i++)
            cout<<se[i]<<" ";
        cout<<endl;
    }
    else
    {
        cout<<"Your system is in unsafe state:"<<endl;
    }
    cout<<"Press -1 to add process value and -2 for exit:"<<endl;
    cin>>choice;
    if(choice==-1)
    {
        cout<<"Enter name of process and value of process:"<<endl;
        cin>>p_r;
        for(int i=0; i<r; i++)
            cin>>p_s[i];

    }
    else{
        break;
    }
   }
    return 0;
}
