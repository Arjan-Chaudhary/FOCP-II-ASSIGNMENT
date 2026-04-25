#include<bits/stdc++.h>
using namespace std;

string solve(int n, vector<int>& a) {
   
    sort(a.begin(), a.end(), greater<int>());
    
    set<int> used;      
    long long alexSum = 0, bobSum = 0;
    int turn = 0;       
    
    for(int i = 0; i < n; i++) {
     
        if(used.count(a[i])) continue;
        
        used.insert(a[i]);
        
        if(turn == 0)
            alexSum += a[i];  
        else
            bobSum += a[i];   
        
        turn = 1 - turn;     
    }
    
    return alexSum > bobSum ? "Alex" : "Bob";
}

int main(){
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        
        cout << solve(n, a) << "\n";
    }
    
    return 0;
}
