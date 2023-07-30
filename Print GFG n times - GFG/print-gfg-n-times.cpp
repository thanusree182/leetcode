//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void solve(vector<string>& ans,int i,int n){
        if(i>=n)
        return;
        ans.push_back("GFG");
        solve(ans,i+1,n);
    }
    void printGfg(int N) {
        // Code here
        vector<string> ans;
        solve(ans,0,N);
        for(int i=0;i<N;i++){
            cout<<ans[i]<<" ";
        }
    }
};


//{ Driver Code Starts.
/* Driver program to test printNos */
int main() {
    int T;

    // taking testcases
    cin >> T;

    while (T--) {
        int N;

        // input N
        cin >> N;
        Solution ob;
        // calling printNos() function
        ob.printGfg(N);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends