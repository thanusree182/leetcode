//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    unordered_map<char,int> mp;
    int j=0;
    int maxi=-1;
    for(int i=0;i<s.length();i++){
        mp[s[i]]++;
        if(mp.size()==k){
            maxi=max(maxi,(i-j+1));
        }
        else if(mp.size()>k){
            while(mp.size()>k){
                mp[s[j]]--;
            
            if(mp[s[j]]==0){
                mp.erase(s[j]);
            }
             j++;
            }
        }
    }
    
    return maxi;
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