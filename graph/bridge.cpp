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


vll adj[100005];
ll tin[100005], low[100005];
ll timer;
bool visited[100005];

void dfs(ll node, ll par)
{
    tin[node] = low[node] = timer++;
    visited[node] = true;
    for(ll child : adj[node])
    {
        if(child == par)
            continue;
        if(visited[child])
            low[node] = min(low[node], tin[child]);
        else
        {
            dfs(child, node);
            low[node] = min(tin[node], low[child]);
            if(low[child]>tin[node])
                cout<<"bridge found between : "<<node<<" - > "<<child<<endl;
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
  
    ll n, u, v; cin>>n;
    f(i, n)
    {
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    fa(i, 1, n+1)
        if(!visited[i])
            dfs(i, -1);

    return 0;
}