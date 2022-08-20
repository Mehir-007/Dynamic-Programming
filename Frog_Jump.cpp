/* Given a number of stairs and a frog, the frog wants to climb from the 0th stair to the (N-1)th stair.
At a time the frog can climb either one or two steps. A height[N] array is also given. 
Whenever the frog jumps from a stair i to stair j, 
the energy consumed in the jump is abs(height[i]- height[j]), where abs() means the absolute difference. 
We need to return the minimum energy that can be used by the frog to jump from stair 0 to stair N-1. 
Sample Input:
2
4
10 20 30 10
3
10 50 10
Ouptput:
20
0
*/

#include<bits/stdc++.h>
using namespace std;

//recursion + memoization TC O(n) SC O(n)+O(n)
 
int f(int ind, vector<int>& height, vector<int>& dp)
{
   if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int jumpTwo = INT_MAX;
    int jumpOne= f(ind-1, height,dp)+ abs(height[ind]-height[ind-1]);
    if(ind>1)
        jumpTwo = f(ind-2, height,dp)+ abs(height[ind]-height[ind-2]);
    
    return dp[ind]=min(jumpOne, jumpTwo);
}
// bottom up Tabulation
int f1(int n,vector<int>&height)
{

}
// Tabulation Space Optimized
int f2(int n,vector<int>&height)
{
    
}
int main()
{
    vector<int> height{30,10,60 , 10 , 60 , 50};
    int n=height.size();
    vector<int> dp(n,-1);
    cout<<f(n-1,height,dp);
}