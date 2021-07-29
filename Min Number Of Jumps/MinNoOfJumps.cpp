#include <vector>
using namespace std;
//O(n^2) time
int minNumberOfJumps(vector<int> array) {
	if(array.size() == 1){
		return 0;
	}
	int min = 1; 
	for(int i = 0; i < array.size(); ){
		int currentJump = i+array[i];int nextIdx = i;
		if(currentJump >= array.size()-1){
			return min;
		}
		for(int j = i+1; j <= i+array[i]; j++){
			if(j+array[j] > currentJump){
				currentJump = j+array[j];
				nextIdx = j;
			}
		}
		i = nextIdx;
		if(nextIdx == array.size()-1){
			return min;
		}
		min++;
		if(currentJump >= array.size()-1){
			return min;
		}
	}
  return min;
}
