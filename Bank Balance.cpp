#include<bits/stdc++.h>
using namespace std;

class Bank {
private:
    // userID -> balance
    unordered_map<string, long long> accounts;

public:
    // CREATE X Y
    bool create(string userID, long long amount) {
        if(accounts.count(userID)) {
            // User already exists, just add balance
            accounts[userID] += amount;
            return false;
        }
        // New account
        accounts[userID] = amount;
        return true;
    }

    // DEBIT X Y
    bool debit(string userID, long long amount) {
        // User not found
        if(!accounts.count(userID))
            return false;

        // Insufficient balance
        if(accounts[userID] < amount)
            return false;

        accounts[userID] -= amount;
        return true;
    }

    // CREDIT X Y
    bool credit(string userID, long long amount) {
        // User not found
        if(!accounts.count(userID))
            return false;

        accounts[userID] += amount;
        return true;
    }

    // BALANCE X
    long long balance(string userID) {
        if(!accounts.count(userID))
            return -1;

        return accounts[userID];
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    Bank bank;

    while(q--) {
        string query;
        cin >> query;

        if(query == "CREATE") {
            string x;
            long long y;
            cin >> x >> y;
            cout << (bank.create(x, y) ? "true" : "false") << "\n";
        }
        else if(query == "DEBIT") {
            string x;
            long long y;
            cin >> x >> y;
            cout << (bank.debit(x, y) ? "true" : "false") << "\n";
        }
        else if(query == "CREDIT") {
            string x;
            long long y;
            cin >> x >> y;
            cout << (bank.credit(x, y) ? "true" : "false") << "\n";
        }
        else if(query == "BALANCE") {
            string x;
            cin >> x;
            cout << bank.balance(x) << "\n";
        }
    }

    return 0;
}
