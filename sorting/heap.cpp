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

void heapify(vi &arr, int n, int i)
{
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    
    if(left<n and arr[left]>arr[largest])
        largest = left;
    if(right<n and arr[right]>arr[largest])
        largest = right;
    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
    
}

void HeapSort(vi &arr, int n)
{
    //building heap
    for(int i =n/2-1;i>=0;i--)
        heapify(arr, n, i);

    for(int i = 0; i<n-1;i++)
    {
        swap(arr[n-1-i], arr[0]);
        heapify(arr, n-1-i, 0);
    }
}

int32_t main()
{
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
  
    vi arr = {5, 4, 2, 1, 3};
    f(i, 5)
        cout<<arr[i]<<" ";
    cout<<endl;
    HeapSort(arr, 5);
    
    f(i, 5)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}