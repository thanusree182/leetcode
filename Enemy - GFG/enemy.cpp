//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        int largestArea(int n,int m,int k,vector<vector<int>> &enemy)
        {
            //  code here
            vector<int> row(n,1);
            vector<int> col(m,1);
            for(int i=0;i<enemy.size();i++){
                int r=enemy[i][0];
                int c=enemy[i][1];
                row[r-1]=0;
                col[c-1]=0;
            }
            int r1=0,c1=0,x=0;
            for(int i=0;i<row.size();i++){
                if(row[i]==1){
                    x++;
                    r1=max(x,r1);
                }
                else{
                    x=0;
                }
            }
            x=0;
            for(int i=0;i<col.size();i++){
                if(col[i]==1){
                    x++;
                    c1=max(x,c1);
                }
                else{
                    x=0;
                }
            }
            return r1*c1;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int k;
        cin>>k;
        vector<vector<int>> e(k,vector<int>(2));
        for(int i=0;i<k;i++)
            cin>>e[i][0]>>e[i][1];
        Solution a;
        cout<<a.largestArea(n,m,k,e)<<endl;
    }
    return 0;
}
// } Driver Code Ends