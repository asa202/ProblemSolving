using namespace std;

vector<int> spiralTraverse(vector<vector<int>> array) {
	vector<int>  ret;
  int rowMax = array.size();
	int colMax = array[0].size();
	int rowMin = 0;
	int colMin = 0;
	int counter = 0; 
	bool ColF = false;
	bool DecFR= false;
	bool DecFC = false;
	bool RowF = true;
	bool IncFC = true;
	bool IncFR = true;
	while(counter < array.size()*array[0].size()){
		if(RowF){
			if(IncFR){
				for(int j = colMin; j < colMax ; j++){
					ret.push_back(array[rowMin][j]);
					counter++;
				}
				rowMin+=1;
				IncFR = false;
				DecFR = true;
			}
			else{
				for(int j = colMax-1; j >= colMin ; j--){
					ret.push_back(array[rowMax-1][j]);
					counter++;
				}
				rowMax-=1;
				IncFR = true;
				DecFR = false;
			}
			RowF = false;
			ColF = true;
		}
		else{
			if(IncFC){
				for(int j = rowMin; j < rowMax ; j++){
					ret.push_back(array[j][colMax-1]);
					counter++;
				}
				colMax-=1;
				IncFC = false;
				DecFC = true;
			}
			else{
				for(int j = rowMax-1; j >= rowMin ; j--){
					ret.push_back(array[j][colMin]);
					counter++;
				}
				colMin+=1;
				IncFC = true;
				DecFC = false;
			}
			RowF = true;
			ColF = false;
		}
	}
  return ret;
}
