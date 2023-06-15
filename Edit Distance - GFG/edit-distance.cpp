//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    int editDistance(string s, string t) {
        // Code here
        int n=s.length();
        int m=t.length();
        vector<int> curr(m+1,0);
        vector<int> prev(m+1,0);
        curr[0]=0;
        for(int j=0;j<=m;j++){
            prev[j]=j;
        }
        for(int i=1;i<=n;i++){
            curr[0]=i;
            for(int j=1;j<=m;j++){
                  if(s[i-1]==t[j-1]){  //1 based indexing
            curr[j]=prev[j-1];
        }
        else{
            int insert=1+curr[j-1];
            int delet=1+prev[j];
            int replace=1+prev[j-1];
            
             curr[j]=min(insert,min(delet,replace));
        }
            }
            prev=curr;
        }
        return prev[m];
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends