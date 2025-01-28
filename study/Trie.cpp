#include <iostream>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }

    ~TrieNode() {
        for (int i = 0; i < 26; i++) {
            delete children[i];
        }
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    ~Trie() {
        delete root;
    }

    void insertUtil(TrieNode* root, string word) {
        // Base case
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        // Assumption: word is in lowercase
        int index = word[0] - 'a';
        TrieNode* child;

        // If present
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            // If absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word) {
        // Base case
        if (word.length() == 0) {
            return root->isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        // If present
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            // If absent 
            return false;
        }

        // Recursive call
        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word) {
        return searchUtil(root, word);
    }
};

int main() {
    Trie* t = new Trie();

    t->insertWord("abcd");
    t->insertWord("hello");
    t->insertWord("world");

    cout << "Present or not (abcd): " << t->searchWord("abcd") << endl;
    cout << "Present or not (hello): " << t->searchWord("hello") << endl;
    cout << "Present or not (world): " << t->searchWord("world") << endl;
    cout << "Present or not (abc): " << t->searchWord("abc") << endl;
    cout << "Present or not (abcdw): " << t->searchWord("abcdw") << endl;

    delete t;
    return 0;
}
