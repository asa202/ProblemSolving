#include <vector>
using namespace std;
//the approach I want to apply here is maximize the value of a & c
//then minimize the value of b&d , store them & see which one satisfies a<b<c<d
// bad approach saw hint suggested O(n) is possible
//should have seen that if its O(n) then have to deal with a single variable at one time
// so first find maximum of a at each index, store it then move to a-b and soon
int maximizeExpression(vector<int> array) {
	if(array.size() < 4)
		return 0;
  
	vector<int> maxAtEachIndex(array.size(), INT_MIN);
	int max = INT_MIN;
	for(int a = 0; a < array.size()-3 ; a++){
		if(array[a]>max){
			max = array[a];
		}
		maxAtEachIndex[a] = max;
	}
	max = INT_MIN;
	vector<int> maxesAB(array.size(), INT_MIN);
	for(int b = 1; b < array.size()-2; b++){
		if(maxAtEachIndex[b-1] - array[b] > max){
			max = maxAtEachIndex[b-1] - array[b];
		}
		maxesAB[b] = max;
	}
	max = INT_MIN;
	vector<int> maxesABC(array.size(), INT_MIN);
	for(int c = 2; c < array.size()-1; c++){
		if(maxesAB[c-1] + array[c] > max){
			max = maxesAB[c-1] + array[c];
		}
		maxesABC[c] = max;
	}
	max = INT_MIN;
	vector<int> maxesABCD(array.size(), INT_MIN);
	for(int d = 3; d < array.size(); d++){
		if(maxesABC[d-1] - array[d] > max){
			max = maxesABC[d-1] - array[d];
		}
		maxesABCD[d] = max;
	}
  return maxesABCD[array.size()-1];
}
