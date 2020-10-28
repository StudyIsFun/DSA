#include<bits/stdc++.h>
using namespace std;
#define ll long long



//using set
int main()
 {
	//code
	int t; cin>>t;
	while(t--)
	{
	    unordered_set<ll> st;
	    ll n, m, x; 
	    cin>>n>>m;
	    while(n--)
	        cin>>x, st.insert(x);
	    while(m--)
	        cin>>x, st.insert(x);
	    cout<<st.size()<<endl;
	}
	return 0;
}


//using map
/*
 int main()
 {
	//code
	int t; cin>>t;
	while(t--)
	{
	    unordered_map<ll, ll> mp;
	    ll n, m, x; 
	    cin>>n>>m;
	    while(n--)
	        cin>>x, mp[x]=1;
	    while(m--)
	        cin>>x, mp[x]=1;
	    cout<<mp.size()<<endl;
	}
	return 0;
}

*/