//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool isPossible(int dis,vector<int> v,int cows){
        int cal_cows=1;
        int last=v[0];
        for(int i=1;i<v.size();i++){
            if(v[i]-last>=dis){
                cal_cows++;
                last=v[i];
            }
            if(cal_cows>=cows)
            return true;
        }
        return false;
        
    }
    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        int ans=0;
        sort(stalls.begin(),stalls.end());
        int low=1;
        int high=stalls[n-1]-stalls[0];
        while(low<=high){
            int mid=(low+(high-low)/2);
            if(isPossible(mid,stalls,k)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends