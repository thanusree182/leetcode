//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


int minFlips (string S)
{
    // your code here
    int flips1=0,flips2=0;
    int n=S.length();
    for(int i=0;i<n;i++){
        if(i%2==0){
            if(S[i]!='1')
            flips1++;
        }
        else{
            if(S[i]!='0')
            flips1++;
        }
    }
    for(int i=0;i<n;i++){
        if(i%2==0){
            if(S[i]!='0')
            flips2++;
        }
        else{
            if(S[i]!='1')
            flips2++;
        }
    }
    return min(flips1,flips2);
}