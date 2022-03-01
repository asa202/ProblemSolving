#include <vector>
using namespace std;
//O(n*d) time |O(n) space : n is the target Value And d is the length of denominations
int numberOfWaysToMakeChange(int n, vector<int> denoms) {
  // Write your code here.
	int count = 0;
	vector<int> ret(n+1,0);
	ret[0] = 1;
	for(int denom : denoms){
		for(int i = 0; i<n+1;i++){
			if(denom <= i){
				ret[i] += ret[i-denom];
			}
		}
	}
	
  return ret[n];
}
