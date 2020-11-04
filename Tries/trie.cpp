/*
    Author : Ritesh Singh
*/
 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ff first
#define ss second
#define T int t;cin>>t;while(t--)
#define f(i,n) for (int i=0;i<n;i++)
#define fa(i,a,b) for (int i=a;i<b;i++)
#define fb(i,a,b) for (int i=a;i>=b;i--)
#define pb push_back
#define pp pop_back
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mt make_tuple
#define mp make_pair 
#define vi vector<int>
#define vl vector<long>
#define vll vector<long long>
#define vs vector<string>
#define pi pair<int,int>
#define pll pair<long long, long long>
#define print(v) for(auto x:v) cout<<x<<" ";cout<<endl;
#define ce cout<<endl
#define all(x) x.begin(),x.end()
#define type(x) cerr<<typeid(x).name();
const int Alphabets = 26;
struct TrieNode{
    TrieNode *child[26] = {NULL};
    bool isEnd = false;
};

void insert(TrieNode *root, string &key){
    TrieNode *curr = root;
    for(int i=0; i<key.size(); i++){
        int index = key[i] - 'a';
        if(curr->child[index]==NULL)
            curr->child[index] = new TrieNode();
        curr = curr->child[index];
    }
    curr->isEnd = true;
}

bool search(TrieNode *curr, string &key){
    for(int i=0; i<key.size(); i++){
        int index = key[i]-'a';
        if(curr->child[index]==NULL)
            return false;
        curr = curr->child[index];
    }
    return curr->isEnd;
}

int32_t main()
{
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
  
    TrieNode *root = new TrieNode();
    string key = "ritesh";
    string key1 = "singh";
    string key2 = "singham";
    insert(root, key);
    insert(root, key1);

    cout<<search(root, key)<<endl;
    cout<<search(root, key1)<<endl;
    cout<<search(root, key2)<<endl;

}