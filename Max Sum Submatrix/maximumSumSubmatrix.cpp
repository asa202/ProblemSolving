#include <vector>
using namespace std;
//O(nm) time |O(nm) space
int sumCol(int row, int col,const vector<vector<int>> &matrix, int size){
	int sum = 0;
	for(int i = row; i < row+size ; i++){
		sum+=matrix[i][col];
	}
	return sum;
}
int sumRowCarry(int row, int col,const vector<vector<int>> &rows, int size){
	int sum = 0;
	for(int j = col+1 ; j < col+size ; j++ ){
		sum+=rows[row][j];
	}
	return sum;
}
int maximumSumSubmatrix(vector<vector<int>> matrix, int size) {
	vector<vector<int>> rows;
	for(int i = 0; i+size-1 < matrix.size() ; i++){
		vector<int> curr{};
		for(int j = 0 ; j < matrix[0].size() ; j++ ){
			if(i==0){
				int colSum = sumCol( i, j, matrix, size);
				curr.push_back(colSum);
			}else{
				vector<int> prev = rows.back();
				int colSum = prev[j] - matrix[i-1][j] + matrix[i+size-1][j];
				curr.push_back(colSum);
			}
		}
		rows.push_back(curr);
	}
	int prev = 0;
	int max = INT_MIN;
	for(int i = 0; i < rows.size() ; i++){
		for(int j = 0; j+size-1 < rows[0].size(); j++){
			int matrixSum = 0;
			int carry = sumRowCarry(i,j,rows,size);
			if(j == 0){
				matrixSum = rows[i][j] + carry;
			}else{
				matrixSum = prev + rows[i][j+size-1];
			}
			prev = carry;
			if(matrixSum > max){
				max = matrixSum;
			}
		}
	}
  return max;
}
