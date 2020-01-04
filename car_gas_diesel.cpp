#include<iostream>
#include<climits>
using namespace std;
#define total 100
int car_type[total];
bool visited[total];
int total_dis=99999;
void minimum_distance(int n,int distance,int rem,int rindex,int car_fueled,int insert_need,int g_or_d){
    if(car_fueled==n){
        if(total_dis>distance){
            total_dis=distance;
        }
        return;
    }
    if(rem<=0){
        return;
    }
    if(insert_need==0&&g_or_d==0)//no insert needed and fuel type is gas
    {
        for(int i=1;i<=n;i++){
            if(!visited[i]&&car_type[i]==1){
                int x=i-rindex;
                if(x<0){
                    x=-x;
                }
                visited[i]=true;
                minimum_distance(n,distance+x,rem-1,i,car_fueled+1,0,0);
                minimum_distance(n,distance+x,2,i,car_fueled+1,1,0);
                minimum_distance(n,distance+x,2,i,car_fueled+1,2,0);
                visited[i]=false;
            }
            }

    }

    if(insert_need==0&&g_or_d==1)//no insert needed and fuel type is diesel
    {
        for(int i=n;i>=1;i--){
            if(!visited[i]&&car_type[i]==2){
                int x=i-rindex;
                if(x<0){
                    x=-x;
                }
                visited[i]=true;
                minimum_distance(n,distance+x,rem-1,i,car_fueled+1,0,1);
                minimum_distance(n,distance+x,2,i,car_fueled+1,1,1);
                minimum_distance(n,distance+x,2,i,car_fueled+1,2,1);
                visited[i]=false;
            }
            }
    }
    if(insert_need==1){
        int x=rindex-0;
        minimum_distance(n,distance+x,2,0,car_fueled,0,0);
    }
    else if(insert_need==2){
        int x=(n+1)-rindex;
        minimum_distance(n,distance+x,2,n+1,car_fueled,0,1);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; //number of car
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>car_type[i];
        }
        minimum_distance(n,0,2,0,0,0,0);
        if(total_dis==99999){
            minimum_distance(n,n+1,2,n+1,0,0,1);
        }
        cout<<total_dis<<endl;
        total_dis=99999;
    }
}
/*
2
5
1 2 1 2 1
5
2 1 1 2 1
*/
