//solved
//used "rare element" solving method
/*  source thake bfs calu hoise then wormhole paile wormhole dea jaite koto
    cost ase oita compare kore dekhe minimum cost cost_to_reach[][] array te
    save hoi.
*/
#include<iostream>
using namespace std;
#define maximum_ 100
int source_row,destination_row,source_col,destination_col,numberof_worm;
int cost_to_reach[maximum_][maximum_];
int visited[maximum_][maximum_];

struct wormholes{
    int entry_row,entry_col,exit_row,exit_col,cost;
};
wormholes wormholes_[maximum_];

void initialize(){
    for(int i=0;i<destination_row;i++){
        for(int j=0;j<destination_col;j++){
            cost_to_reach[i][j]=1e9;
            visited[i][j]=0;
        }
    }
}

bool isValid(int point_row,int point_col){
    return (point_col>=0&&point_col<=destination_col&&point_row>=0&&point_row<=destination_row);
}

void find_min_cost(int start_row,int start_col,int cost_temp){

    if(!isValid(start_row,start_col)) {
        return;
    }
    if(visited[start_row][start_col]!=0){
        if(cost_to_reach[start_row][start_col]<cost_temp){
            return;
        }
    }
    visited[start_row][start_col]=1;
    cost_to_reach[start_row][start_col]=cost_temp;
    printf("to reach (%d,%d) it cost %d\n",start_row,start_col,cost_to_reach[start_row][start_col]);
    find_min_cost(start_row-1,start_col,cost_temp+1);
    find_min_cost(start_row+1,start_col,cost_temp+1);
    find_min_cost(start_row,start_col-1,cost_temp+1);
    find_min_cost(start_row,start_col+1,cost_temp+1);

    for(int i=0;i<numberof_worm;i++){
        if(wormholes_[i].entry_row==start_row&&wormholes_[i].entry_col==start_col){
            find_min_cost(wormholes_[i].exit_row,wormholes_[i].exit_col,cost_temp+wormholes_[i].cost);
        }
        else if(wormholes_[i].exit_row==start_row&&wormholes_[i].exit_col==start_col){
            find_min_cost(wormholes_[i].entry_row,wormholes_[i].entry_col,cost_temp+wormholes_[i].cost);
        }
    }
}
int main(){

    cin>>source_row>>source_col>>destination_col>>destination_row>>numberof_worm;
    for(int i=0;i<numberof_worm;i++){
        cin>>wormholes_[i].entry_row;
        cin>>wormholes_[i].entry_col;
        cin>>wormholes_[i].exit_row;
        cin>>wormholes_[i].exit_col;
        cin>>wormholes_[i].cost;
    }
    initialize();
    find_min_cost(source_row,source_col,0);
    int ans=cost_to_reach[destination_row][destination_col];
    cout<<ans;
}
/*
1 1 4 4
3
1 1 2 2 1
2 2 3 3 1
3 3 4 4 1

ans=3

1 1 4 4
3
1 1 4 4 1
2 2 3 3 1
3 3 4 4 1
ans=1

1 1 4 4
1
1 1 2 2 1
ans=5

*/
