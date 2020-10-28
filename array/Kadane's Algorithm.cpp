//Given an array arr of N integers. Find the contiguous sub-array with maximum sum.

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
 {
	//code
	int t; cin>>t;
	while(t--){
	    ll ans = INT_MIN;
	    ll n; cin>>n;
	    ll arr[n];
	    ll sum = 0;
	    for(ll i=0; i<n; i++)
	    {
	        cin>>arr[i];
	        sum = max(sum+arr[i], arr[i]);
	        ans = max(ans, sum);
	    }
	    cout<<ans<<endl;
	}
	return 0;
}