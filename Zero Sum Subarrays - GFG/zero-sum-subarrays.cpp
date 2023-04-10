//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n ) {
        //code here
        long long int result=0;
        map<long long int,int> frequency;
        long long int sum=0;
        //firt we add frequency 0 as 1 time in map as we initialise sum with 0
        frequency[0]++;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            result+=frequency[sum]; //if we peviously same sum is found that means 
            //in between all elements sum=0 hence we add with previous sum frequency
            frequency[sum]++;
        }
        return result;
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
        cin>>n; //input size of array
       
        vector<long long int> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}
// } Driver Code Ends