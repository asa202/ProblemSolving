#include <vector>
using namespace std;

vector<int> nextGreaterElement(vector<int> array) {
  // Write your code here.
	if(array.size() == 0){
		return {};
	}
	vector<int> ret(array.size(), 0);
	vector<int> helper;
	vector<int> indices;
	int idx = array.size()-1;
	while(idx >= 0){
		if(helper.size() == 0){
			indices.push_back(idx);
			helper.push_back(array[idx]);
			idx--;
		}else{
			if(array[idx] < helper.back()){
				ret[idx] = helper.back();
				helper.push_back(array[idx]);
				idx--;
			}else{
				helper.pop_back();
			}
		}
	}
	for(int i = 0; i < indices.size() ;){
		if(array[indices[i]] < helper.back() ){
			ret[indices[i]] = helper.back();
			i++;
		}else{
			if(helper.size() == 0){
				ret[indices[i]] = -1;
				i++;
			}else{
				helper.pop_back();;
			}
		}
	}
  return ret;
}
