#include <vector>
using namespace std;
//O(n^2) time and O(n) space
bool checkIfCanBeStacked(vector<int> base, vector<int> top){
	return base[0] > top[0] && base[1] > top[1] && base[2] > top[2] ;
}
bool sortByHeight(vector<int> v1, vector<int> v2){
	return v1[2] < v2[2];
}

vector<vector<int>> diskStacking(vector<vector<int>> disks) {
 	std::sort(disks.begin(), disks.end(), sortByHeight);
	//to store the indices of previous disks that gives maximum height
	vector<int> tower(disks.size(), -1);
	//to store max tower height achieved with a disc as base
	vector<int> maxHeightTowerAsBase(disks.size(), 0);
	//Initialize max Height at each tower with its own height
	for(int i = 0 ; i < disks.size() ; i++){
		maxHeightTowerAsBase[i] = disks[i][2];
	}
	int maxHeight = 0;
	int baseIndex = -1;
	for(int i = 0; i < disks.size(); i++){
		for(int j = 0; j < i ; j++){
			//check if disk i can have disk j on top
			if(checkIfCanBeStacked(disks[i],disks[j])){
				int combinedHeight = disks[i][2]+maxHeightTowerAsBase[j];
				if(maxHeightTowerAsBase[i] <  combinedHeight){
					maxHeightTowerAsBase[i] = combinedHeight;
					tower[i] = j;
				}
			}
		}
		//keep track of the index of base for that update max height
		if(maxHeightTowerAsBase[i] > maxHeight){
			baseIndex = i;
			maxHeight = maxHeightTowerAsBase[i];
		}
	}
	//might be an empty array
	if(baseIndex == -1){
		return {};
	}
	vector<vector<int>> req{disks[baseIndex]};
	//reconstruction 
	while(tower[baseIndex] != -1){
		int next = tower[baseIndex];
		req.push_back(disks[next]);
		baseIndex = next;
	}
	//reverse to get it in order 
	std::reverse(req.begin(), req.end());
  return req;
}
