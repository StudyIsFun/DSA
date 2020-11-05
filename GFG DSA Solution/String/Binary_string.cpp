// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/*  Function to count the number of substrings 
*   starting and ending with 1
*   n: size of string
*   a: input string
*/
long binarySubstring(int n, string a){
    
    // Your code here
    long curr = 0, ans = 0, f = 0;
    for(int i=0; i<a.size(); i++){
        if(a[i]=='1' and f==0)
            f = 1, curr++;
        else if(a[i]=='1')
            ans += curr, curr++;
    }
    return ans;
    
}


// { Driver Code Starts.

int main()
{
    int t,n,count;
    string a;
    cin>>t;
    while(t--)
    {
        count = 0;
        cin >> n;
        cin >> a;
        
        cout << binarySubstring(n, a) << endl;
    }
}
  // } Driver Code Ends