//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int K) {
    // your code here
    int ans=0;
    int i=0,j=0;
    int n=s.length();
    unordered_map<char,int> mp;
       while(i<n && j<n){
           mp[s[j]]++;
           if(mp.size()>K){
               while(mp.size()>K && i<j){
                   mp[s[i]]--;
                   
                   if(mp[s[i]]==0){
                       mp.erase(s[i]);
                   }
                   i++;
               }
           }
           if(mp.size()==K){
               ans=max(ans,(j-i+1));
           }
           j++;
       }
       if(ans==0)
       return -1;
       else
       return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends