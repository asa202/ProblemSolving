#include <vector>
#include <limits>
using namespace std;
struct Item{
	int vertex, distance;
};
class MinHeap{
	public:
	vector<Item> heap; 
	unordered_map<int, int> vertexMap;
	
	MinHeap(vector<Item> array){
		for(auto item: array){
			vertexMap[item.vertex] = item.vertex;
		}
		heap = buildHeap(array);
	
	}
	
	vector<Item> buildHeap(vector<Item> &array) {
		int firstParentIdx = (array.size() - 2)/2;
    for(int currentIdx = firstParentIdx + 1 ; currentIdx >= 0 ; currentIdx--){
			siftDown(currentIdx, array.size()-1, array);
		}
		return array;
  }
	
	bool isEmpty(){ return heap.size() == 0; }
	//O(logn) time| O(1) space
  void siftDown(int currentIdx, int endIdx, vector<Item> &heap) {
		int childOneIdx = currentIdx * 2 + 1;
		while(childOneIdx <= endIdx){
			int childTwoIdx = currentIdx * 2+2 <= endIdx ? currentIdx * 2+2 : -1;
			int idxToSwap;
			if(childTwoIdx != -1 && heap[childTwoIdx].distance < heap[childOneIdx].distance){
				idxToSwap = childTwoIdx;
			}else{
				idxToSwap = childOneIdx;
			}
			if(heap[idxToSwap].distance < heap[currentIdx].distance){
				swap(currentIdx, idxToSwap);
				currentIdx = idxToSwap;
				childOneIdx = currentIdx * 2 +1;
			} else {
				return;
			}
		}
	}

  void siftUp(int currentIdx) {
    int parentIdx = (currentIdx-1)/2;
		while(currentIdx > 0 && heap[currentIdx].distance < heap[parentIdx].distance){
			swap(currentIdx, parentIdx);
			currentIdx = parentIdx;
			parentIdx = (currentIdx-1)/2;
		}
  }
	
  Item remove() {
		swap(0,heap.size()-1);
		auto [vertex, distance] = heap.back();
		heap.pop_back();
		vertexMap.erase(vertex);
		siftDown(0,heap.size()-1, heap); 
    return Item{vertex, distance};
  }
	
	void update(int vertex, int value){
		heap[vertexMap[vertex]] = Item{vertex, value};
		siftUp(vertexMap[vertex]);
	}
	
	void swap(int i, int j){
		vertexMap[heap[i].vertex] = j;
		vertexMap[heap[j].vertex] = i;
		auto temp = heap[i];
		heap[i] = heap[j];
		heap[j] = temp;
	}
};
//O((v+e)*logv)

vector<int> dijkstrasAlgorithm(int start, vector<vector<vector<int>>> edges) {
	int numerOfVertices = edges.size();
	vector<int> minDistances (edges.size(), numeric_limits<int>::max());
	minDistances[start] = 0;
	
	vector<Item> nodes;
	for(int i = 0; i < edges.size(); i++){
		nodes.push_back(Item{i,numeric_limits<int>::max()});
	}
	MinHeap minDistancesHeap(nodes);
	minDistancesHeap.update(start,0);
	
	while(!minDistancesHeap.isEmpty()){
		auto [vertex, currentMinDistance] = minDistancesHeap.remove();
		
		if(currentMinDistance == numeric_limits<int>::max()) {
			break;
		}
		
		for(auto edge: edges[vertex]){
			int destination = edge[0];
			int newDistance = currentMinDistance + edge[1];
			int currDistance = minDistances[destination];
			if(newDistance < currDistance){
				minDistances[destination] = newDistance;
				minDistancesHeap.update(destination,newDistance);
			}
		}
	}
	for(int &i:minDistances){
			if(i==numeric_limits<int>::max()){
				i = -1;
			}
		}
  return minDistances;
}
