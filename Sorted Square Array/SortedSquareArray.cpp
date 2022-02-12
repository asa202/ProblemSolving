#include <vector>
using namespace std;

vector<int> sortedSquaredArray(vector<int> array) {
  int j = array.size()-1;
	int k = array.size()-1;
	vector<int> ret(array.size());
	for(int i = 0; i != j ;){
		int i_val = array[i]*array[i];
		int j_val = array[j]*array[j];
		if(i_val < j_val){
			ret[k]= j_val;
			k--;
			j--;
		}
		else{
			ret[k]= i_val;
			k--;
			i++;
		}
	}
	ret[k]=array[j]*array[j];
	return ret;
}
