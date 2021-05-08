#include <vector>

using namespace std;
//O(n^2) time | O(d) space
int getNextSmaller(int rootIdx, vector<int> arr, int min){
	int left = rootIdx + 1;
	while(left < arr.size()){
		if(arr[left] < arr[rootIdx] && arr[left] >= min){
			return left;
		}
			left++;
		}
	return -1;
}

int getGreaterOrEqual(int rootIdx, vector<int> arr, int max){
	int right = rootIdx + 1;
		while(right < arr.size()){
			if(arr[right] >= arr[rootIdx] && arr[right] < max){
				return right;
			}
			right++;
		}
	return -1;
}
bool helper(vector<int> arr1,vector<int> arr2, int rootIdx1, int rootIdx2, int min , int max ){
	if(rootIdx1 == -1 || rootIdx2 == -1){
		return rootIdx1 == rootIdx2;
	}
	if(arr1[rootIdx1] == arr2[rootIdx2]){
		int left1 = getNextSmaller(rootIdx1,arr1, min);
		int left2 = getNextSmaller(rootIdx2,arr2, min);
		int right1 = getGreaterOrEqual(rootIdx1,arr1, max);
		int right2 = getGreaterOrEqual(rootIdx2,arr2, max);
			
		bool leftAreSames = helper(arr1, arr2, left1, left2, min, arr1[rootIdx1]);
		
		bool rightAreSames = helper(arr1, arr2, right1, right2, arr2[rootIdx2], max);
		
		return leftAreSames && rightAreSames ;
	}
	return false;
}

bool sameBsts(vector<int> arrayOne, vector<int> arrayTwo) {
  return helper(arrayOne, arrayTwo, 0, 0, INT_MIN, INT_MAX);
}
