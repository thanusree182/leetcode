//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int solve(string& A, string& B,int n,int m){
        if(n==0 || m==0){
            return 0;
        }
        if(A[n-1]==B[m-1]){
            return 1+solve(A,B,n-1,m-1);
        }
        else{
            return solve(A,B,n-1,m);
        }
        
    }
    int getLongestSubsequence(string A, string B) {
        // code here
        int n=A.length(),m=B.length();
        int maxi=0;
        for(int i=0;i<=m;i++){
            int ans=solve(A,B,n,i);
            maxi=max(maxi,ans);
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string A,B;

        cin >>A>>B;

        Solution ob;
        cout << ob.getLongestSubsequence(A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends