//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string reverseAlternate(string str)
{
    // code here 
    int count=0;
    string ans,temp;
    int n=str.length();
    for(int i=0;i<=n;i++){
        if(str[i]==' ' || i==str.length()){
            count++;
            if(count%2==0){
                reverse(temp.begin(),temp.end());
            }
            ans+=temp+" ";
            temp="";
            continue;
        }
        temp+=str[i];
    }
    return ans;
}
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string str;
        getline(cin,str);
        Solution ob;
        cout<<ob.reverseAlternate(str)<<endl;
    }
    return 0;
}

// } Driver Code Ends