using namespace std;
#include <string>
void isPalindrome(string str, int leftIdx, int rightIdx, string &max){
	while(leftIdx >= 0 && rightIdx < str.size()){
		if(str[leftIdx] != str[rightIdx]){
			break ;
		}
		leftIdx--;
		rightIdx++;
	}
	leftIdx++;
	rightIdx--;
	if(leftIdx >= 0 && rightIdx < str.size()){
		if(rightIdx - leftIdx + 1 > max.size()){
			max = str.substr(leftIdx, rightIdx - leftIdx + 1);
		}
	}
}
string longestPalindromicSubstring(string str) {
  // Write your code here.
	if(str.size() == 0){
		return "";
	}else{
		string max = "";
		for(int i = 0 ; i < str.size() ; i++){
			cout<<i<<endl;
			isPalindrome(str, i-1, i+1, max);
			isPalindrome(str, i, i+1, max);
		}
		if(max == ""){
			return str.substr(0,1);
		}
		return max;
	}
}
