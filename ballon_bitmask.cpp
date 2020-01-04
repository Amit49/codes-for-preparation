#include<iostream>
using namespace std;
#define ll long long
ll n,dp[20][1<<15],point[15];
ll setbit(int n,int i){
    n=n|(1LL<<i);
    return n;
}
ll checkbit(int n,int i){
    n=n&(1LL<<i);
    return n;
}
ll find_ans(int msk,int idx){
    if(msk==(1<<n)-1){
        return 0;
    }
    if(dp[idx][msk]!=-1){
        return dp[idx][msk];
    }
    ll rt,lt,mx=0LL;
    for(int i=0;i<n;i++){
        if(checkbit(msk,i)){
            continue;
        }
        rt=-1,lt=-1;
        for(int l=i-1;l>=0;l--){
            if(checkbit(msk,l)==0){
                lt=l;
                break;
            }
        }
        for(int r=i+1;r<n;r++){
            if(checkbit(msk,r)==0){
                rt=r;
                break;
            }
        }
        int temp;
        if(rt==-1&&lt==-1){ temp=point[i];}
        else if(rt==-1){ temp=point[lt];}
        else if(lt==-1){ temp=point[rt];}
        else { temp=point[lt]*point[rt];}
        mx=max(mx,temp+find_ans(setbit(msk,i),idx+1));
    }
    dp[idx][msk]=mx;
    return mx;
}
int main()
{
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        cin>>n;
        for(int i=0;i<15;i++){
            for(int j=0;j<(1<<12);++j){
                dp[i][j]=-1;
            }
        }
        for(int i=0;i<n;i++){
            cin>>point[i];
        }
        int ans=find_ans(0,0);
        cout<<ans<<endl;
    }
}
