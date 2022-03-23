#include <vector>
using namespace std;
//O(n) time | O(n) space
int waterArea(vector<int> heights) {
  vector<int> maxes(heights.size(), 0);
	int leftMax = 0;
	for(int i = 0; i < heights.size() ; i++){
		maxes[i] = leftMax;
		leftMax = max(leftMax, heights[i]);
	}
	int rightMax = 0;
	for(int i = heights.size()-1 ; i >= 0 ; i--){
		int waterLevel = min(rightMax,maxes[i]);
		if(waterLevel > heights[i]){
			maxes[i] = waterLevel - heights[i];
		}else{
			maxes[i] = 0;
		}
		rightMax = max(rightMax, heights[i]);
	}
	int waterDots = 0;
	for(int i: maxes){
		waterDots += i;
	}
  return waterDots;
}
