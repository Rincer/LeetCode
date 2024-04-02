#include "..\Solution.h"

class Trie 
{
    struct Node
    {       
        Node* nodes[256];
        bool end;
        Node()
        {            
            memset(nodes, 0, sizeof(nodes));
            end = false;
        }
    };

    Node root;

    void insert(Node& node, string& word, int letterIndex)
    {
        int index = word[letterIndex];

        if (node.nodes[index] == nullptr)
        {
            node.nodes[index] = new Node();
        }

        if (letterIndex == word.length() - 1)
        {
            node.nodes[index]->end = true;
            return;
        }

        insert(*node.nodes[index], word, letterIndex + 1);
    }

    bool search(Node& node, string& word, int letterIndex)
    {
        int index = word[letterIndex];
        if (node.nodes[index] == nullptr)
        {
            return false;
        }
        else
        {   
            if ((letterIndex == word.length() - 1) && (node.nodes[index]->end))
                return true;

            return search(*node.nodes[index], word, letterIndex + 1);
        }
    }

    bool startsWith(Node& node, string& word, int letterIndex)
    {
        if (letterIndex == word.length())
            return true;
        int index = word[letterIndex];
        if (node.nodes[index] == nullptr)
        {
            return false;
        }
        else
        {
            return startsWith(*node.nodes[index], word, letterIndex + 1);
        }
    }

    public:
        Trie() {

        }

        void insert(string word) 
        {
            insert(root, word, 0);
        }

        bool search(string word) 
        {
            return search(root, word, 0);
        }

        bool startsWith(string prefix) 
        {
            return startsWith(root, prefix, 0);
        }
};


void Solution::ImplementTrie()
{
    Trie trie;
    bool res;
    trie.insert("apple");
    res = trie.search("apple");   // return True
    res = trie.search("app");     // return False
    res = trie.startsWith("app"); // return True
    trie.insert("app");
    res = trie.search("app");     // return True
}