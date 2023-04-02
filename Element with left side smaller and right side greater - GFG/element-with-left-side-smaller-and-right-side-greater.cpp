//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findElement(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) cin >> a[i];
        cout << findElement(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends

bool check(int arr[],int n,int index){
    int i=index-1;
    int j=index+1;
    while(i>=0){
    if(arr[i]>arr[index])
    return false;
        i--;
    }
    while(j<n){
        if(arr[j]<arr[index]){
            return false;
        }
        j++;
    }
    return true;
}
int findElement(int arr[], int n) {
    for(int i=1;i<n-1;i++){
        if(check(arr,n,i)){
            return arr[i];
        }
    }
    return -1;
}