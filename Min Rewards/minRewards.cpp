#include <vector>
using namespace std;

int minRewards(vector<int> scores) {
  // Write your code here.
	vector<int> helper(scores.size(), 1);
	for(int i = 0 ; i < scores.size()-1 ; i++){
		if(scores[i+1] > scores [i]){
			helper[i+1] = helper[i]+1;
		}
	}
	for(int i = scores.size()-1 ; i > 0 ; i--){
		if(scores[i] < scores [i-1]){
			if(helper[i-1] <= helper[i]){
				helper[i-1] = helper[i]+1;
			}
		}
	}
	int total = 0;
	for(int i:helper){
		total+=i;
	}
  return total;
}
