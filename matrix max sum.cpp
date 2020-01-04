//solved
#include<iostream>
using namespace std;
#define r 100
#define c 100
int maximum_sum(int matrix[r][c],int row,int col){
    int max_sum[row][col];
    //cout<<matrix[0][0]<<endl;
    max_sum[0][0]=matrix[0][0];//(0,0) initialize korte hobe
    for(int i=1;i<row;i++){
        max_sum[i][0]=max_sum[i-1][0]+matrix[i][0];
    }
    for(int i=1;i<col;i++){
        max_sum[0][i]=max_sum[0][i-1]+matrix[0][i];
    }

    for(int i=1;i<row;i++){
        for(int j=1;j<col;j++){
            max_sum[i][j]=max(max_sum[i-1][j],max_sum[i][j-1])+matrix[i][j];
        }
    }
    return max_sum[row-1][col-1];
}
int main()
{
    int row,col;
    cin>>row>>col;
    //r=row,c=col;
    int cost_matrix[r][c];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>cost_matrix[i][j];
        }
    }
    int ans=maximum_sum(cost_matrix,row,col);
    cout<<ans;
}
/*
4 4
2 3 4 1
1 1 3 9
2 2 3 1
2 2 3 1
*/
