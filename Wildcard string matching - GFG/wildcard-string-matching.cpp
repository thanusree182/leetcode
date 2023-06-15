//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    public:
    bool solve(int i,int j, string& p,string& s){
        if(i<0 && j<0){
            return true;
        }
        if(i<0 && j>=0 ){
            return false;
        }
        if(i>=0 && j<0){
            for(int k=0;k<=i;k++){
                if(p[k]!='*'){
                    return false;
                }
            }
            return true;
        }
        if(p[i]==s[j] || p[i]=='?'){
            return solve(i-1,j-1,p,s);
        }
        if(p[i]=='*'){
            return solve(i-1,j,p,s) || solve(i,j-1,p,s);
        }
        return false;
    }
    bool match(string wild, string pattern)
    {
        // code here
        int n=wild.length();
        int m=pattern.length();
        return solve(n,m,wild,pattern);
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        if(ob.match(wild, pattern))
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends