#include <iostream>
#include <string>
#include <vector>

#include "trie.h"
#include "trie_x.h"


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



TrieX<int> trieX;
trieX.add_word(std::string("ab"));
trieX.add_word(std::string("abc"));
trieX.add_word(std::string("abd"));
trieX.add_word(std::string("abce"));
trieX.add_word(std::string("abcf"));
trieX.add_word(std::string("abdm"));
trieX.add_word(std::string("abdl"));
std::cout<<"............."<<"\n";
auto res = trieX.suffix(std::string("ab"));
for(auto& suffix: res)
{
    std::cout<<suffix<<"\n";
}
std::cout<<"............."<<"\n";
res = trieX.suffix(std::string("abc"));
for(auto& suffix: res)
{
    std::cout<<suffix<<"\n";
}
 
  return 0;
}
