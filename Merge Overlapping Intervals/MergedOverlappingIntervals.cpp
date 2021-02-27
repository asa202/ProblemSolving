#include <vector>
using namespace std;

bool mysort(vector<int> i , vector<int> j ){
	return( i[0] < j[0] );
}

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> intervals) {
  // Write your code here.
	if(intervals.size() == 0){
		return {};
	}
	vector<vector<int>> sorted = intervals;
	sort(sorted.begin(), sorted.end(), mysort);
	vector<vector<int>> mergedArray;
	mergedArray.push_back(sorted[0]);
	for(int i = 1; i < intervals.size() ; i++){
		vector<int> back = mergedArray.back();
		if(sorted[i][0] <= back[1]){
			if(back[1] < sorted[i][1]){
				mergedArray.pop_back();
				back[1] = sorted[i][1];
				mergedArray.push_back(back);
			}
		}else{
			mergedArray.push_back(sorted[i]);
		}
	}
  return mergedArray;
}
