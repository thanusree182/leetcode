//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here 
        int n=str.length();
        set <int> help;
        for(int i=0;i<n;i++){
            help.insert(str[i]);
        }
        int distinct_chars=help.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int visited[256]={0};
            int count=0;
            int size_s=0;
            for(int j=i;j<n;j++){
                if(visited[str[j]]==0){
                    count++;
                    visited[str[j]]=1;
                }
                size_s+=1;
                if(count==distinct_chars){
                    break;
                }
            }
            if(ans>size_s && count==distinct_chars){
                ans=size_s;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends