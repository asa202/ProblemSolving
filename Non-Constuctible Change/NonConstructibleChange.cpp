#include <vector>
using namespace std;

int nonConstructibleChange(vector<int> coins) {
  sort(coins.begin(), coins.end());
	
	int change = 0;
	
	for(int coin : coins){
		if(coin > change + 1){
			return change + 1;
		}
		else{
			change = change + coin;
		}
	}
  return change +1 ;
}
