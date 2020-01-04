//solved
#include<iostream>
using namespace std;
int nodes[20][20],node_state[20],parent[20];
int cycle=0;
int node_num,edge_num;
void dfs(int u){
    for(int i=0;i<node_num;i++){
        if(nodes[u][i]==1&&parent[u]!=i&&node_state[u]!=2){
            /*cout<<u<<"-->"<<i<<endl;*/
            node_state[u]=1;
            if(node_state[i]==1&&parent[u]!=i){
                cycle++;
               /* cout<<"cycle found in "<<u<<"<--";
                int x=u;
                while(1){
                    cout<<parent[x];
                    x=parent[x];
                    if(x==i){cout<<endl;break;}
                    cout<<"<--";
                }*/
//                //ekhane return hobe na
            }
            else if(node_state[i]==0) {
                node_state[i]=1;
                parent[i]=u;
                dfs(i);
            }
        }
    }
    node_state[u]=2;
    return;
}
int main(){
    int x,y;
    cin>>node_num>>edge_num;
    for(int i=0;i<node_num;i++){
        node_state[i]=0;
        parent[i]=-1;
    }
    for(int j=0;j<edge_num;j++){
        cin>>x>>y;
        x--,y--;
        nodes[x][y]=1;
        nodes[y][x]=1;
    }
    for(int i=0;i<node_num&&node_state[i]==0;i++){
        dfs(i);
    }
    /*for(int i=0;i<node_num;i++){
        cout<<i<<"="<<node_state[i]<<endl;
    }*/

    cout<<cycle;

}
/*
7 8
1 2
1 6
2 3
2 5
3 4
3 7
4 5
4 7
*/
