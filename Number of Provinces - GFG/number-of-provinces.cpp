//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void solve(int i,vector<vector<int>>& adj,int V,vector<int>& vis){
        vis[i]=1;
        for(int j=0;j<V;j++){
            if(adj[i][j]==1 && vis[j]==0){
                solve(j,adj,V,vis);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        
        vector<int> vis(V+1,0);
        int count=0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                count++;
                solve(i,adj,V,vis);
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends