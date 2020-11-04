/*
4. Camel Case

Given a dictionary of words dict where each word follows CamelCase notation, print all words in the dictionary that match with a given pattern consisting of uppercase characters only.

CamelCase is the practice of writing compound words or phrases such that each word or abbreviation begins with a capital letter. Common examples include: “PowerPoint” and “WikiPedia”, “GeeksForGeeks”, “CodeBlocks”, etc.
*/




// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// Alphabet size (# of upper-Case characters)
#define ALPHABET_SIZE 26

void findAllWords(vector<string> , string);

int main()
{
	int t;
	cin>>t;
	while(t--) {
	int now;
	cin>>now;
	vector<string> dict(now) ;
	for(int i=0;i<now;i++)
	    cin>>dict[i];

	string pattern;
	cin>>pattern;

	findAllWords(dict, pattern);
	    cout<<endl;
}
	return 0;
}
// } Driver Code Ends


//User function template for C++
struct TrieNode{
    TrieNode *child[ALPHABET_SIZE];
    map<char, TrieNode *> mp;
    bool isEnd = false;
};


bool insert(TrieNode *root, string key, string pattern, int index){
    for(int i=0;i<key.size(); i++){
        char temp = key[i];
        if(temp==pattern[index]) index++;
        if(!root->mp[temp])
            root->mp[temp] = new TrieNode();
        if(root->mp[temp])
            root = root->mp[temp];
    }
    root->isEnd = true;
    if(index==pattern.size())
        return true;
    return false;
}

// dict : given set of strings
// pattern : given pattern
void findAllWords(vector<string> dict, string pattern) {
    //code here
    sort(dict.begin(), dict.end());
    TrieNode *root = new TrieNode();
    bool matched = false;
    for(string s : dict){
        if(insert(root, s, pattern, 0))
        {
            cout<<s<<" ";
            matched = true;
        }
    }
    if(!matched){
        cout<<"No match found"<<endl;
    }
}




