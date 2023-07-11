//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int n, int m, vector<vector<int>>&a)  {
        // code here
        	int top=0,bottom=n-1;
 		int left=0,right=m-1;
 		vector<int> help;
 		while(top<=bottom && left<=right){
 		    for(int i=left;i<=right;i++){
 		        help.push_back(a[top][i]);
 		    }
 		    top++;
 		   
 		    for(int j=top;j<=bottom;j++){
 		        help.push_back(a[j][right]);
 		    }
 		    
 		    right--;
 		    if(top<=bottom){
 		    for(int i=right;i>=left;i--){
 		        help.push_back(a[bottom][i]);
 		    }
 		     bottom--;
 		    }
 		   
 		    
 		    if(left<=right){
 		    for(int i=bottom;i>=top;i--){
 		        help.push_back(a[i][left]);
 		    }
 		    left++;
 		    }
 		    
 		}
 		
 		reverse(help.begin(),help.end());
 		return help;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends