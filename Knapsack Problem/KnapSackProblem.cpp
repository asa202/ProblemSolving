#include <vector>
using namespace std;
//O(nc) time | O(nc) space where c is capacity
vector<vector<int>> knapsackProblem(vector<vector<int>> items, int capacity) {
  vector<vector<int>> knapsackValues(items.size()+1, vector<int>(capacity+1, 0));
	for(int i = 1 ; i < items.size()+1 ; i++){
		int currentWeight = items[i-1][1];
		int currentValue = items[i-1][0];
		for(int j = 0; j < capacity + 1; j++){
			if(currentWeight > j){
				knapsackValues[i][j] = knapsackValues[i-1][j];
			}else{
				knapsackValues[i][j] = max(knapsackValues[i-1][j],knapsackValues[i-1][j-currentWeight]+currentValue);
			}
		}
	}
	vector<int> ret{};
	int max = 0;
	int j = capacity;
	for(int i = items.size() ; i > 0 ; ){
		if(knapsackValues[i][j] != knapsackValues[i-1][j]){
			ret.push_back(i-1);
			i = i-1;
			j = j-items[i][1];
			max += items[i][0];
		}
		else if(j==0){
			break;
		}else{
			i = i-1;
		}
	}
  return {
      {max},   // total value
      ret, // item indices
  };
}
