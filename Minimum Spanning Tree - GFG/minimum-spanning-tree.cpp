//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        //tree which have n nodes n-1 edges and all nodes are reachable from each other
//          Notes for self!
// Required data structures
// 1. Min heap
// 2. Visited array
// 3. Mst list that will store all the edges that are a part of MST

// Datatypes of our data structures
// Visited array => int
// Mst list =>  (weight , node name , node parent)



// Steps
// 1. Mark the visited array as 0 for all the nodes

// 2. Start with 0th node and push
// (0,0,-1)
// explanation:  -1 means 0 is the genesis node
// Mark 0 as visited

// 3. Push all the neighbours of 0 in pq Do not mark them visited  (footnote 1)
// Since its a min heap the edge with minimum weight will be at the top

// 4. Pick up the top edge , insert it in the mst , mark the picked node as visited , insert all neighbours of picked node into pq

// 5. keep repeating steps 3 and 4 untill all the nodes have been picked up and thats when the algorithm ends


// footnote:
// 1. why to not mark it visited?
// in bfs , when we push the element inside a queue we mark it as visited cause that element will be picked up later for sure (algorithm ends only when the queue is empty )
// but in msts case even if we push the edge into pq , theres no surety that the edge will be picked up . when prims algo ends there are still a few non accepted edges present in the pq hence we only mark it visited once its picked up from pq


        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> vis(V,0);
        int sum=0;
        pq.push({0,0});
        while(!pq.empty()){
            auto it=pq.top();
            int wt=it.first;
            int node=it.second;
            pq.pop();
            if(vis[node]==1){
                continue;
            }
            vis[node]=1;
            sum+=wt;
            for(auto i:adj[node]){
                int adjNode=i[0];
                int edjw=i[1];
                if(!vis[adjNode]){
                    pq.push({edjw,adjNode});
                }
            }
        }
        
        return sum;
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
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends