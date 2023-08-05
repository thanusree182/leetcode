//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void Reverse(stack<int> &St){
        if(St.size()==1)
        return;
        int top=St.top();
        St.pop();
        Reverse(St);
        Insert(St,top);
    }
    void Insert(stack<int>& s,int top){
        if(s.empty())
        {
            s.push(top);  //if single elemnt just push into stack
            return;
        }
        int temp=s.top();
        s.pop();                      //else remove all elements and push above element and then push poppe delements 
        Insert(s,top);    
        s.push(temp);
        
        return;
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends