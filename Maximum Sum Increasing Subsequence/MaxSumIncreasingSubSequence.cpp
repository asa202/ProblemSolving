#include <vector>
using namespace std;
//O(n^2) time | O(n) space
vector<vector<int>> maxSumIncreasingSubsequence(vector<int> array) {
  vector<int> sums(array.size(), INT_MIN);
	vector<int>sequence (array.size(), -1);
	int maxIndex = -1;int max = INT_MIN;
	for(int i = 0 ; i < array.size() ; i++){
		for(int j = 0 ; j < i; j++){
			if( i!=j && array[j] < array[i] && sums[j] > sums[i] && sums[j] > 0){
				sums[i] = sums[j];
				sequence[i] = j;
			}
		}
		if(sums[i] == INT_MIN){
			sums[i] = array[i];
		}else{
			sums[i]+=array[i];
		}
		if(sums[i] > max){
			max = sums[i];
			maxIndex = i;
		}
	}
	vector<int>sequenceR{};
	while(sequence[maxIndex] != -1){
		sequenceR.push_back(array[maxIndex]);
		maxIndex = sequence[maxIndex];
	}
	sequenceR.push_back(array[maxIndex]);
	std::reverse(sequenceR.begin(),sequenceR.end());
  return {
      {max}, // Sum of sequence.
      sequenceR,  // Elements of the sequence.
  };
}
