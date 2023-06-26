//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void bfs(int node,vector<vector<int>>& adj,int v,vector<int>& vis){
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int top=q.front();
            q.pop();
            vis[top]=1;
            for(int i=0;i<v;i++){
                if(vis[i]==0 && adj[top][i]==1 ){
                    q.push(i);
                    vis[i]=1;
                }
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int> vis(V,0);
        int count=0;
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                count++;
                bfs(i,adj,V,vis);
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