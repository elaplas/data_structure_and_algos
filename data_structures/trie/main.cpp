#include <iostream>
#include <string>
#include "trie.h"

using namespace std;


int main() {


 int i = 0;

 Trie<int> trie;
 // Insert key-value pairs
 trie.insert(string("sea"), 100);
 trie.insert(string("sells"), 200);
 trie.insert(string("she"), 300);
 // Search for values associated with keys
 cout<<"...............search..............."<<"\n";
 cout<<"(sea, "<<trie.find(string("sea"))<<")"<<"\n";
 cout<<"(sells, "<<trie.find(string("sells"))<<")"<<"\n";
 cout<<"(she, "<<trie.find(string("she"))<<")"<<"\n";
 // Remove nodes
 cout<<"...............remove..............."<<"\n";
 trie.remove(string("sells"));
 cout<<"(sea, "<<trie.find(string("sea"))<<")"<<"\n";
 cout<<"(she, "<<trie.find(string("she"))<<")"<<"\n";
 // cout<<"(sells, "<<trie.find(string("sells"))<<")"<<"\n";   key-val pair (sells, 200) doesn't exist so it should lead to seg fault
 
  return 0;
}
