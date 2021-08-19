#include <vector>
using namespace std;
//O(nk) time | O(nk) time
int maxProfitWithKTransactions(vector<int> prices, int k) {
	vector<vector<int>> profits (k+1,vector<int>(prices.size(), 0));
	if(prices.size() == 0|| k == 0) return 0;
	for(int i = 1; i <= k; i++){
		int max = INT_MIN;
		for(int j = 1; j < prices.size(); j++){
			max = std::max(max, -prices[j-1]+profits[i-1][j-1]);
			int v1 = profits[i][j-1];
			int v2 = prices[j] + max;
			profits[i][j] = std::max(v1,v2);
		}
	}
  return profits[k][prices.size()-1];
}
