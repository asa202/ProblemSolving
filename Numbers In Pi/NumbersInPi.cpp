#include <vector>
#include <string>
using namespace std;
//O(n^3 + m) time | O(n + m) space
int getMinSpaces(string pi, set<string> numberSet, unordered_map<int,int> *cache, int idx);
int numbersInPi(string pi, vector<string> numbers) {
	//sorting to reduce the number for operations as we will chunk off the max part first
  // std::sort(numbers.begin(), numbers.end(), 
  // [](const string &a,const string &b) {return a.length() < b.length();});
	//above was a bad idea doesn't help
	
	//use a set to store unique string
	set<string> numberSet;
	for(string number: numbers){
		numberSet.insert(number);
	}
	//create a map : convert string to int for fast comparison and use as key and value is the number of strings reuired to create the number
	unordered_map<int,int> cache{};
	for(int i = numbers.size()-1; i >=0 ; i--){
		getMinSpaces(pi, numberSet, &cache, i);
	}
  return cache.at(0) == INT_MAX ? -1 : cache.at(0);
}
int getMinSpaces(string pi, set<string> numberSet, unordered_map<int,int> *cache, int idx){
	if(idx == pi.length()){
		return -1;
	}
	if(cache->find(idx)!=cache->end()){
		return cache->at(idx);
	}
	int minSpaces = INT_MAX;
	for(int i = idx; i < pi.length(); i++){
		string sub = pi.substr(idx, i+1-idx);
		if(numberSet.find(sub)!=numberSet.end()){
			int minSpacesForSuffix = getMinSpaces(pi, numberSet, cache, i+1);
			if(minSpacesForSuffix == INT_MAX ){
				minSpaces = min(minSpaces,minSpacesForSuffix);
			}else{
				minSpaces = min(minSpaces, minSpacesForSuffix+1);
			}
		}
	}
	cache->insert({idx, minSpaces});
	return minSpaces;
}
