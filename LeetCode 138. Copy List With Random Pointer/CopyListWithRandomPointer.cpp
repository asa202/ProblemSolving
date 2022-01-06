/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //better soln exists with three passes in the leetcode doc
//         if(head == NULL){
//             return NULL;
//         }
//         Node* newHead = new Node(head->val);
//         Node* temp = head;
//         Node* tempNew = newHead;
//         while(temp->next !=nullptr){
//             temp = temp->next;
//             Node* newNode = new Node(temp->val);
//             tempNew->next = newNode;
//             tempNew = tempNew->next;
//         }
        
//         temp = head;
//         tempNew = newHead;
//         while(temp != nullptr){
//             Node* random = temp->random;
//             Node* temp2 = head;
//             Node* tempNew2 = newHead;
//             while(random!=temp2){
//                 tempNew2 = tempNew2->next;
//                 temp2 = temp2->next;
//             }
//             tempNew->random = tempNew2;
//             temp = temp->next;
//             tempNew = tempNew->next;
//         }
        
//         return newHead;
        if(head == NULL){
            return NULL;
        }
        Node* temp = head;
        while(temp!=nullptr){
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = temp->next->next;
        }
        // temp = head;
        // while(temp!=NULL){
        //     cout<<temp->val<<endl;
        //     temp = temp->next;
        // }
        
        temp = head;
        Node* temp2 = head->next;
        while(temp!=NULL){
            if(temp->random)
            temp2->random = temp->random->next;
            
            temp=temp2->next;
            if(temp)
            temp2=temp->next;
        }
       temp = head;
        temp2 = head->next;
        Node* ret = temp2;
        while(temp!=NULL){
            if(temp2->next)
            temp->next = temp2->next;
            else{
                temp->next = NULL;
            }
            temp = temp->next;
            
            if(temp){
                temp2->next = temp->next;
            }else{
                temp2->next = NULL;
            }
            
            temp2=temp2->next;
        }
        return ret;
    }
};