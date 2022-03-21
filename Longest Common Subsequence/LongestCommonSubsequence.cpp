#include <vector>
using namespace std;
//O(n,m) time and space
vector<char> longestCommonSubsequence(string str1, string str2) {
  vector<vector<int>> TwoDArray(str1.length()+1, vector<int> (str2.length()+1, 0));
	for(int i = 1; i < str1.length()+1 ; i++){
		for(int j = 1; j < str2.length()+1; j++){
			if(str1[i-1] == str2[j-1]){
				TwoDArray[i][j] = TwoDArray[i-1][j-1] + 1;
			}else{
				TwoDArray[i][j] = max(TwoDArray[i-1][j] , TwoDArray[i][j-1]);
			}
		}
	}
	
	// creating lcs from 2d array
	vector<char> req{};
	int currentRow = str1.length() ; int currentCol = str2.length() ;
	while(TwoDArray[currentRow][currentCol]!=0){
		if(str1[currentRow-1] == str2[currentCol-1]){
			req.push_back(str1[currentRow-1]);
			currentRow--;
			currentCol--;
		}else{
			currentRow = TwoDArray[currentRow-1][currentCol] < TwoDArray[currentRow][currentCol-1] ?
				currentRow : currentRow-1 ;
			currentCol = TwoDArray[currentRow-1][currentCol] < TwoDArray[currentRow][currentCol-1] ?
				currentCol-1 : currentCol ;
		}
	}
	std::reverse(req.begin(), req.end());
  return req;
}
 