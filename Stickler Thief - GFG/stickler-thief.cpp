//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int func(int arr[],int index,  vector<int>& dp){
        if(index==0 ){
            return dp[index]=arr[0];
        }
        if(index<0){
            return 0;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        int take=arr[index]+func(arr,index-2,dp);
        int not_take=func(arr,index-1,dp);
        return dp[index]= max(take,not_take);
    }
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        vector<int> dp(n+1,-1);
        int ans=func(arr,n-1,dp);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends