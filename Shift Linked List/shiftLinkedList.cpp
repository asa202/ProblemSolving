using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value) {
    this->value = value;
    next = nullptr;
  }
};

LinkedList *shiftLinkedList(LinkedList *head, int k) {
  int length = 0;
	LinkedList *temp = head;
	while(temp){
		temp = temp->next;
		length++;
	}
	bool negative = k < 0? true:false;
	k = abs(k);
	k = k > length ? k%length : k;
	if(negative){
		k = length-k;
	}
	temp = head;
	while(k>0){
		temp = temp->next;
		k--;
	}
	LinkedList * temp2 = head;
	while(temp && temp->next){
		temp2 = temp2->next;
		temp = temp->next;
	}
	if(temp){
		temp->next = head;
		head = temp2->next;
		temp2->next = nullptr;
	}
  return head;
}
