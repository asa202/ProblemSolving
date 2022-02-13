#include <vector>
using namespace std;

int firstDuplicateValue(vector<int> array) { 
	for(int i = 0 ; i < array.size() ; i++){
		int val = abs(array[i]);
		if(array[val-1] < 0 )
			return val;
		array[val-1] *=-1;
	}
	return -1; 
}
