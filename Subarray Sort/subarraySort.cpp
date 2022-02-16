#include <vector>
using namespace std;

vector<int> subarraySort(vector<int> array) {
  // Write your code here.
	int min = INT_MAX;
	int max = INT_MIN;
	int min_index = -1;
	int max_index = -1;
	bool flag_min = true;
	for(int i = 0; i < array.size()-1; i++){
		if(array[i]>array[i+1]){
			flag_min = false;
			if(array[i+1] < min){
				min = array[i+1];
			}
			if(array[i]> max){
				max = array[i];
			}
		}
	}
	for(int i = 0 ; i < array.size(); i++){
		if(array[i] > min && !flag_min){
			min_index = i;
			flag_min = true;
		}
		if(array[i] < max ){
			max_index = i;
		}
	}
	 return {min_index,max_index};
}
