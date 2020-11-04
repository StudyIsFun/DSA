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
    TrieNode *child[2]={NULL};
    bool isEnd = false;
};

bool insert(int mat[][5], TrieNode *curr, int row, int n){
    for(int i=0; i<n; i++){
        int index = mat[row][i];
        if(curr->child[index]==NULL)
            curr->child[mat[row][i]] = new TrieNode();
        curr = curr->child[mat[row][i]];
    }
    if(curr->isEnd==true)
        return false;
    return curr->isEnd = true;
}

int32_t main()
{
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    TrieNode *root = new TrieNode();
    int mat[5][5] = {{0,0,0,0,0}, {1,1,1,1,1},{0,0,0,0,0}, {1,1,1,1,1},{1,0,1,0,1}};
    int unique_row_cnt = 0;
    f(i, 5)
    {
        if(insert(mat, root, i, 5))
            unique_row_cnt++;
    }
    cout<<"No of Unique row : "<<unique_row_cnt<<endl;
    return 0;
}