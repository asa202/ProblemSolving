#include <vector>
#include <stdlib.h>
using namespace std;

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
  // Write your code here.
	int min ;
	vector<int> ret{arrayOne[0],arrayTwo[0]};
	
	sort(arrayOne.begin(),arrayOne.end());
	sort(arrayTwo.begin(),arrayTwo.end());
	min = abs(arrayOne[0]-arrayTwo[0]);
	int current = 0 ; int parent = 0;int j = 0;
	for(int i = 0 ; i < arrayOne.size() ; i++){
		if(j >= arrayTwo.size()){
			break;
		}
		int left = arrayOne[i];
		int right = arrayTwo[j];
		while(left > right){
			if(j < arrayTwo.size()){
				parent = j++;
			}
			else{
				break;
			}
			right = arrayTwo[j];
			current = j;
		}
		int localMin = abs(arrayOne[i]-arrayTwo[parent]) < abs(arrayOne[i]-arrayTwo[current])
										? abs(arrayOne[i]-arrayTwo[parent]):abs(arrayOne[i]-arrayTwo[current]) ;
		if(localMin == 0 && localMin == abs(arrayOne[i]-arrayTwo[parent])){
			return {left,arrayTwo[parent]};
		}
		else if(localMin == 0){
			return {left,right};
		}
		else if(min > localMin){
			if(localMin == abs(arrayOne[i]-arrayTwo[parent])){
				ret[0]=left;
				ret[1]=arrayTwo[parent];
				min = localMin;
			}
			else{
				ret[0]=left;
				ret[1]=arrayTwo[current];
				min = localMin;
			}
		}
	}
	
	
	// for(int i = 0 ; i < arrayOne.size() ; i++){
	// 		int first = arrayOne[i];
	// 	for(int j = 0 ; j < arrayTwo.size() ; j++){
	// 		int second = arrayTwo[j];
	// 		int diff = abs(first - second);
	// 		if(diff == 0 ){
	// 			return {first,second};
	// 		}
	// 		else if(diff < min){
	// 			ret[0]=first;
	// 			ret[1]=second;
	// 			min = diff;
	// 		}
	// 	}
	// }
	
  return ret;
}
