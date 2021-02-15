#include <vector>

using namespace std;

vector<int> arrayOfProducts(vector<int> array) {
  vector<int> left(array.size(),1);
	vector<int> right(array.size(),1);
	int leftP = 1;
	int rightP = 1;
	for(int i = 0 ; i< array.size() ;i++){
		left[i] = leftP;
		leftP *= array[i];
	}
	for(int i = array.size()-1 ; i >=0 ;i--){
		right[i] = rightP;
		rightP *= array[i];
	}
	for(int i = 0 ; i< array.size() ;i++){
		array[i] = left[i]*right[i];
	}
  return array;
}
