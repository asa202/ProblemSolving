#include <vector>
using namespace std;
//optimal but using more space see or try to reduce space
vector<int> twoNumberSum(vector<int> array, int targetSum) {
  // Write your code here.
	unordered_set<int> numberAndDifferences;
	int difference;
	for(int i : array){
		difference = targetSum - i;
		if(i == difference){
			if(numberAndDifferences.insert(difference).second == false){
				return {i,i};
			}
		}else{
			if(numberAndDifferences.insert(i).second == false){
				return {i , difference};
			}
			if(numberAndDifferences.insert(difference).second == false){
				return {i , difference};
			}
		}
	}
  return {};
}
