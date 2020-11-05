// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/*  Function to check if str1 can be formed from
*   str2 after rotation by 2 places
*/
bool isRotated(string s1, string s2)
{
    if(s1.size()==1 or s2.size()==1)
        if(s1==s2)
            return true;
        else
            return false;
            
    if((s1.substr(2,s1.size())+s1.substr(0,2)).find(s2)!=string::npos)
        return true;
    if((s1.substr(s1.size()-2, s1.size())+s1.substr(0, s1.size()-2)).find(s2)!=string::npos)
        return true;
    return false;
}


// { Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		cout<<isRotated(s,b)<<endl;
	}
	return 0;
}
  // } Driver Code Ends