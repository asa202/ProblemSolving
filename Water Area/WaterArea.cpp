#include <vector>
#include <stdlib.h>     
using namespace std;
//O(n^2) time and O(n) space
int waterArea(vector<int> heights) {
  vector<int> waterContributions(heights.size(), 0);
	int maxHeight = 0;
	int maxHeightIdx = 0;
	for(int i = 0; i < heights.size() ; i++){
		if(heights[i]>0){
			int alreadyCounted = 0;
			for(int j = i-1 ; j > maxHeightIdx; j--){
				if(heights[j]!=0){
					int height = heights[i] < heights[j] ? heights[i] : heights[j];
					alreadyCounted += height;
					if(j-1-maxHeightIdx > 0){
						int waterDotsJ = ((j-1-maxHeightIdx)*(height));
						if(waterDotsJ < waterContributions[j]){
							alreadyCounted += waterDotsJ;
						}else{
							alreadyCounted += waterContributions[j];
						}
					}
					if(heights[j] > heights[i]){
						break;
					}
				}
			}
			int level = heights[i] < maxHeight ? heights[i] : maxHeight;
			int width = i - maxHeightIdx - 1;
			int totalWaterDots = level*width;
			int currTowerContribution = totalWaterDots - alreadyCounted;
			waterContributions[i] = currTowerContribution;
			cout<<heights[i]<<" : "<< waterContributions[i]<<endl;
		}
		if(maxHeight <= heights[i]){
			maxHeight = heights[i];
			maxHeightIdx = i;
		}
	}
	int waterDots = 0;
	for(int i: waterContributions){
		waterDots+=i;
	}
  return waterDots;
}
