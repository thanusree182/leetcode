//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to count paths between two vertices in a directed graph.
    void dfs(int s,int d,vector<int> adj[],vector<int>& vis,int& ans){
        if(s==d){
            ans++;
            return ;
        }
         vis[s]=1;
        for(auto it:adj[s]){
            if(!vis[it]){
               
                dfs(it,d,adj,vis,ans);
            }
        }
        vis[s]=0; //backtrack
    }
    int countPaths(int V, vector<int> adj[], int source, int destination) {
        // Code here
        int ans=0;
        vector<int> vis(V,0);
            dfs(source,destination,adj,vis,ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // adj[v].push_back(u);
        }
        int source, destination;
        cin >> source >> destination;
        Solution obj;
        cout << obj.countPaths(V, adj, source, destination) << endl;
    }
    return 0;
}
// } Driver Code Ends