//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    long long maximumProfit(vector<long long>&prices, int n) {
        // Code here
         vector<long long> prev(2,0),curr(2,0);
         
        prev[0]=0,prev[1]=0; //base case
        //now iteration sholud be written backward like n->1
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                
                 if(j==0){
            int buy=-prices[i]+prev[1];
            int not_buy=prev[0];
                curr[j]=max(buy,not_buy);
                         }
               else if(j==1){
            int sell=prices[i]+prev[0];
            int not_sell=prev[1];
               curr[j]=max(sell,not_sell);
                       }
            }
            prev=curr;
        }
        return curr[0];
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