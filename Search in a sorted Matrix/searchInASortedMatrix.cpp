#include <vector>
using namespace std;

vector<int> searchInSortedMatrix(vector<vector<int>> matrix, int target) {
  // Write your code here.
	int currentRow = 0;
	int currentCol = matrix[0].size()-1;
	while(currentRow < matrix.size() && currentCol >=0){
		if(matrix[currentRow][currentCol] < target){
			currentRow++;
		}
		else if(matrix[currentRow][currentCol] > target){
			currentCol--;
		}else{
			return {currentRow,currentCol};
		}
	}
	
  return {-1,-1};
}
