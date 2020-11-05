// Shortest Unique Prefix

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

struct TrieNode{
    int freq = 0;
    map<char, TrieNode *> mp;
};

void insert(TrieNode *root, string key){
    for(int i = 0; i<key.size(); i++){
        char c = key[i];
        if(!root->mp[c])
            root->mp[c] = new TrieNode();
        if(root->mp[c]){
            root->freq++;
            root = root->mp[c];
        }
    }
}

string generateUnique(TrieNode *root, string key){
    string temp = "";
    for(int i=0; i<key.size(); i++){
        char c = key[i];
        if(root->mp[c])
        {   
            root = root->mp[c];
            if(root->freq > 1)
                temp += c;
            else{
                temp += c; 
                return temp;
            }
        }
    }
}

int32_t main()
{
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
  
    TrieNode *root = new TrieNode();
    vector<string> keys = {"zebra", "dog", "duck", "dove"};
    for(int i=0; i<keys.size(); i++)
        insert(root, keys[i]);

    for(int i=0; i<keys.size(); i++){
        cout<<generateUnique(root, keys[i])<<endl;
    }
    
    return 0;
}