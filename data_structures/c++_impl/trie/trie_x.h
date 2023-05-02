#ifndef TRIE_X_H_
#define TRIE_X_H_

#include <unordered_map>
#include <vector>
#include <string>

template<class TValue>
struct TrieNode{

    TValue value;
    bool terminated;
    std::unordered_map<char, TrieNode<TValue>*> nodes;

    TrieNode():TrieNode(TValue(), false){}
    TrieNode(const TValue& val, bool isTerminated):value(val), terminated(isTerminated){}

    TrieNode* add_node(char key, const TValue& value=TValue(), bool isTerminated=false)
    {
        if (nodes.find(key) == nodes.end())
        {
            nodes[key] = new TrieNode<TValue>(value, isTerminated);
        }
        
        return nodes[key];
    }

    TrieNode* get_node(char key)
    {
        if (nodes.find(key) != nodes.end())
        {
            return nodes[key];
        }
        else
        {
            return nullptr;
        }
    }
};


template<class TValue>
class TrieX
{
    public:
    using TTrieNode = TrieNode<TValue>;

    TrieX()
    {
        m_root = TTrieNode();
    }

    void add_word(const std::string& word)
    {
        auto curNode = &m_root;
        for (int i=0; i < word.size(); ++i)
        {
            if (i == word.size()-1)
            {
                curNode = curNode->add_node(word[i], TValue() , true);
            }
            else
            {
                curNode = curNode->add_node(word[i]);
            }
        } 
    }

    TTrieNode* find_word(const std::string& word)
    {
        TTrieNode* curNode = &m_root;
        for (int i=0; i < word.size(); ++i)
        {
            auto res = curNode->get_node(word[i]);
            if (!res)
            {
                return nullptr;
            }
            curNode = res;

            if (i == word.size()-1)
            {
                if (curNode->terminated)
                {
                    return curNode;
                }
                else
                {
                    return nullptr;
                }
            }
        }
    }

    std::vector<std::string> suffix(const std::string& prefix)
    {
        auto res = std::vector<std::string>();
        auto curNode = find_word(prefix);
        suffix_recursive(curNode, prefix, res);
        return res;
    }

    private:

    void suffix_recursive(
        TTrieNode* curNode, 
        const std::string& curPrefix,
        std::vector<std::string>& suffixes)
        {
            if (curNode->terminated)
            {
                suffixes.push_back(curPrefix);
            }

            for (auto& node: curNode->nodes)
            {
                suffix_recursive(node.second, curPrefix+node.first, suffixes);
            }
        }


    private:
    TTrieNode m_root;
};

#endif


