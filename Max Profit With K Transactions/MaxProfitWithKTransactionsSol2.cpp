#include <vector>
using namespace std;
//O(nk) time | O(n) space
int maxProfitWithKTransactions(vector<int> prices, int k) {
	vector<int> profitsFromPrevious(prices.size(), 0);
	vector<int> profits(prices.size(), 0);
	if(prices.size() == 0|| k == 0) return 0;
	for(int i = 1; i <= k; i++){
		int max = INT_MIN;
		for(int j = 1; j < prices.size(); j++){
			max = std::max(max, -prices[j-1]+profitsFromPrevious[j-1]);
			int v1 = profits[j-1];
			int v2 = prices[j] + max;
			profits[j] = std::max(v1,v2);
		}
		profitsFromPrevious = profits;
		profits[0] = 0;
	}
  return profits[prices.size()-1];
}