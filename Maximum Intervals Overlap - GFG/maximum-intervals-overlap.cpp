//{ Driver Code Starts
// Program to find maximum guest at any time in a party
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> findMaxGuests(int Entry[], int Exit[], int N)
	{
	   // Your code goes here
	   sort(Entry,Entry+N);
	   sort(Exit,Exit+N);
	   int i=0,j=0;
	   int count=0,maxCount=0,ansTime=0;
	   while(i<N && j<N){
	       if(Entry[i]<=Exit[j]){
	           count++;
	           if(count>maxCount){
	               maxCount=count;
	               ansTime=Entry[i];
	           }
	           i++;
	       }
	       else{
	           j++;
               count--;
	       }
	   }
	   
	   return {maxCount,ansTime};
	}

};

//{ Driver Code Starts.

 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i;
        cin>>n;
        int entry[n],exit1[n];
        for(i=0;i<n;i++)
        cin>>entry[i];
        for(i=0;i<n;i++)
        cin>>exit1[i];
        Solution obj;

	    vector<int> p = obj.findMaxGuests(entry, exit1, n);
	    cout<<p[0]<<' '<<p[1];
	    cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends