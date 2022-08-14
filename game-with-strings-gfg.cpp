//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        map<char,int>m;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }
        
        priority_queue<int>pq;
        
        for(auto i:m){
            pq.push(i.second);
        }
        
        while(k--){
            int m=pq.top();
            pq.pop();
            m--;
            pq.push(m);
        }
        
        int ans=0;
        while(!pq.empty()){
            int m=pq.top();
            pq.pop();
            int z=m*m;
            ans+=z;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
