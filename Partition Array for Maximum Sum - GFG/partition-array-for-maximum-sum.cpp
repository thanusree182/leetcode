//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
   
    int solve(int n, int k, vector<int>& arr){
        // Code here
        vector<int> dp(n+1,-1);
        
      
       dp[n]=0;
       for(int i=n-1;i>=0;i--){
           int maxi=INT_MIN;
           int len=0;
        int maxians=INT_MIN;
           for(int j=i;j<min(n,i+k);j++){
               len++;
            maxi=max(maxi,arr[j]);
            int sum=(maxi*len)+dp[j+1];
            maxians=max(maxians,sum);
           }
           dp[i]=maxians;
       }
       return dp[0];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            int x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        cout<<obj.solve(n,k,arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends