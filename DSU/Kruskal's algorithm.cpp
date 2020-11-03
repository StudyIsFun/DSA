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

ll parent[100005];
ll rankk[100005];
vector<tuple<int, int, int>> vt;
void make_set(int v){
    parent[v] = v;
    rankk[v] = 0;
}

ll find_set(int v){
    if(parent[v]==v)
        return v;
    return parent[v] = find_set(parent[v]);
}

bool union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);
    
    if(a!=b){
        if(rankk[a]<rankk[b])
            swap(a, b);
        parent[b] = a;

        if(rankk[a]==rankk[b])
            rankk[a]++;
        return true;
    }
    return false;
}


int find_MST()
{
    sort(vt.begin(), vt.end());
    int ans = 0;
    for(auto it : vt){
        int wt, x, y;
        tie(wt, x, y) = it;
        if(union_set(x, y))
            ans += wt;
    }
    return ans;
}
int32_t main()
{
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
  
    int n=4;
    fa(i, 0, n+1)
        make_set(i);

    vt.pb({10, 0, 1});
    vt.pb({6, 0, 2});
    vt.pb({5, 0, 3});
    vt.pb({15, 1, 3});
    vt.pb({4, 2, 3});

    cout<<find_MST()<<endl;
    return 0;
}