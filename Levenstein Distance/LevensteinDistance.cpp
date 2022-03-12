using namespace std;
//O(nm) time |O(min(n,m))space
int levenshteinDistance(string str1, string str2) {
  // Write your code here.
	string larger = str1.size() > str2.size()? str1 : str2;
	string smaller = str1.size() <= str2.size()? str1: str2;
	vector<int> helper(smaller.size()+1);
	helper[0] = 0;
	std::iota(helper.begin()+1, helper.end(), 1);
	if(smaller.size() == 0){
		return larger.size();
	}
	int previous = helper[helper.size()-1];
	int diagonal = 0;
	for(int i = 0; i < larger.size(); i++){
		diagonal = i;
		for(int j = 0; j < smaller.size(); j++){
			if(smaller[j] != larger[i]){
				previous = 1+min(previous, min(diagonal, helper[j+1]));
			}else{
				previous = diagonal;
			}
			diagonal = helper[j+1];
			helper[j+1] = previous;
		}
	}
  return previous;
}
