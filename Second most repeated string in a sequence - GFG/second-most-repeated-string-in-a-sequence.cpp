//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        //code here.
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        int first_freq=INT_MIN,second_freq=INT_MIN;
        string ans1,ans2;
        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->second>first_freq){
                second_freq=first_freq;
                ans2=ans1;
                first_freq=it->second;
                ans1=it->first;
            }
            else if(it->second>second_freq && it->second!=first_freq){
                second_freq=it->second;
                ans2=it->first;
            }
        }
        
        return ans2;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends