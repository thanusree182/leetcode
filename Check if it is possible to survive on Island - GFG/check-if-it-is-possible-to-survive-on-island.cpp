//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minimumDays(int S, int N, int M){
        // code here
        int sundays=S/7;
        int buying_days=S-sundays;
        int total_food=S*M;
        int ans=0;
        if((total_food)%N==0){
            ans=total_food/N;
        }
        else{
            ans=total_food/N+1;
        }
        if(ans>buying_days){
            return -1;
        }
        else{
            return ans;
        }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}
// } Driver Code Ends