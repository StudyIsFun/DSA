
// 2. Search Query for Strings
// Easy Accuracy: 77.18% Submissions: 346 Points: 2

// Trie is an efficient information retrieval data structure. Use this data structure to store strings and search strings. In this problem, you are given an array of strings (consisting of lowercase characters) arr[] of size N. Also, you will be given some queries Q and for each query a string is given and your task is to check if the given string is in the string array or not.

// Note: Each word in the array of string can be of size 103.



// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;
const int ALPHABET_SIZE = 26;
// trie node
struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];

    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void) {
    struct TrieNode *pNode = new TrieNode;

    pNode->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++) pNode->children[i] = NULL;

    return pNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(struct TrieNode *, string key);

// Returns true if key presents in trie, else
// false
bool search(struct TrieNode *, string key);

// Driver
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        string keys[n];

        for (int i = 0; i < n; i++) {
            cin >> keys[i];
        }

        struct TrieNode *root = getNode();

        // Construct trie
        for (int i = 0; i < n; i++) insert(root, keys[i]);

        while (q--) {
            string key;
            cin >> key;
            if (search(root, key))
                cout << "1" << endl;
            else
                cout << "0" << endl;
        }
    }
    return 0;
}
// } Driver Code Ends


// User function template for C++

// root : root node of the trie
// key : string to be inserted into the trie
// If not present, inserts key into trie
// If the key is prefix of trie node, just marks leaf node
void insert(struct TrieNode *root, string key) {
    for(int i=0;i<key.size();i++)
    {
        int index = key[i]-'a';
        if(root->children[index]==NULL){
            root->children[index] = new TrieNode();
        }
        root = root->children[index];
    }
    root->isEndOfWord = true;
}

// root : root node of the trie
// key : string to search in the trie
// Returns true if key presents in trie, else false
bool search(struct TrieNode *root, string key) {
    // code here
    for(int i=0; i<key.size();i++)
    {
        int index = key[i] - 'a';
        if(root->children[index]==NULL)
            return false;
        root = root->children[index];
    }
    return root->isEndOfWord;
}
