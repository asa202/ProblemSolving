using namespace std;
string reverseWordsInString(string str) {
  // Write your code here.
	vector<string> helper;
	string current = "";
	for(char ch: str){
		if(ch == ' '){
			if(current != ""){
				helper.push_back(current);
			}
			helper.push_back(" ");
			current = "";
		}else{
			current += ch;
		}
	}
	if(current != ""){
		helper.push_back(current);
	}
	string retString = "";
	while(helper.size()!=0){
		retString += helper.back();
		helper.pop_back();
	}
  return retString;
}
