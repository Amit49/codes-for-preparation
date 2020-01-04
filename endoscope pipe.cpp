//solved
#include<iostream>
using namespace std;
#define size 1000
int graph[size][size]; //to store the points
int used[size][size]; //point already used or not
int N,M,R,C,L;
int ans;
int front=0,rear=0;

typedef struct point{
    int x,y;
    int distance;//endoscope koita pipe ei point e asar aage cross seta distance e store thakbe
};
point queue[size*size];

bool is_empt(){
    if(front == rear){
        return true;
    }
    else{
        return false;
    }
}

void push(int x,int y,int distance)
{
    queue[rear].x=x;
    queue[rear].y=y;
    queue[rear].distance=distance;
    rear++;
}

point pop()
{
    front++;
    return queue[front-1];
}
bool up(int x,int y)
{
    if(graph[x][y]==1||graph[x][y]==2||graph[x][y]==4||graph[x][y]==7)
        return true;
    return false;
}
bool down(int x,int y)
{
    if(graph[x][y]==1||graph[x][y]==2||graph[x][y]==5||graph[x][y]==6)
        return true;
    return false;
}
bool left(int x,int y)
{
    if(graph[x][y]==1||graph[x][y]==3||graph[x][y]==6||graph[x][y]==7)
        return true;
    return false;
}
bool right(int x,int y)
{
    if(graph[x][y]==1||graph[x][y]==3||graph[x][y]==4||graph[x][y]==5)
        return true;
    return false;
}
int solution()
{
    ans=0;
    //cout<<"r="<<R<<"c="<<C<<" = "<<graph[R][C]<<endl;
    if(graph[R][C]>=1)
    {
      //  cout<<"Yes"<<endl;
        ans++;
        push(R,C,1);
        used[R][C]=1;
    }

    while(!is_empt()){
        point now=pop();
        int nx=now.x;
        int ny=now.y;
        int ndis=now.distance;
        if(nx-1>=0&&ndis<L&&used[nx-1][ny]==0&&up(nx,ny)&&down(nx-1,ny)){//*nx-1 dara actually upore jacce
            ans++;
            used[nx-1][ny]=1;
            push(nx-1,ny,ndis+1);
        }
        if(nx+1<N&&ndis<L&&used[nx+1][ny]==0&&up(nx+1,ny)&&down(nx,ny)){
            ans++;
            used[nx+1][ny]=1;
            push(nx+1,ny,ndis+1);
        }
        if(ny-1>=0&&ndis<L&&used[nx][ny-1]==0&&left(nx,ny)&&right(nx,ny-1)){
            ans++;
            used[nx][ny-1]=1;
            push(nx,ny-1,ndis+1);
        }
        if(ny+1<M&&ndis<L&&used[nx][ny+1]==0&&left(nx,ny+1)&&right(nx,ny)){
            ans++;
            used[nx][ny+1]=1;
            push(nx,ny+1,ndis+1);
        }
    }
    return ans;
}
int main()
{
    int T;
    cin>>T;

    while(T--){
        cin>>N>>M>>R>>C>>L;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cin>>graph[i][j];
                used[i][j]=0;
            }
        }
        cout<<solution()<<endl;

    }
}
/*
2
5 6 2 1 3
0 0 5 3 6 0
0 0 2 0 2 0
3 3 1 3 7 0
0 0 0 0 0 0
0 0 0 0 0 0
5 6 2 2 6
3 0 0 0 0 3
2 0 0 0 0 6
1 3 1 1 3 1
2 0 2 0 0 2
0 0 4 3 1 1

output#1 5
output#2 15
*/
