#include <vector>
#include <string>
using namespace std;
bool check(string string, int len, int index, std::string &str){
	if(index + len > string.size()){
		return false;
	}
	str = string.substr(index, len);
	index +=len;
	if(stoi(str) >= 0 && stoi(str) <= 255){
			if((str.size()>1 && str[0] != '0')|| str.size() == 1){
				return true;
			}
		}
	return false;
}
vector<string> validIPAddresses(string string) {
  // Write your code here.
	vector<std::string> ret = {};
	for(int i = 1 ; i < 4 ; i++){
		int index = 0;
		std::string one = "";
		if(check(string, i, index, one)){
			for(int j = 1 ; j < 4 ; j++){
				index = i;
				std::string two = "";
				if(check(string, j, index, two)){
					for(int k = 1 ; k < 4; k++){
						index = i+j;
						std::string three = "";
						if(check(string, k, index, three)){
							for(int l = 1 ; l < 4; l++){
								index = i+j+k;
								std::string four = "";
								if(check(string, l, index, four)){
									if(index+l == string.size()){
										std::string finalStr = one+"."+two+"."+three+"."+four;
										ret.push_back(finalStr);
									}
								}
							}
						}
					}
				}
			}
		}
	}
  return ret;
}
