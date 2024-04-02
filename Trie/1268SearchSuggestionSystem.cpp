#include "..\Solution.h"

struct TrieNode
{
    TrieNode* m_Children[26];
    bool m_End[26];

    TrieNode()
    {
        memset(m_Children, 0, sizeof(m_Children));
        memset(m_End, 0, sizeof(m_End));
    }
};

class Trie
{
    TrieNode m_Root;

    public:

        void Insert(string s)
        {
            Insert(s, 0, m_Root);
        }

        void GetSuggestions(string search, vector<string>& suggestions)
        {
            string result;
            GetSuggestions(search, suggestions, result, &m_Root);
            
        }

    private:
        void Insert(string word, int letterIndex, TrieNode& node)
        {
            int index = word[letterIndex] - 'a';
            if (letterIndex == word.length() - 1)
            {
                node.m_End[index] = true;
                return;
            }
            else
            {
                if (node.m_Children[index] == nullptr)
                {
                    node.m_Children[index] = new TrieNode();
                }
                Insert(word, letterIndex + 1, *node.m_Children[index]);
            }
        }

        void GetSuggestions(string search, vector<string>& suggestions, string result, TrieNode* node)
        {
            if (node == nullptr)
                return;
            if (suggestions.size() == 3)
                return;
            int depth = result.length();
            if (depth < search.length())
            {
                int index = search[depth] - 'a';
                if ((node->m_End[index]) || (node->m_Children[index]))
                {
                    result.push_back(index + 'a');
                    if ((result.length() == search.length()) && node->m_End[index])
                    {
                        suggestions.push_back(result);
                    }
                    GetSuggestions(search, suggestions, result, node->m_Children[index]);
                }
            }
            else
            {
                for (int i = 0; i < 26; i++)
                {
                    if ((node->m_End[i]) || (node->m_Children[i]))
                    {
                        result.push_back(i + 'a');
                        if (node->m_End[i])
                        {
                            if (suggestions.size() < 3)
                                suggestions.push_back(result);
                        }
                        GetSuggestions(search, suggestions, result, node->m_Children[i]);
                        result.pop_back();
                    }                    
                }
            }
        }
};

vector<vector<string>> Solution::suggestedProducts(vector<string>& products, string searchWord)
{
    Trie trie;    
    vector<vector<string>> res;
    for (int i = 0; i < products.size(); i++)
    {
        trie.Insert(products[i]);
    }

    for (int i = 1; i <= searchWord.length(); i++)
    {
        string search = searchWord.substr(0,i);
        vector<string> suggestions;
        trie.GetSuggestions(search, suggestions);
        res.push_back(suggestions);
    }
    return res;
}