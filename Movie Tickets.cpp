#include<bits/stdc++.h>
using namespace std;

class MovieTicket {
private:
    const int MAX_SLOTS = 100;
    
    unordered_map<int, int> bookedCount;
    
    set<pair<int,int>> bookings;

public:
    bool book(int customerID, int movieID) {
        if(bookings.count({customerID, movieID}))
            return false;
        
        if(bookedCount[movieID] >= MAX_SLOTS)
            return false;
        
        bookings.insert({customerID, movieID});
        bookedCount[movieID]++;
        return true;
    }

    bool cancel(int customerID, int movieID) {
        if(!bookings.count({customerID, movieID}))
            return false;
        
        bookings.erase({customerID, movieID});
        bookedCount[movieID]--;
        return true;
    }

    bool isBooked(int customerID, int movieID) {
        return bookings.count({customerID, movieID}) > 0;
    }

    int availableTickets(int movieID) {
        return MAX_SLOTS - bookedCount[movieID];
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    MovieTicket mt;

    while(q--) {
        string query;
        cin >> query;

        if(query == "BOOK") {
            int x, y;
            cin >> x >> y;
            cout << (mt.book(x, y) ? "true" : "false") << "\n";
        }
        else if(query == "CANCEL") {
            int x, y;
            cin >> x >> y;
            cout << (mt.cancel(x, y) ? "true" : "false") << "\n";
        }
        else if(query == "IS_BOOKED") {
            int x, y;
            cin >> x >> y;
            cout << (mt.isBooked(x, y) ? "true" : "false") << "\n";
        }
        else if(query == "AVAILABLE_TICKETS") {
            int y;
            cin >> y;
            cout << mt.availableTickets(y) << "\n";
        }
    }

    return 0;
}
