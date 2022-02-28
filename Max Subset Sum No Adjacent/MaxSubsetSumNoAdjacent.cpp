#include <vector>
#include <algorithm> 

using namespace std;
//O(n) time | constant space
int maxSubsetSumNoAdjacent(vector<int> array) {
  // Write your code here.
	if(array.size() == 0) return 0;
	int max = 0;
	int previousMax = array[0];
	for(int i = 2; i < array.size(); i++){
		max = array[i]+ previousMax;
		array[i] = max;
		previousMax = std::max(array[i-1],array[i-2]);
	}
	max = std::max(array[array.size()-1],array[array.size()-2]);
  return max;
}
