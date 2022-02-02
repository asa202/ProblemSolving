#include <unordered_map>
using namespace std;

// Do not edit the class below except for the
// populateSuffixTrieFrom and contains methods.
// Feel free to add new properties and methods
// to the class.
class TrieNode {
public:
  unordered_map<char, TrieNode *> children;
};

class SuffixTrie {
public:
  TrieNode *root;
  char endSymbol;

  SuffixTrie(string str) {
    this->root = new TrieNode();
    this->endSymbol = '*';
    this->populateSuffixTrieFrom(str);
  }

  void populateSuffixTrieFrom(string str) {
    // Write your code here.
		TrieNode *temp;
		for(int i = 0 ; i < str.size() ; i++){
			temp = this->root;
			for(int j = i ; j < str.size() ; j++){
				unordered_map<char, TrieNode *> :: const_iterator it =temp->children.find(str[j]);
				if(it == temp->children.end()){
					temp->children[str[j]] = new TrieNode();
					temp = temp->children[str[j]];
				}else{
					temp = it->second;
				}
			}
			temp->children[this->endSymbol] = nullptr;		
		}
  }

  bool contains(string str) {
    // Write your code here.
		TrieNode *temp = this->root;
		for(int i = 0; i<str.size(); i++){
			unordered_map<char, TrieNode *> :: const_iterator it =temp->children.find(str[i]);
			if(it == temp->children.end()){
				return false;
			}else{
				temp = it->second;
			}
		}
		
		unordered_map<char, TrieNode *> :: const_iterator it =temp->children.find('*');
		if(it != temp->children.end()){
			return true;
		}
    return false;
  }
};
