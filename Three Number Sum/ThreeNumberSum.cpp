#include <vector>
using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
  // Write your code here.
	sort(array.begin(),array.end());
	vector<vector<int>> array2d;
	for(int i = 0 ; i < array.size() ; i++){
		int first = array[i];
		int left = i + 1;
		int right = array.size() - 1;
		while(left < right){
			if((first + array[left] + array[right]) == targetSum){
				array2d.push_back({first, array[left++], array[right--]});
			}
			else if((first + array[left] + array[right]) < targetSum){
				left++;
			}
			else {
				right--;
			}
			
		}
	}
	
	
	
  return array2d;
}
