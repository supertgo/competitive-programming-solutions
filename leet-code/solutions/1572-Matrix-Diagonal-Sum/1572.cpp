class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int size = mat.size();
        int dSum = 0;

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (i == j || (i + j) == size - 1) {
                    dSum += mat[i][j];
                }
            }
        }

        return dSum;
    }
};
