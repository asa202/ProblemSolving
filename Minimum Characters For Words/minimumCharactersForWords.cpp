#include <vector>
using namespace std;

vector<char> minimumCharactersForWords(vector<string> words) {
  // Write your code here.
	unordered_map<char,int> globalMap;
	for(auto word:words){
		unordered_map<char,int> localMap;
		for(char ch:word){
			localMap[ch]++;
		}
		for(auto it: localMap){
			unordered_map<char,int>::const_iterator got = globalMap.find(it.first);
			if(got == globalMap.end()){
				globalMap[it.first] = it.second;
			}else{
				int update = it.second > got->second ? it.second:got->second;
				globalMap[it.first] = update;
			}
		}
	}
	vector<char> ret{};
	for(auto it:globalMap){
		for(int i = 1 ; i <= it.second; i++){
			ret.push_back(it.first);
		}
	}
  return ret;
}