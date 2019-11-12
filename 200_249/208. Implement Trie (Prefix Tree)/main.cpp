// 208. Implement Trie (Prefix Tree)
// Medium

// 2031

// 36

// Favorite

// Share
// Implement a trie with insert, search, and startsWith methods.

// Example:

// Trie trie = new Trie();

// trie.insert("apple");
// trie.search("apple");   // returns true
// trie.search("app");     // returns false
// trie.startsWith("app"); // returns true
// trie.insert("app");
// trie.search("app");     // returns true
// Note:

// You may assume that all inputs are consist of lowercase letters a-z.
// All inputs are guaranteed to be non-empty strings.

#include <iostream>
#include <string>

using namespace std;

class Trie
{
    struct ListNode
    {
        ListNode *next[26];
        bool isword;
        ListNode() : isword(false)
        {
            for (auto &a : next)
            {
                a = NULL;
            }
        }
    };
    ListNode *root;

private:
public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new ListNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        ListNode *t = root;
        for (auto &a : word)
        {
            int i = a - 'a';
            if (!t->next[i])
            {
                t->next[i] = new ListNode();
            }
            t = t->next[i];
        }
        t->isword = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        ListNode *t = root;
        for (auto &a : word)
        {
            int i = a - 'a';
            if (!t->next[i])
            {
                return false;
            }
            t = t->next[i];
        }
        return t->isword;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        ListNode *t = root;
        for (auto &a : prefix)
        {
            int i = a - 'a';
            if (!t->next[i])
            {
                return false;
            }
            t = t->next[i];
        }
        return true;
    }
};

int main()
{

    Trie *obj = new Trie();
    obj->insert("apple");
    cout << obj->search("apple") << endl;
    cout << obj->search("app") << endl;
    cout << obj->startsWith("app") << endl;
    obj->insert("app");
    cout << obj->search("app") << endl;

    return 0;
}