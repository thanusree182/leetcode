// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
   { 
       // code here 
       stack<string>st;
       for(int i=0;i<s.length();i++)
       {
           string a = "";
           while(i<s.length()&&s[i]!='.')
           {
               a+= s[i];
               i++;
           }
           st.push(a);
       }
       while(!st.empty())
       {
           cout<<st.top();
           st.pop();
           if(!st.empty())
           {
               cout<<".";
           }
       }
   }


};

// { Driver Code Starts.
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
}  // } Driver Code Ends