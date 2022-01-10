#include <vector>
using namespace std;

string tournamentWinner(vector<vector<string>> competitions,
                        vector<int> results) {
  // Write your code here.
	unordered_map<string,int> pointsMap;
	int max = 0;
	string winner = "";
	for(int i = 0; i < competitions.size(); i++){
		if(results[i] == 0 ){
			pointsMap[competitions[i][1]] = pointsMap[competitions[i][1]]+3; 
			if(max < pointsMap[competitions[i][1]]){
				winner = competitions[i][1];
				max = pointsMap[competitions[i][1]];
			}
		}else{
			pointsMap[competitions[i][0]] = pointsMap[competitions[i][0]]+3; 
			if(max < pointsMap[competitions[i][0]]){
				winner = competitions[i][0];
				max = pointsMap[competitions[i][0]];
			}
		}
	}
	return winner;
}
