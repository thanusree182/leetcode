//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
   bool is_subsequence(string s1,string s2){
       int i=0,j=0;
       while(i<s1.length() && j<s2.length()){
           if(s1[i]==s2[j])
           i++;
           j++;
       }
       return i==s1.length();
   }
    string findLongestWord(string S, vector<string> d) {
        // code here
        string ans="";
        for(auto it:d){
            if(is_subsequence(it,S)){
                if(it.length()>ans.length() || ((it.length()==ans.length())&& it<ans)){
                    ans=it;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> d(n + 1);
        for (int i = 0; i < n; i++) cin >> d[i];
        string S;
        cin >> S;
        Solution ob;
        cout << ob.findLongestWord(S, d) << endl;
    }
    return 0;
}

// } Driver Code Ends