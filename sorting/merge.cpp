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

vi merge(vi arr1, vi arr2)
{
    vi ans;
    int i=0, j=0;
    while(i!=arr1.size() and j!=arr2.size())
    {
        if(arr1[i]<arr2[j])
            ans.pb(arr1[i]), i++;
        else
            ans.pb(arr2[j]), j++;
    }
    while(i!=arr1.size())
        ans.pb(arr1[i++]);
    while(j!=arr2.size())
        ans.pb(arr2[j++]);
    return ans;
}

vi mergeSort(vi &arr, int start, int end)
{
    int mid = (start + end)/2;
    vi ans;
    if(start == end)
    {
        ans.pb(arr[start]);
        return ans;
    }
    return merge(mergeSort(arr, start, mid), mergeSort(arr, mid+1, end));
}


int32_t main()
{
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
  
    vi arr = {5,3,2,1,4};
    f(i, arr.size())
        cout<<arr[i]<<" ";
    cout<<endl;
    arr = mergeSort(arr, 0, 4);


    f(i, arr.size())
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}