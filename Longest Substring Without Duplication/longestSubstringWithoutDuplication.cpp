using namespace std;
//O(n) time | O(min(n,a)) space where a is the maxlength of the resulting substring
string longestSubstringWithoutDuplication(string str) {
  unordered_map<char,int> uMap;
	int idx = 0;
	int maxLength = 1;
	int startMax = 0;
	int startIdxNewSubSet = 0;
	while(idx < str.size()){
		auto it = uMap.find(str[idx]);
		if(it!=uMap.end()){
			idx = it->second+1;
			if(uMap.size()>maxLength){
				maxLength = uMap.size();
				startMax = startIdxNewSubSet;
			}
			startIdxNewSubSet = it->second+1;
			uMap = {};
		}else{
			uMap[str[idx]] = idx;
			idx++;
		}
	}
	if(uMap.size()>maxLength){
			maxLength = uMap.size();
			startMax = startIdxNewSubSet;
	}
  return str.substr(startMax,maxLength);
}
