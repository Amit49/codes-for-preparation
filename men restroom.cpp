//solved
#include<iostream>
using namespace std;
#define total 1000

bool fillup[total];
int n;

int index_of_biggest_gap(){

    int current_gap=0;
    int current_index=-1;//current gap er 1st index;
    int previous_gap=0;
    int previous_index=-1;//previous gap er 1st index;

    int first_encounter=0;//first time seeing an empty space
    for(int i=0;i<n;i++){
        if(fillup[i]==false&&first_encounter!=0){
            current_gap++;
        }
        else if(fillup[i]==false&&first_encounter==0){
            current_gap++;
            current_index=i;
            first_encounter=1;
        }
        else if(fillup[i]==true){
            if(current_gap>previous_gap){
                previous_gap=current_gap;
                previous_index=current_index;
        }
        current_index=i+1;
        current_gap=0;
        }
    }
    if(current_gap>previous_gap)//(***)ei if ta na dile last gap ta count hobe na
    {
        previous_gap=current_gap;
        previous_index=current_index;
    }
    return previous_index+(previous_gap/2);
}
int main()
{

    cin>>n;
    string s="";
    for(int i=0;i<n;i++)
    {
        fillup[i]=false;
        s+="_";
    }
    for(int i=0;i<n;i++){
        int index=index_of_biggest_gap();
        fillup[index]=true;
        s[index]='X';
        cout<<s<<endl;
    }
}
