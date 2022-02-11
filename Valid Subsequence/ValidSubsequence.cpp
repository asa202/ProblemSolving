using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
  // Write your code here.
	int len = sequence.size();
	int i = 0;
	for(int j = 0 ; j < array.size() ; j++){
		if(array[j] == sequence[i]){
			i++;
		}
	}
	if(i == len){
		return true;
	}
  return false;
}
