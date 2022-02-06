#include <vector>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> words) {
  // Write your code here.
	vector<vector<string>> ret{};
	unordered_map<string,vector<string>> anagrams;
	for(auto word: words){
		string wordCopy = word;
		sort(wordCopy.begin(),wordCopy.end());
		anagrams[wordCopy].push_back(word);
	}
	for(auto it: anagrams){
		ret.push_back(it.second);
	}
  return ret;
}
