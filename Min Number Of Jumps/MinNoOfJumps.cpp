#include <vector>
#include <climits>
using namespace std;
//brute force 
// void helper(vector<int> array, int &min, int idx, int jumps){
// 	if(idx >= array.size()-1){
// 		if(min > jumps){
// 			min = jumps;
// 		}
// 		return;
// 	}else{
// 		if(array[idx] == 1){
// 			helper(array, min, idx+1, jumps+1);
// 		}else{
// 			for(int i = 1; i <=array[idx]; i++){
// 				helper(array, min, idx+i, jumps+1);
// 			}
// 		}
// 	}
// }

int minNumberOfJumps(vector<int> array) {
	// int min = INT_MAX;
	// helper(array, min, 0, 0);
	//O(n^2) time | O(n) space
	vector<int> jumps(array.size(), INT_MAX);
	jumps[0] = 0;
	for(int i = 1 ; i < array.size() ; i++){
		for(int j = 0; j < i; j++){
			if(array[j]+j >= i){
				jumps[i] = std::min(jumps[i],jumps[j]+1);
			}
		}
	}
  return jumps[array.size()-1];
}
