//solved
/*
the basic idea is to look for distance from each point where rare element exists
to every point of the matrix and store the distances then finally compare the
distances with each other to find the shortest longest path as "ans".
*/
#include<iostream>
using namespace std;
int matrix_size,num_rare;
int rare_loc[20][3],matrix[20][20];
int visited[20][20],dis[20][20][6];
bool flag=true;

bool is_in_limit(int point_x,int point_y){
    return (point_x>=0&&point_x<matrix_size&&point_y>=0&&point_y<matrix_size&&matrix[point_x][point_y]!=0);
    //ekhane je point nea kaj kortesi oita limit e ase naki check kortese
    //matrix[point_x][point_y]!=0 dea rasta ase naki check kortese

}

void dfs(int th_rare,int point_x,int point_y,int dist){
    if(!is_in_limit(point_x,point_y)){ return; }
    if(dis[point_x][point_y][th_rare]<dist&&visited[point_x][point_y]!=0){  return;}

    dis[point_x][point_y][th_rare]=dist;
    visited[point_x][point_y]=1;
    dfs(th_rare,point_x+1,point_y,dist+1);
    dfs(th_rare,point_x-1,point_y,dist+1);
    dfs(th_rare,point_x,point_y+1,dist+1);
    dfs(th_rare,point_x,point_y-1,dist+1);
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>matrix_size>>num_rare;
        for(int i=0;i<num_rare;i++){
            cin>>rare_loc[i][1];
            cin>>rare_loc[i][2];
            rare_loc[i][1]--;
            rare_loc[i][2]--;
        }
        for(int i=0;i<matrix_size;i++){
            for(int j=0;j<matrix_size;j++){
                cin>>matrix[i][j];
                visited[i][j]=0;
                for(int k=0;k<num_rare;k++){
                    dis[i][j][k]=-1;
                }
            }
        }
        for(int i=0;i<num_rare;i++){
            dfs(i,rare_loc[i][1],rare_loc[i][2],0);
            for(int j=0;j<matrix_size;j++){
                for(int k=0;k<matrix_size;k++){
                    visited[j][k]=0;
                }
            }
        }
        int ans=10000;//INT_MAX
        for(int i=0;i<matrix_size;i++){
            for(int j=0;j<matrix_size;j++){
                if(matrix[i][j]==0){
                    continue;
                }

                int mx=-1;
                for(int k=0;k<num_rare;k++){
                    if(dis[i][j][k]<0){
                        flag=false;
                        continue;
                    }
                    if(dis[i][j][k]>mx)
                    {
                        mx=dis[i][j][k];
                    }
                }
                if(mx<ans){
                    ans=mx;
                }
            }
        }
        cout<<ans<<endl;
    }
}
/*
5
5 2
4 3
3 4
1 1 0 0 0
1 1 0 0 0
1 1 1 1 1
1 1 1 0 1
1 1 1 1 1
8 2
5 6
6 4
1 1 1 1 1 1 0 0
1 1 1 1 1 1 1 0
1 1 0 1 0 1 1 0
1 1 1 1 0 1 1 0
1 1 1 1 1 1 1 0
1 1 1 1 1 1 1 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
10 3
8 2
5 3
7 1
0 0 0 1 1 1 1 1 1 0
1 1 1 1 1 1 1 1 1 0
1 0 0 1 0 0 0 0 1 0
1 1 1 1 1 1 1 1 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 0 0 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1
15 4
11 15
15 9
1 2
14 3
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 1 1 1 1 1 1 1 1 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 0 1 0 0 0 1 1 1 1 1 1 1 0 1
0 0 1 1 1 1 1 1 1 1 1 1 1 1 1
20 4
13 6
20 4
1 2
17 16
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0

Output
#1 1
#2 2
#3 2
#4 12
#5 15
*/
