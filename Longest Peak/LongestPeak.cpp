using namespace std;

int longestPeak(vector<int> array) {
  // Write your code here.
	int max = 0;
	int counter = 1;
	if(array.size() < 3){
		return 0;
	}
	for(int i = 0; i<array.size()-1; ){
		while( i < array.size()-1 && array[i+1]>array[i]){
			counter++;
			i++;
		}
		if(i < array.size()-1 && array[i+1] < array[i] && counter != 1){
			while(i < array.size()-1 && array[i+1] < array[i]){
				counter++;
				i++;
			}
			if(counter > max){
				max = counter;
			}
			counter = 1;
		}else{
			counter = 1;
			i++;
		}
	}
  return max;
}
