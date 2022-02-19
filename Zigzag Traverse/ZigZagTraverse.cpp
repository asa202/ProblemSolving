#include <vector>

using namespace std;

vector<int> zigzagTraverse(vector<vector<int>> array) {
  // Write your code here.
	if(array.size() == 0){
		return {};
	}
	vector<int> ret{};
	int counter = 1;
	int level = 0;
	int row = 0 ; int col = 0; bool flagRow = false ; bool flagCol = false;
	ret.push_back(array[0][0]);
	while(counter!= array.size()*array[0].size()){
		if(flagRow){
			row++;col--;
			if(row == level){
				flagRow = false;
			}
		}
		else if(flagCol){
			col++;row--;
			if(col == level){
				flagCol = false;
			}
		}
		else{
			if(row == level){
				row++;flagCol = true;
			}else{
				col++; flagRow = true;
			}
			level++;
		}
		
		if(row >= 0 && row < array.size()){
			if(col >= 0 && col < array[0].size()){
				ret.push_back(array[row][col]);counter++;
			}
		}
	}
  return ret;
}
