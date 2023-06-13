//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   //if we take Longest common subsequence of given string and reverse of that string as palindrome common one is the answer
  public: 
  //we need to print it
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        vector<vector<int>> dp  (x+1,vector<int>(y+1,0));
        for(int i=0;i<=x;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<=y;j++){
            dp[0][j]=0;
        }
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                if(s1[i-1]==s2[j-1]){
               dp[i][j]=1+dp[i-1][j-1];
               }
                else{
               dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
               }
            }
        }
        return dp[x][y];
    }
    int longestPalinSubseq(string A) {
        //code here
        string B=A;
        reverse(A.begin(),A.end());
        int n=A.length();
        int len=lcs(n,n,A,B);
        return len;
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends