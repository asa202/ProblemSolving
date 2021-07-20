#include <vector>
using namespace std;
void fillMap(unordered_map<char,vector<int>> &map,const string &str){
	for(int i = 0; i < str.size(); i++){
		map[str[i]].push_back(i);
	}
}

vector<char> longestCommonSubsequence(string str1, string str2) {
	string shorter = str1.size() > str2.size() ? str2 :str1;
	string longer =  str1.size() > str2.size() ? str1 :str2;
	unordered_map<char,vector<int>> target;
	fillMap(target, longer);
	vector<char> reqVec{};
	for(int i = shorter.size()-1; i >= 0; i --){
		int targetIndex = INT_MAX;
		vector<char> currVec{};
		for(int j = i ; j >= 0; j--){
			if(target.find(shorter[j])!= target.end()){
				for(int k = target[shorter[j]].size()-1 ; k >= 0 ; k--){
					if(target[shorter[j]][k] < targetIndex){
						currVec.push_back(shorter[j]);
						targetIndex = target[shorter[j]][k];
						break;
					}
				}
			}
		}
		if(currVec.size() > reqVec.size()){
			reqVec = currVec;
		}
	}
	std::reverse(reqVec.begin(),reqVec.end()); 
  return reqVec;
}
