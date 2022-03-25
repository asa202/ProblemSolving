#include <vector>
using namespace std;
//my own solution without help O(n*2^n) time and space
int vectorWeightSum(vector<vector<int>> items, vector<int> current){
	int sum = 0;
	for(int i = 0; i < current.size(); i++){
		sum+=items[current[i]][1];
	}
	return sum;
}
int vectorValueSum(vector<vector<int>> items, vector<int> current){
	int sum = 0;
	for(int i = 0; i < current.size(); i++){
		sum+=items[current[i]][0];
	}
	return sum;
}
vector<vector<int>> knapsackProblem(vector<vector<int>> items, int capacity) {
	vector<vector<int>> permutations= {{}};
	for(int i = 0 ; i < items.size() ; i++){
		int size = permutations.size();
		for(int j = 0 ; j < size ;j++){
			vector<int> current = permutations[j];
			current.push_back(i);
			if(vectorWeightSum(items,current) <= capacity){
				permutations.push_back(current);
			}
		}
	}
	int max = 0;
	vector<int> ret = {};
	for(auto it: permutations){
		int currSum = vectorValueSum(items,it);
		if(currSum > max){
			max = currSum;
			ret = it;
		}
	}
  return {
      {max},   // total value
      ret, // item indices
  };
}
