#include <vector>

using namespace std;

vector<int> moveElementToEnd(vector<int> array, int toMove) {
	int j = array.size()-1;
	for(int i = 0 ; i < j ; ){
		if(array[j] == toMove){
			j--;
		}
		else if(array[i] != toMove){
			i++;
		}else{
			swap(array[i],array[j]);
			i++;j--;
		}
	}
  return array;
}
