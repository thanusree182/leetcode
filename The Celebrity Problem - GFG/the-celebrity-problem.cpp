//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++



class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        //to find potential candidate we use stack
        stack<int> s;
        for(int i=0;i<n;i++){
            s.push(i);
        }
        while(s.size()>1){
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            if(M[a][b] && M[b][a])continue;
            if(M[a][b]){ //if anyone knows them push into stack
                s.push(b);
            }
            if(M[b][a]){
                s.push(a);
            }
        }
        int candidate=s.top();
        //check if row of that is 0 as it should not know anyone
        int knowns=0;
        for(int i=0;i<n;i++){
            if(M[candidate][i]!= 0) return -1;
            if(candidate!=i && M[i][candidate]==0) return -1;
        }
        
        return candidate;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends