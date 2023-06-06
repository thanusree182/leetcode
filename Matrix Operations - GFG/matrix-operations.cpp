//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix){
        //code here
        int n=matrix.size();
        int m=matrix[0].size();
        int i=0,j=0,dirn=0,ans1=0,ans2=0;
        while((i>=0 && j>=0) && (i<n && j<m)){
            if(matrix[i][j]==1){
                dirn=(dirn+1)%4;
                matrix[i][j]=0;
            }
            ans1=i;ans2=j;
            if(dirn==0){
                j++;
            }
            else if(dirn==1){
                i++;
            }
            else if(dirn==2){
                j--;
            }
            else{
                i--;
            }
        }
        return {ans1,ans2};
    }

};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends