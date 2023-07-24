class NumMatrix {
public:
    int rowSum[200][200];   //rowIdx,0~colIdx

    NumMatrix(vector<vector<int>>& matrix) {
        //init
        int row = matrix.size();
        int col = matrix[0].size();
        for(int i=0;i<row;i++){
            //calSum
            rowSum[i][0] = matrix[i][0];
            for(int j=1;j<col;j++)
                rowSum[i][j] = rowSum[i][j-1]+matrix[i][j];
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i=row1;i<=row2;i++){
            if(col1==0) sum+=rowSum[i][col2];
            else sum += (rowSum[i][col2]-rowSum[i][col1-1]);
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
