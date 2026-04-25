#include<bits/stdc++.h>
using namespace std;

int main(){
    long long l, r;
    cin >> l >> r;
    
    // Count of odd numbers in [l, r]
    long long oddCount = (r + 1) / 2 - l / 2;
    
    if(oddCount % 2 == 1)
        cout << "odd" << endl;
    else
        cout << "even" << endl;
    
    return 0;
}
