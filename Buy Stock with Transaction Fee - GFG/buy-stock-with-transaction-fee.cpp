//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long solve(int i, int sell_or_buy,vector<long long>& prices,vector<vector<long long>>& dp,int fee){
        if(i==prices.size()){
            return 0;
        }
        if(dp[i][sell_or_buy]!=-1){
            return dp[i][sell_or_buy];
        }
        if(sell_or_buy==0){
            int buy=-prices[i]+solve(i+1,1,prices,dp,fee);
            int not_buy=solve(i+1,0,prices,dp,fee);
            return dp[i][sell_or_buy]=max(buy,not_buy);
        }
        if(sell_or_buy==1){
            int sell=prices[i]-fee+solve(i+1,0,prices,dp,fee);
            int not_sell=solve(i+1,1,prices,dp,fee);
            return dp[i][sell_or_buy]=max(sell,not_sell);
        }
    }
    long long maximumProfit(vector<long long>&prices, int n, int fee) {
        // Code here
        
        // Code here
        vector<vector<long long>> dp(n,vector<long long>(2,-1));
        return solve(0,0,prices,dp,fee); //0-->buy 1-->sell
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
        
        int fee; cin>>fee;
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n, fee)<<"\n";
    }
    return 0;
}
// } Driver Code Ends