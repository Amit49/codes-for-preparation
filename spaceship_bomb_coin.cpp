//solved
#include<iostream>
using namespace std;
int ans=0;
int arr[20][5];
void highest_ans(int row,int col,int temp,int bomb,int b_effect){
    if(row<0){
        if(temp>ans){
            ans=temp;
        }
        return;
    }
    for(int i=-1;i<=1;i++){
        if(col+i<0||col+i>4){
            continue;
        }
        if(arr[row][col+i]==0||arr[row][col+i]==1){//enemy nai
            if(bomb==0){//bomb use hoise sei jonno b_effect minus 1 kora hoise
                highest_ans(row-1,col+i,temp+arr[row][col+i],bomb,b_effect-1);
                //ekhane temp er shate point jog hocce, last e gea ans er shate compare hobe
            }
            else{ //bomb use hoi nai
                highest_ans(row-1,col+i,temp+arr[row][col+i],bomb,b_effect);
            }
        }
        else{ //enemy ase
            if(bomb==0){
                highest_ans(row-1,col+i,temp,bomb,b_effect-1);
            }
            else{
                highest_ans(row-1,col+i,temp,0,5);
            }

        }
    }
    return;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<5;j++){
            cin>>arr[i][j];
        }
    }
    int starting_row=n-1; //সবার নিচের রো থেকে শুরু হইছে সেইজন্য (n-1)
    int starting_col=2; //মাঝখানের কলাম থেকে শুরু হইছে
    highest_ans(starting_row,starting_col,0,1,0);
    cout<<ans;

}
/*
6
0 1 0 2 0
0 2 2 2 1
0 2 1 1 1
1 0 1 0 0
0 0 1 2 2
1 1 0 0 1
*/
