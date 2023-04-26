//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        int n=S.length();
        stack<int> st;
        string ans="";
        int i=n-1;
        while(i>=0){
            if(S[i]!='.'){
                st.push(S[i]);
                i--;
            }
            else{
                while(!st.empty()){
                    ans+=st.top();
                    st.pop();
                }
                ans+='.';
                i--;
            }
        }
        if(!st.empty()){
            while(!st.empty()){
            ans+=st.top();
            st.pop();
            }
        }
        return ans;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends