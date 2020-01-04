//Solved
/*
4
0 1 0 1
1 0 1 0
0 1 0 1
1 0 1 0
3
0 1 0
0 0 1
1 0 0
*/
#include<iostream>
using namespace std;
#define total 1000

int node;
int edge[total][total];
int color[total];
bool isbipartite(int source)
{
    bool flag=true;//for checking with other adjacent nodes
    for(int i=0; i<node; i++)
    {
        if(edge[source][i]==1)
        {
            if(color[i]==color[source])
            {
                return false;
            }
            else if(color[i]==-1)
            {
                color[i]=1-color[source];//Assigning the alternative color
                flag=flag& isbipartite(i);
            }

        }
    }
    return flag;
}
int main()
{
    cin>>node;
    for(int i=0; i<node; i++)
    {
        color[i]=-1;//no color
        for(int j=0; j<node; j++)
        {
            cin>>edge[i][j];
        }
    }
    for(int i=0; i<node; i++) //loop na calaile disconnected graph er jonno kaj korebe na
    {
        if(color[i]==-1)
        {
            color[i]=0;//if node has no color,it becomes 1(suppose red)
            if(!isbipartite(i))
            {
                cout<<-1;
                return 0;
            }
        }


    }
    cout<<"BIPARTITE";
}
