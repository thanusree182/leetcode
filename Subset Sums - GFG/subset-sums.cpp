// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    void func(int ind,int sum, vector<int>&arr, int N, vector<int>&sums){
        if(ind==N){
            sums.push_back(sum);
            return;
        }
        func(ind+1,sum+arr[ind],arr,N,sums); //pick
        func(ind+1,sum,arr,N,sums); //dont pick
    }
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> sums;
        func(0,0,arr,N,sums);
        sort(sums.begin(),sums.end());
        return sums;
    }

   
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends