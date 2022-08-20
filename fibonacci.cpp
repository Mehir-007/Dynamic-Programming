#include<bits/stdc++.h>
using namespace std;

// normal reccurison 

int fibo_recc(int n)
{
    if(n<=1) return n;
    return fibo_recc(n-1)+fibo_recc(n-2);
}

// memoization Time complexity O(n), Space Complexity O(n) for stack and O(n) for Dp array 

int fibo_memo(int n,vector<int> &dp)
{
    if(n<=1) return n;
    if(dp[n] != -1) return dp[n];
    return dp[n]=fibo_memo(n-1,dp)+fibo_memo(n-2,dp);
}

// tabulation Time complexity O(n), Space Complexity O(n)

int fibo_tab(int n)
{
    vector<int> dp(n+1); dp[0]=0;dp[1]=1;
    if(n<=1) return n;
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

// tabulation Space Optimized, Time complexity O(n), Space Complexity O(1)

int fibo_tab_space(int n)
{
    int last2=0;
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
    cout<<fibo_recc(n)<<endl; //normal reccursion method call


    vector<int> dp(n+1,-1);

    cout<<fibo_memo(n,dp)<<endl;  //memoization method call 

    cout<<fibo_tab(n)<<endl; // tabulatuion method call

    cout<<fibo_tab_space(n)<<endl; // tabulation space optimized
}