//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        //using set in set if better distance is found along with updating dist array we can erase it from set also
        //but we cannot guarantee set has better tc than priority queue becasue erase in set takes O(logn) tc
        set<pair<int,int>> s;
        vector<int> dis(V,1e9);
        s.insert({0,S});
        dis[S]=0;
        while(!s.empty()){
            auto it=*(s.begin());
            int node=it.second;
            int dist=it.first;
            s.erase(it);
            for(auto i:adj[node]){
                int adjNode=i[0];
                int edge_weight=i[1];
                if(dist+edge_weight<dis[adjNode]){
                    if(dis[adjNode]!=1e9){
                        s.erase({dis[adjNode],adjNode}); //differenece  in pq and s
                    }
                    dis[adjNode]=dist+edge_weight;
                    s.insert({dis[adjNode],adjNode});
                }
            }
        }
        return dis;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends