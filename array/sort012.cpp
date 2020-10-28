#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
 {
	//code
	int t; cin>>t;
	while(t--)
	{
	    ll n; cin>>n;
	    ll arr[n];
	    for(ll i=0;i<n;i++)
	        cin>>arr[i];
	    int low = 0, mid = 0, high = n-1;
	    while(mid<=high){
	        switch(arr[mid]){
	            case 0 : swap(arr[low++], arr[mid++]);
	                     break;
	            case 1 : mid++;
	                     break;
	            case 2 : swap(arr[mid], arr[high--]);
	                     break;
	        }
	    }
	    for(ll i=0;i<n;i++)
	        cout<<arr[i]<<" ";
	    cout<<endl;
	}
	return 0;
}


/*

int main()
{
	int t; cin>>t;
	while(t--)
	{
		int n; cin>>n;
		int arr[3]={0} x;
		for(int i=0;i<n;i++)
			cin>>x; arr[x]++;

		while(arr[0]--)
			cout<<0<<" ";
		while(arr[1]--)
			cout<<1<<" ";
		while(arr[2]--)
			cout<<2<<" ";
		cout<<endl; 
	}
}

*/