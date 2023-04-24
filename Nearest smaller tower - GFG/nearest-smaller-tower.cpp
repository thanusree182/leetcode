//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {
        // code here
        vector<int> left(arr.size(),0),right(arr.size(),0),ans;
        stack<int> st1,st2;
        for(int i=0;i<arr.size();i++){
            while(!st1.empty() && arr[st1.top()]>=arr[i]){
                st1.pop();
            }
            if(st1.size()==0){
                left[i]=-1;
            }
            else{
                left[i]=st1.top();
            }
            st1.push(i);
        }
        
        for(int i=arr.size()-1;i>=0;i--){
            while(!st2.empty() && arr[st2.top()]>=arr[i]){
                st2.pop();
            }
            if(st2.size()==0){
                right[i]=-1;
            }
            else{
                right[i]=st2.top();
            }
            st2.push(i);
        }
        for(int i=0;i<arr.size();i++){
            if(left[i]==-1 && right[i]==-1){
                ans.push_back(-1);
            }
            else if(left[i]==-1){
                ans.push_back(right[i]);
            }
            else if(right[i]==-1){
                ans.push_back(left[i]);
            }
            else{
                if(abs(i-left[i])<abs(i-right[i])){
                    ans.push_back(left[i]);
                }
                else if(abs(i-left[i])>abs(i-right[i])){
                    ans.push_back(right[i]);
                }
                else{
                    if(arr[left[i]]>arr[right[i]]){
                        ans.push_back(right[i]);
                    }
                    else{
                         ans.push_back(left[i]);
                    }
                }
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends