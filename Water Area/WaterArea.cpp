#include <vector>
using namespace std;
//O(n) time | O(1) space
int waterArea(vector<int> heights) {
  // Write your code here.
	if(heights.size() == 0){
		return 0;
	}
	int leftIdx = 0;
	int rightIdx = heights.size()-1;
	int leftMax = heights[leftIdx];
	int rightMax = heights[rightIdx];
	int waterDots = 0;
	while(leftIdx < rightIdx){
		int width = rightIdx - leftIdx - 1;
		if(heights[leftIdx] < heights[rightIdx]){
			leftIdx++;
			leftMax = max(leftMax, heights[leftIdx]);
			waterDots += leftMax - heights[leftIdx];
		}else{
			rightIdx--;
			rightMax = max(rightMax, heights[rightIdx]);
			waterDots += rightMax - heights[rightIdx];
		}
	}
  return waterDots;
}
