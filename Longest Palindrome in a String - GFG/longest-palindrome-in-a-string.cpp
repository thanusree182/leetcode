//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) {
        // code here
         int n=S.length();
        string ans="";
        ans=S[0];
        for(int i=1;i<n;i++){
            int h=i;
            int l=i-1;
            while(S[l]==S[h] && i>=0 && h<n){
                if(ans.length()<(h-l+1)){
                    ans=S.substr(l,h-l+1);
                }
                l--;
                h++;
            }
            
        }
        
         for(int i=1;i<n;i++){
            int h=i+1;
            int l=i-1;
            while(S[l]==S[h] && i>=0 && h<n){
                if(ans.length()<(h-l+1)){
                    ans=S.substr(l,h-l+1);
                }
                l--;
                h++;
            }
            
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends