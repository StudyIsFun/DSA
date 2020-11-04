/*
3. Renaming Cities
Some cities are going to be renamed and accordingly name of their railway stations will also change. Changing the name of railway station should also result in changed station code. Railways have an idea that station code should be the shortest prefix out of all railway stations renamed prior to this. If some city has same name, then prefix will be the name with suffix as the count of occurence of that city prior to this and including this, seperated with spaces.

Given N renamed cities consisting of lowercase alphabets only. The task is to generate a station ID for all the stations.
*/


// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node{
    bool isEndOfWord;
    int count1;
    map<char, Node *> mp;
};

Node *newNode(){
    Node *temp = new Node();
    temp->isEndOfWord = false;
    // int count1 = 0;
    return temp;
}

void check(string *arr, int n);

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string arr[n];
        for(int i = 0;i<n;i++){
            string s;
            cin >> s;
            arr[i] = s;
        }
        check(arr,n);
    }
    return 0;
}
// } Driver Code Ends


//User function template for C++

string insert(Node *root, string key)
{
    string temp = "";
    int f = 0;
    for(int i=0;i<key.size();i++)
    {
        char index = key[i];
        if(!root->mp[index])
        {
            root->mp[index] = newNode();
            if(f==0)
                temp+=index; 
            f = 1;
        }
        if(f == 0)
            temp += index;
        if(root->mp[index])
            root = root->mp[index];
    }
    root->count1++;
    root->isEndOfWord = true;
    if(temp == key and root->count1>1)
        return key+" "+to_string(root->count1);
    else
        return temp;
}

// arr : array of strings
// n : count of the number of strings in the array
void check(string *arr, int n){
    Node *root = newNode();
    for(int i=0;i<n;i++)
        cout<<insert(root, arr[i])<<endl;
}



