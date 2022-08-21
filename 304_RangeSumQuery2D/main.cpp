class NumMatrix {
public:
    vector<vector<int>> sum_mat;
    NumMatrix(vector<vector<int>>& matrix) { 
        sum_mat.resize(matrix.size());
        for (auto& it : sum_mat) {
            it.resize(matrix[0].size());
        }
        // left-up most entry
        sum_mat[0][0] = matrix[0][0];
        try {
            // left-most col
            for (int i = 1; i < matrix.size(); i++) {
                sum_mat.at(i).at(0) = matrix.at(i).at(0) + sum_mat.at(i-1).at(0);
            }
            // up-most row
            for (int j = 1; j < matrix[0].size(); j++) {
                sum_mat.at(0).at(j) = matrix.at(0).at(j) + sum_mat.at(0).at(j-1);
            }
            // other entries
            for (int i = 1; i < matrix.size(); i++) {
                for (int j = 1; j < matrix[0].size(); j++) {
                    sum_mat.at(i).at(j) = matrix.at(i).at(j) + sum_mat.at(i-1).at(j) + sum_mat.at(i).at(j-1) - sum_mat.at(i-1).at(j-1);
                }
            }
        } catch (out_of_range const& exp) {}
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {  
        cout << "------------------" << endl;
        auto leftup = int(0), leftbtm = int(0), rightup = int(0), rightbtm = int(0);
        try {
            leftup = sum_mat.at(row1-1).at(col1-1);
        } catch (out_of_range const& exp) {}
        try {
            leftbtm = sum_mat.at(row2).at(col1-1);
        } catch (out_of_range const& exp) {}
        try {
            rightup = sum_mat.at(row1-1).at(col2);
        } catch (out_of_range const& exp) {}
        try {
            rightbtm = sum_mat.at(row2).at(col2);
        } catch (out_of_range const& exp) {}
        int res = rightbtm - leftbtm - rightup + leftup;
        
        
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
