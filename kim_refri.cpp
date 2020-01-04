//solved
#include<iostream>
using namespace std;
int n,x[20],y[20],ans;

int dis(int u,int v)
{
    int disx=x[u]-x[v];
    int disy=y[u]-y[v];
    if(disx<0) {disx=-disx;}
    if(disy<0) {disy=-disy;}

    return (disx+disy);
}
void optimal(int cur,bool vis[],int nodes,int value)
{
    if(nodes==n)
    {
        ans=min(ans,value+dis(cur,n+1)); //return korbe na
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i]){
            vis[i]=true;
            optimal(i,vis,nodes+1,value+dis(cur,i));
            vis[i]=false;
        }
    }
}
int main()
{
    int test;
    cin>>test;
    for(int i=1;i<=test;i++){ //customer er index '1' thake suru hobe
        ans=INT_MAX;
        cin>>n;
        bool vis[n+2]={false};
        cin>>x[n+1]>>y[n+1]>>x[0]>>y[0];
        for(int j=1;j<=n;j++){
            cin>>x[j]>>y[j];
        }

        optimal(0,vis,0,0);
        cout<<"#"<<i<<" "<<ans<<endl;
    }
}
/*
3
5
0 0 100 100 70 40 30 10 10 5 90 70 50 20
6
88 81 85 80 19 22 31 15 27 29 30 10 20 26 5 14
10
39 9 97 61 35 93 62 64 96 39 36 36 9 59 59 96 61 7 64 43 43 58 1 36

#1 200

#2 304

#3 366
*/
