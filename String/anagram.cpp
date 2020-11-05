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

bool isAnagramPresent(string str, string key){
    int xor_val = 0;
    for(int i=0; i<key.size(); i++)
        xor_val ^= key[i];
    for(int i=0; i<key.size(); i++)
        xor_val ^= str[i];
    if(xor_val==0)
        return true;
    int j=0;
    for(int i=key.size();i<str.size(); i++){
        xor_val ^= str[i];
        xor_val ^= str[j++];
        if(xor_val==0)
            return true;
    }
    return false;
}

int32_t main()
{
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
  
    string str = "RiteshSingh";
    string key = "esh";

    
    cout<<isAnagramPresent(str, key);
    return 0;
}