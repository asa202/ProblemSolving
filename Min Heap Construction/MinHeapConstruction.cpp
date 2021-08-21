#include <vector>
using namespace std;

// Do not edit the class below except for the buildHeap,
// siftDown, siftUp, peek, remove, and insert methods.
// Feel free to add new properties and methods to the class.
class MinHeap {
public:
  vector<int> heap;

  MinHeap(vector<int> vector) { heap = buildHeap(vector); }
//commented out:O(n log n) time and O(n) space
	//O(n) and O(1)
  vector<int> buildHeap(vector<int> &vector) {
    // Write your code here.
		// for(int i:vector){
		// 	insert(i);
		// }
		// return heap;
		int possibleLastParentIdx = (vector.size()-2)/2;
		for(int currentIdx = possibleLastParentIdx; currentIdx >=0; currentIdx--){
			siftDown(currentIdx, vector.size()-1,vector);
		}
		return vector;
  }
	void swap(int currentIdx, int swapIdx, vector<int> &heap){
			int temp = heap[currentIdx];
			heap[currentIdx] = heap[swapIdx];
			heap[swapIdx] = temp;
		return;
	}
  void siftDown(int currentIdx, int endIdx, vector<int> &heap) {
    // Write your code here.
		int leftChildIdx = (2*currentIdx)+1;
		int rightChildIdx = (2*currentIdx)+2;
		while(leftChildIdx <= endIdx){
			if(rightChildIdx>endIdx){
				rightChildIdx = leftChildIdx;
			}
			int swapIdx = heap[leftChildIdx] < heap[rightChildIdx]? leftChildIdx : rightChildIdx;
			if(heap[currentIdx] > heap[swapIdx]){
				swap(currentIdx, swapIdx, heap);
				currentIdx = swapIdx;
				leftChildIdx = (2*currentIdx)+1;
				rightChildIdx = (2*currentIdx)+2;
			}else{
				return;
			}
		}
  }

  void siftUp(int currentIdx, vector<int> &heap) {
		int parentIdx = (currentIdx-1)/2;
		while(heap[parentIdx] > heap[currentIdx] && currentIdx > 0){
			swap(currentIdx, parentIdx, heap);
			currentIdx = parentIdx;
			parentIdx = (currentIdx -1)/2;
		}
	}

  int peek() {
    return heap.size()>0?heap[0]:-1;
  }

  int remove() {
		swap(0,heap.size()-1,heap);
		int ret = heap.back();
		heap.pop_back();
		siftDown(0,heap.size()-1,heap);
    return ret;
  }

  void insert(int value) {
		heap.push_back(value);
		int currentIdx = heap.size()-1;
		siftUp(currentIdx, heap);
  }
};
