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

int partition(int* arr, int low, int high)
{
    int pivot = arr[high];
    int i = low-1;
    for(int j=low; j<high; j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quicksort(int* arr, int low, int high)
{
    if(low < high)
    {
        int piv = partition(arr, low, high);
        quicksort(arr, low, piv-1);
        quicksort(arr, piv+1, high);
    }
}

int32_t main()
{
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
  
    int arr[] = {5, 1, 3 ,2, 4};
    quicksort(arr, 0, 4);
    f(i, 5)
    cout<<arr[i]<<" ";
    return 0;
}