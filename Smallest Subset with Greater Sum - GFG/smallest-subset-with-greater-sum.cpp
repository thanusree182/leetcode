//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int minSubset(vector<int> &Arr,int N){
        if(N==1){
            return 1;
        }
        sort(Arr.begin(),Arr.end());
        
        long long int sum=0,result=0;
        int count=0;
        for(int i=0;i<N;i++){
            sum+=Arr[i];
        }
        int i=N-1;
        while(result<=sum && i>0){
            result+=Arr[i];
            sum-=Arr[i];
            count++;
            i--;
        }
        return count;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        cout<<ob.minSubset(Arr,N)<<endl;
    }
    return 0;
}
// } Driver Code Ends