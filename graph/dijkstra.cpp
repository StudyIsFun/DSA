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
const ll INF = 1e9;

unordered_map<ll, unordered_map<ll, ll>> adj;
vll dis(100005);

void dijkstra(ll source)
{
    dis[source] = 0;
    priority_queue<pair<ll, ll>> q;
    q.push({0, source});

    while(!q.empty())
    {
        auto temp = q.top();
        ll distance = -temp.ff;
        ll node = temp.ss;
        q.pop();
        for(auto &child : adj[node])
        {   
            if(distance+child.ss < dis[child.ff]){
                dis[child.ff] = distance+child.ss;
                    q.push({-dis[child.ff], child.ff});
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
  
    ll n, m, u, v, w; cin>>n>>m;
    f(i, m)
    {
        cin>>u>>v>>w;
        if(adj[u][v]==0 or adj[u][v]>w)
            adj[u][v] = w;
        if(adj[v][u]==0 or adj[v][u]>w)
            adj[v][u] = w;
    }

    dis.assign(n+1, INF);
    dijkstra(1);
    fa(i, 2, n+1)
        cout<<dis[i]<<" ";
    cout<<endl;

    return 0;
}