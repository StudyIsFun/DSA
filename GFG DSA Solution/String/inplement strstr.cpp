// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int strstr(string ,string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        
        cin>>a;
        cin>>b;
        
        cout<<strstr(a,b)<<endl;
    }
}
// } Driver Code Ends


/* The function should return position where the target string 
   matches the string str
Your are required to complete this method */
int strstr(string s, string x)
{
     //Your code here
     for(int i=0; i<s.size(); i++){
         if(s[i]==x[0]){
            for(int j=0;j<x.size(); j++){
                if(s[i+j]!=x[j])
                    break;
                if(j==(x.size()-1))
                    return i;
            }
        }
     }
     return -1;
}