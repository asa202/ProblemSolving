#include <vector>
using namespace std;

vector<vector<int>> fourNumberSum(vector<int> array, int targetSum) {
  // Write your code here.
	vector<vector<int>> twoSumArray;
	vector<pair<bool,vector<int>>> ret {};
	for(int i = 0; i < array.size() ; i++){
		for(int j = i+1; j < array.size() ; j++){
				vector<int> twoArray{array[i],array[j]};
				twoSumArray.push_back(twoArray);
			}
		}
	for(int i = 0; i < twoSumArray.size() ; i++){
		for(int j = i+1; j < twoSumArray.size() ; j++){
			//cout<<twoSumArray[i][0]<<","<<twoSumArray[i][1]<<","<<twoSumArray[j][0]<<","<<twoSumArray[j][1]<<endl;
			if((twoSumArray[i][0] != twoSumArray[j][0]) && (twoSumArray[i][1] != twoSumArray[j][0])
				 && ( twoSumArray[i][0]!= twoSumArray[j][1]) && ( twoSumArray[i][1]!= twoSumArray[j][1])){
					if(twoSumArray[i][0]+twoSumArray[i][1]+twoSumArray[j][0]+twoSumArray[j][1] == targetSum){
						vector<int> temp {twoSumArray[i][0],twoSumArray[i][1],twoSumArray[j][0],twoSumArray[j][1]};
						pair<bool,vector<int>> p = make_pair(false, temp);
						ret.push_back(p);
					}
			}
		}
	}
	vector<vector<int>> retHelper{};
	for(int i = 0; i < ret.size() ; i++){
		if(!ret[i].first){
			vector<int> temp = ret[i].second;
			retHelper.push_back(temp);
			ret[i].first = true;
			unordered_set<int> setHelper{temp[0],temp[1],temp[2],temp[3]};
			for(int j = 0; j < ret.size() ; j++){
				if(!ret[j].first){
					vector<int> temp2 = ret[j].second;
					if(((setHelper.find(temp2[0])!=setHelper.end())&&
						(setHelper.find(temp2[1])!=setHelper.end()))&&
						(setHelper.find(temp2[2])!=setHelper.end())){
						ret[j].first = true;
					}
				}
			}
		}
	}
	
  return retHelper;
}
