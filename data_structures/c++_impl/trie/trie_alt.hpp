
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>


using namespace std;

struct Node{
    bool word;
    unordered_map<char, Node*> node;
};


Node* addCharacter(Node* node, char c, bool isWord)
{
    if (node->node.find(c) == node->node.end())
    {
        auto tmpNode = new Node();
        if (isWord)
        {
            tmpNode->word = true;
        }
        node->node[c] = tmpNode;
    }
    if (isWord)
    {
        node->node[c]->word = true;
    }
    return node->node[c];
}

void addWord(Node& node, string word)
{
    auto* curNode = &node;
    bool isWord = false;
    for (uint32_t i = 0; i < word.size(); ++i)
    {
        if (i == word.size()-1)
            isWord = true;
        curNode = addCharacter(curNode, word[i], isWord);
    }
}

void autoCorrect_helper(Node& node, string curPrefix, vector<string>& prefixes ){

    if (node.word)
    {
        prefixes.push_back(curPrefix);
        return;
    }

    for (auto pair: node.node)
    {
        autoCorrect_helper(*pair.second, curPrefix + pair.first, prefixes);
    }

}


vector<string> autoCorrect(Node& node, string targetPrefix)
{
    auto& curNode = node;
    vector<string> vec;
    for (int i=0; i < targetPrefix.size(); ++i)
    {
        auto c = targetPrefix[i];
        if (node.node.find(c) != node.node.end())
        {
            curNode = *node.node[c];
        }
        else
        {
            return vec;
        }
    }

    autoCorrect_helper(curNode, targetPrefix, vec);
    return vec;
}


int main(int argc, char **argv)
{
    Node trie;

    addWord(trie, "car");
    addWord(trie, "cat");
    addWord(trie, "can");
    addWord(trie, "cos");
    addWord(trie, "com");
    addWord(trie, "cor");

    int i = 0;
    vector<string> prefixes;
    auto res = autoCorrect(trie, "ca");

    for (auto r: res)
    {
        cout<<r<<", ";
    }

    return 0;
}