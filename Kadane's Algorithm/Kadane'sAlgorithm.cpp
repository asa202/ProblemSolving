#include <vector>
using namespace std;
//O(n) time | O(1) space
int kadanesAlgorithm(vector<int> array) {
  int max = array[0];
	int currSum = array[0];
	for(int i = 1; i < array.size() ; i++){
		currSum = std::max(array[i], array[i]+currSum);
		max = std::max(max, currSum);
	}
  return max;
}
