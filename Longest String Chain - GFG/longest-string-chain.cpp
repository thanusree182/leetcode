//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    static bool comp(string& s1,string &s2){
        return s1.size()<s2.size();
    }
    bool check(string& s1,string& s2 ){
        if(s2.length()!=s1.length()+1){
            return false;
        }
        int i=0,j=0;
        while(j<s2.size()){
            if(i<s1.size() && s1[i]==s2[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        if(i==s1.size() && j==s2.size()){
            return true;
        }
        return false;
    }
    int longestChain(int n, vector<string>& words) {
        // Code here
        sort(words.begin(),words.end(),comp);
        vector<int> dp(n,1);
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(check(words[prev],words[i]) && (1+dp[prev])>dp[i]){
                    dp[i]=1+dp[prev];
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> words(N);
        for (int i = 0; i < N; i++) {
            cin >> words[i];
        }
        Solution obj;
        cout << obj.longestChain(N, words) << "\n";
    }
    return 0;
}
// } Driver Code Ends