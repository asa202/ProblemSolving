#include <vector>
using namespace std;

vector<int> largestRange(vector<int> array) {
  // Write your code here.
	unordered_map<int, bool> helperMap;
	for(int i : array){
		helperMap[i] = false;
	}
	int longest = 0;
	vector<int> ret {};
	int first , last;
	for(auto& it: helperMap){
		if(!it.second){
			first = last = it.first;
			it.second = true;
			int len = 1;
			while(helperMap.find(first - 1) != helperMap.end()){
				first -= 1;
				len++;
				helperMap[first] = true;
			}
			while(helperMap.find(last + 1) != helperMap.end()){
				last += 1;
				len++;
				helperMap[last] = true;
			}
			if(len > longest){
				longest = len;
				ret = {first,last};
			}
		}
	}
  return ret;
}
