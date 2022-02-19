using namespace std;
// O(n) time and constant space
bool isMonotonic(vector<int> array) {
  // Write your code here.
	bool flag_in = false;
	bool flag_dec = false;
	if(array.size() <= 1){
		return true;
	}
	for(int i = 0 ; i <= array.size()-2 ; i++){
		if(array[i] > array[i+1]){
			if(flag_in == false){
				flag_dec = true;
			}
			else{
				return false;
			}
		}
		else if(array[i] < array[i+1]){
			if(flag_dec == false){
				flag_in = true;
			}
			else{
				return false;
			}
		}
	}
  return true;
}
