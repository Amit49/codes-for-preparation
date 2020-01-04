//solved
/*You are given N unique numbers a1<a2<a3<...an.
Find out the count of all possible binary search trees
that can be constructed using these numbers.
For example with 3 elements 1,2,3, there are 5 possible BST
and for 1,2,3,4 there are 14 BST.*/

//www.youtube.com/watch?v=YDf982Lb84o

#include<iostream>
using namespace std;
int main()
{
    int num_of_element;
    cin>>num_of_element;
    int bst_for_n[num_of_element+1];
    bst_for_n[0]=1;
    bst_for_n[1]=1;
    for(int i=2;i<=num_of_element;i++){
        bst_for_n[i]=0;
        for(int j=0;j<i;j++){
            bst_for_n[i]+=bst_for_n[j]*bst_for_n[i-j-1];
        }
    }
    cout<<bst_for_n[num_of_element];
}
