//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
   
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp (n,vector<int> (n+1,0));
        for(int i=0;i<=n;i++){
            dp[0][i]=price[0]*(i);
        }
        for(int i=1;i<n;i++){
            for(int w=0;w<=n;w++){
                int not_take=dp[i-1][w];
              int take=INT_MIN;
                  if(w>=i+1){ //a i+1 denotes length of rod at index i
                      take=price[i]+dp[i][w-(i+1)];
                          }
                          dp[i][w]=max(take,not_take);
            }
        }
        return dp[n-1][n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends