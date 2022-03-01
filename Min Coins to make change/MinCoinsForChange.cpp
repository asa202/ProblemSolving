#include <vector>
using namespace std;
//O(nd) time | O(n) space
int minNumberOfCoinsForChange(int n, vector<int> denoms) {
  vector<int> numberOfCoins(n+1, INT_MAX);
	numberOfCoins[0] = 0;
	for(int denom : denoms){
		for(int i = 0 ; i < n+1 ;i++){
			if(denom <= i){
				if(numberOfCoins[i-denom] != INT_MAX){
					if(numberOfCoins[i] > numberOfCoins[i-denom]+1){
						numberOfCoins[i] = numberOfCoins[i-denom]+1;
					}
				}
			}
		}
	}
  return numberOfCoins[n]!= INT_MAX?numberOfCoins[n]:-1 ;
}
