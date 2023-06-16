//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    long long maximumProfit(vector<long long>&prices, int n) {
        // Code here
        vector<vector<long long>> dp(n+1,vector<long long>(2,0));
        dp[n][0]=0,dp[n][1]=0; //base case
        //now iteration sholud be written backward like n->1
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                
                 if(j==0){
            int buy=-prices[i]+dp[i+1][1];
            int not_buy=dp[i+1][0];
                dp[i][j]=max(buy,not_buy);
                         }
               else if(j==1){
            int sell=prices[i]+dp[i+1][0];
            int not_sell=dp[i+1][1];
               dp[i][j]=max(sell,not_sell);
                       }
            }
        }
        return dp[0][0];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends