#include <vector>

using namespace std;

// This is an input class. Do not edit.
class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value) {
    this->value = value;
    next = nullptr;
  }
};
//O(n+m) time | O(1) space

LinkedList *mergeLinkedLists(LinkedList *headOne, LinkedList *headTwo) {
  // Write your code here.
	if(!headOne) return headTwo;
	if(!headTwo) return headOne;
	LinkedList* head = headOne->value <= headTwo->value? headOne: headTwo;
	LinkedList* main = headOne->value <= headTwo->value ? headOne:headTwo;
	LinkedList* secondary = headOne->value <= headTwo->value ? headTwo:headOne;
	while(main){
		LinkedList* nextNode = main->next;
			if(main->next && main->next->value <= secondary->value){
				main = main->next;
			}else if(!main->next){
				main->next = secondary;
				main = nextNode;
			}else{
				main->next = secondary;
				main = secondary;
				secondary = nextNode;
			}
		}
  return head;
}
