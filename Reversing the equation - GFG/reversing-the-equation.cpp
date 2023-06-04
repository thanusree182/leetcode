//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
            //code here.
            string ans;
            string temp;
            int n=s.length();
            for(int i=n-1;i>=0;i--){
                if(s[i]=='-' || s[i]=='+' || s[i]=='*' || s[i]=='/'){
                    reverse(temp.begin(),temp.end());
                    ans+=temp;
                    ans+=s[i];
                    temp="";
                }
                else{
                    temp+=s[i];
                }
            }
            reverse(temp.begin(),temp.end());
            ans+=temp;
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends