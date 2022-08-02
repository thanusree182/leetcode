class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> A;
        for(int i=0;i<matrix.size();i++) {
            for(int j=0;j<matrix[i].size();j++) { 
            A.push_back(matrix[i][j]);
                }
        }
        sort(A.begin(),A.end());
        
        return A[k-1];
    }
};