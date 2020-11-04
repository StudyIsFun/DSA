// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

string mostFrequentWord(string arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];

        cout << mostFrequentWord(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends


// User function template for C++

// arr : given array of string
// n : number of string in the array
// return the expected answer
struct TrieNode{
  int encounteredAt = 0;
  map<char,TrieNode *> mp;
  int count = 0;
  bool isEnd = false;
};

int position=-1, cnt = 0;
string curr;

void insert(TrieNode *root, string key, int pos){
    for(int i=0; i<key.size(); i++){
        char c = key[i];
        if(!root->mp[c])
            root->mp[c] = new TrieNode();
            
        if(root->mp[c])
            root = root->mp[c];
    }
    if(!root->isEnd)
    {
        root->encounteredAt = pos;
        root->isEnd = true;
    }
    root->count++;
    if(root->count > cnt){
        position = root->encounteredAt;
        curr = key;
        cnt = root->count;
    }
    else if(root->count == cnt){
        if(position<root->encounteredAt)
        {
            position = root->encounteredAt;
            curr = key;
        }
    }
}

string mostFrequentWord(string arr[], int n) {
    cnt = 0;
    position = -1;
    TrieNode *root = new TrieNode();
    for(int i=0;i<n;i++)
        insert(root, arr[i], i+1);
    return curr;
}





