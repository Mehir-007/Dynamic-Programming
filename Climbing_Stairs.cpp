/* Problem Statement: Given a number of stairs.
Starting from the 0th stair we need to climb to the “Nth” stair.
At a time we can climb either one or two steps. We need to return the total number of distinct ways to reach from 0th to Nth stair.
*/

#include<bits/stdc++.h>
using namespace std;

int Stairs(int n)
{
    int last2=1;
    int last1=1;
    if(n<=1) return n;
    for(int i=2;i<=n;i++)
    {
        int temp=last1+last2;
        last2=last1;
        last1=temp;
    }
    return last1;
}

int main()
{
    int n;cin>>n;

    cout<<"Number of ways to climb stairs : "<<Stairs(n)<<endl;
}