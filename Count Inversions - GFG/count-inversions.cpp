//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int merge(long long arr[], long long temp[], long long left, long long mid, long long right) {
    long long i, j, k;
    long long inv_count = 0;

    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            inv_count += (mid - i); //as left half is sorted if ith element of left half is
           // bigger than right element then all element after ith element in left half will 
            //also be greater elements than element in right half 
        }
    }
    while (i <= mid - 1) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return inv_count;
}

long long int _mergeSort(long long arr[], long long temp[], long long left, long long right) {
    long long mid, inv_count = 0;
    if (right > left) {
        mid = (right + left) / 2;

        inv_count +=_mergeSort(arr, temp, left, mid); //inversions in left half
        inv_count += _mergeSort(arr, temp, mid + 1, right); //inversions in right half

        inv_count += merge(arr, temp, left, mid + 1, right); //inversions when both are mixed
    }
    return inv_count;
}

long long int inversionCount(long long arr[], long long N) {
    long long temp[N];
    return _mergeSort(arr, temp, 0, N - 1);
}
    
};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends