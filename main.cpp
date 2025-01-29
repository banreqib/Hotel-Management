#include <iostream>
#include <string>
#include <list>
#include <utility>

using namespace std;

class room {
    int roomid;
    int roomno;
    int bedcount;
    bool smoking;

public:
    room(int roomid, int roomno, int bedcount, bool smoking) {
        this->roomid = roomid;
        this->roomno = roomno;
        this->bedcount = bedcount;
        this->smoking = smoking;
    }

    void setroomid(int roomid) {
        this->roomid = roomid;
    }
    int getroomid() {
        return roomid;
    }

    void setroomno(int roomno) {
        this->roomno = roomno;
    }
    int getroomno() {
        return roomno;
    }

    void setbedcount(int bedcount) {
        this->bedcount = bedcount;
    }
    int getbedcount() {
        return bedcount;
    }

    void setsmoking(bool smoking) {
        this->smoking = smoking;
    }
    bool getsmoking() {
        return smoking;
    }
};

class hotel {
    int hotelid;
    string name;
    int stars;

public:
    hotel(int hotelid, string name, int stars) {
        this->hotelid = hotelid;
        this->stars = stars;
        this->name = name;
    }

    void sethotelid(int hotelid) {
        this->hotelid = hotelid;
    }
    int gethotelid() {
        return hotelid;
    }

    void setname(string name) {
        this->name = name;
    }
    string getname() {
        return name;
    }

    void setstars(int stars) {
        this->stars = stars;
    }
    int getstars() {
        return stars;
    }
};

class guest {
    int guestid;
    int phone;
    int points;
    string guestname;

public:
    guest(int guestid, int phone, int points, string guestname) {
        this->guestid = guestid;
        this->phone = phone;
        this->points = points;
        this->guestname = guestname;
    }

    void setguestid(int guestid) {
        this->guestid = guestid;
    }
    int getguestid() {
        return guestid;
    }

    void setphone(int phone) {
        this->phone = phone;
    }
    int getphone() {
        return phone;
    }

    void setpoints(int points) {
        this->points = points;
    }
    int getpoints() {
        return points;
    }

    void setguestname(string guestname) {
        this->guestname = guestname;
    }
    string getguestname() {
        return guestname;
    }
};

class branch : public hotel, public guest {
    int branchid;
    int branchphone;
    string address;
    list<room> rooms;

public:
    branch(int branchid, int branchphone, string address,
        int hotelid, string hotelname, int stars,
        int guestid, int guestphone, int points, string guestname)
        : hotel(hotelid, hotelname, stars), guest(guestid, guestphone, points, guestname) {
        this->branchid = branchid;
        this->branchphone = branchphone;
        this->address = address;
    }

    list<room>& getRooms() {
        return rooms;
    }

    void addRoom(room r) {
        rooms.push_back(r);
    }

    void displayRooms() {
        for (auto& r : rooms) {
            cout << "Room ID: " << r.getroomid() << ", Room No: " << r.getroomno()
                << ", Bed Count: " << r.getbedcount() << ", Smoking: " << (r.getsmoking() ? "Yes" : "No") << endl;
        }
    }

    void setbranchid(int branchid) {
        this->branchid = branchid;
    }
    int getbranchid() {
        return branchid;
    }

    void setbranchphone(int branchphone) {
        this->branchphone = branchphone;
    }
    int getbranchphone() {
        return branchphone;
    }

    void setaddress(string address) {
        this->address = address;
    }
    string getaddress() {
        return address;
    }
};

list<guest> guests;
list<branch> branches;
list<pair<guest, room>> booking;
void insertGuest() {
    int guestid, phone, points;
    string guestname;
    cout << "Enter Guest ID: ";
    cin >> guestid;
    cout << "Enter Guest Phone: ";
    cin >> phone;
    cout << "Enter Guest Points: ";
    cin >> points;
    cout << "Enter Guest Name: ";
    cin.ignore();
    getline(cin, guestname);
    guests.push_back(guest(guestid, phone, points, guestname));
    cout << "Guest Added Successfully!" << endl;
}

void removeGuest() {
    int guestid;
    cout << "Enter Guest ID to Remove: ";
    cin >> guestid;
    auto it = guests.begin();
    while (it != guests.end()) {
        if (it->getguestid() == guestid) {
            it = guests.erase(it);
            cout << "Guest Removed Successfully!" << endl;
            return;
        }
        else {
            ++it;
        }
    }
    cout << "Guest not found!" << endl;
}

void modifyGuest() {
    int guestid;
    cout << "Enter Guest ID to Modify: ";
    cin >> guestid;
    for (auto& g : guests) {
        if (g.getguestid() == guestid) {
            int phone, points;
            string guestname;
            cout << "Enter New Phone: ";
            cin >> phone;
            cout << "Enter New Points: ";
            cin >> points;
            cout << "Enter New Guest Name: ";
            cin.ignore();
            getline(cin, guestname);
            g.setphone(phone);
            g.setpoints(points);
            g.setguestname(guestname);
            cout << "Guest Modified Successfully!" << endl;
            return;
        }
    }
    cout << "Guest not found!" << endl;
}

void displayGuests() {
    if (guests.empty()) {
        cout << "No guests found!" << endl;
        return;
    }
    for (auto& g : guests) {
        cout << "Guest ID: " << g.getguestid() << ", Name: " << g.getguestname()
            << ", Phone: " << g.getphone() << ", Points: " << g.getpoints() << endl;
    }
}

void findGuest() {
    int guestid;
    cout << "Enter Guest ID to Find: ";
    cin >> guestid;
    for (auto& g : guests) {
        if (g.getguestid() == guestid) {
            cout << "Guest Found: " << endl;
            cout << "Guest ID: " << g.getguestid() << ", Name: " << g.getguestname()
                << ", Phone: " << g.getphone() << ", Points: " << g.getpoints() << endl;
            return;
        }
    }
    cout << "Guest not found!" << endl;
}

void manageGuest() {
    int choice;
    do {
        cout << "==== Guest Operations ====" << endl;
        cout << "1. Add Guest" << endl;
        cout << "2. Remove Guest" << endl;
        cout << "3. Modify Guest" << endl;
        cout << "4. Display Guests" << endl;
        cout << "5. Find Guest" << endl;
        cout << "6. Back" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            insertGuest();
            break;
        case 2:
            removeGuest();
            break;
        case 3:
            modifyGuest();
            break;
        case 4:
            displayGuests();
            break;
        case 5:
            findGuest();
            break;
        case 6:
            cout << "Returning to main menu..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 6);
}

void insertBranch() {
    int branchid, branchphone, hotelid, guestid, points;
    string address, hotelname, guestname;
    int stars, phone;
    cout << "Enter Branch ID: ";
    cin >> branchid;
    cout << "Enter Branch Phone: ";
    cin >> branchphone;
    cout << "Enter Branch Address: ";
    cin.ignore();
    getline(cin, address);
    cout << "Enter Hotel ID: ";
    cin >> hotelid;
    cout << "Enter Hotel Name: ";
    cin.ignore();
    getline(cin, hotelname);
    cout << "Enter Hotel Stars: ";
    cin >> stars;
    cout << "Enter Guest ID: ";
    cin >> guestid;
    cout << "Enter Guest Phone: ";
    cin >> phone;
    cout << "Enter Guest Points: ";
    cin >> points;
    cout << "Enter Guest Name: ";
    cin.ignore();
    getline(cin, guestname);

   
    branches.push_back(branch(branchid, branchphone, address, hotelid, hotelname, stars, guestid, phone, points, guestname));
    cout << "Branch Added Successfully!" << endl;
}

void removeBranch() {
    int branchid;
    cout << "Enter Branch ID to Remove: ";
    cin >> branchid;
    auto it = branches.begin();
    while (it != branches.end()) {
        if (it->getbranchid() == branchid) {
            it = branches.erase(it);
            cout << "Branch Removed Successfully!" << endl;
            return;
        }
        else {
            ++it;
        }
    }
    cout << "Branch not found!" << endl;
}

void modifyBranch() {
    int branchid;
    cout << "Enter Branch ID to Modify: ";
    cin >> branchid;
    for (auto& b : branches) {
        if (b.getbranchid() == branchid) {
            int branchphone;
            string address;
            cout << "Enter New Branch Phone: ";
            cin >> branchphone;
            cout << "Enter New Branch Address: ";
            cin.ignore();
            getline(cin, address);
            b.setbranchphone(branchphone);
            b.setaddress(address);
            cout << "Branch Modified Successfully!" << endl;
            return;
        }
    }
    cout << "Branch not found!" << endl;
}

void displayBranches() {
    if (branches.empty()) {
        cout << "No branches available!" << endl;
        return;
    }
    for (auto& b : branches) {
        cout << "Branch ID: " << b.getbranchid() << ", Branch Phone: " << b.getbranchphone()
            << ", Address: " << b.getaddress() << endl;
    }
}

void findBranch() {
    int branchid;
    cout << "Enter Branch ID to Find: ";
    cin >> branchid;
    for (auto& b : branches) {
        if (b.getbranchid() == branchid) {
            cout << "Branch Found: " << endl;
            cout << "Branch ID: " << b.getbranchid() << ", Branch Phone: " << b.getbranchphone()
                << ", Address: " << b.getaddress() << endl;
            return;
        }
    }
    cout << "Branch not found!" << endl;
}

void manageBranch() {
    int choice;
    do {
        cout << "==== Branch Operations ====" << endl;
        cout << "1. Add Branch" << endl;
        cout << "2. Remove Branch" << endl;
        cout << "3. Modify Branch" << endl;
        cout << "4. Display Branches" << endl;
        cout << "5. Find Branch" << endl;
        cout << "6. Back" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            insertBranch();
            break;
        case 2:
            removeBranch();
            break;
        case 3:
            modifyBranch();
            break;
        case 4:
            displayBranches();
            break;
        case 5:
            findBranch();
            break;
        case 6:
            cout << "Returning to main menu..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 6);
}

void modifyBooking() {
    int guestid, roomid;
    cout << "Enter Guest ID to Modify Booking: ";
    cin >> guestid;
    cout << "Enter Room ID to Modify Booking: ";
    cin >> roomid;

    for (auto& b : booking) {
        if (b.first.getguestid() == guestid && b.second.getroomid() == roomid) {
            int newGuestId, newRoomId;
            cout << "Enter New Guest ID: ";
            cin >> newGuestId;
            cout << "Enter New Room ID: ";
            cin >> newRoomId;

            guest newGuest(newGuestId, 0, 0, "");
            for (auto& guestObj : guests) {
                if (guestObj.getguestid() == newGuestId) {
                    newGuest = guestObj;
                    break;
                }
            }

        
            room newRoom(newRoomId, 0, 0, false);
            for (auto& b : branches) {
                for (auto& roomObj : b.getRooms()) {
                    if (roomObj.getroomid() == newRoomId) {
                        newRoom = roomObj;
                        break;
                    }
                }
            }

           
            b.first = newGuest;
            b.second = newRoom;
            cout << "Booking Modified Successfully!" << endl;
            return;
        }
    }
    cout << "Booking not found!" << endl;
}
void insertBooking() {
    int guestid, roomid;
    cout << "Enter Guest ID: ";
    cin >> guestid;
    cout << "Enter Room ID: ";
    cin >> roomid;

  
    guest g(guestid, 0, 0, "");
    for (auto& guestObj : guests) {
        if (guestObj.getguestid() == guestid) {
            g = guestObj;
            break;
        }
    }

    for (auto& b : branches) {
        for (auto& room1 : b.getRooms()) {
            if (room1.getroomid() == roomid) {
                booking.push_back(make_pair(g, room1));
                cout << "Booking Added Successfully!" << endl;
                return;
            }
        }
    }
    cout << "Room or Guest not found!" << endl;
}

void removeBooking() {
    int guestid, roomid;
    cout << "Enter Guest ID to Remove Booking: ";
    cin >> guestid;
    cout << "Enter Room ID to Remove Booking: ";
    cin >> roomid;
    auto it = booking.begin();
    while (it != booking.end()) {
        if (it->first.getguestid() == guestid && it->second.getroomid() == roomid) {
            it = booking.erase(it);
            cout << "Booking Removed Successfully!" << endl;
            return;
        }
        else {
            ++it;
        }
    }
    cout << "Booking not found!" << endl;
}

void displayBookings() {
    if (booking.empty()) {
        cout << "No bookings available!" << endl;
        return;
    }
    for (auto& b : booking) {
        cout << "Guest ID: " << b.first.getguestid() << ", Guest Name: " << b.first.getguestname()
            << ", Room ID: " << b.second.getroomid() << ", Room No: " << b.second.getroomno() << endl;
    }
}

void findBooking() {
    int guestid, roomid;
    cout << "Enter Guest ID to Find Booking: ";
    cin >> guestid;
    cout << "Enter Room ID to Find Booking: ";
    cin >> roomid;
    for (auto& b : booking) {
        if (b.first.getguestid() == guestid && b.second.getroomid() == roomid) {
            cout << "Booking Found: " << endl;
            cout << "Guest ID: " << b.first.getguestid() << ", Guest Name: " << b.first.getguestname()
                << ", Room ID: " << b.second.getroomid() << ", Room No: " << b.second.getroomno() << endl;
            return;
        }
    }
    cout << "Booking not found!" << endl;
}

void manageBooking() {
    int choice;
    do {
        cout << "==== Booking Operations ====" << endl;
        cout << "1. Add Booking" << endl;
        cout << "2. Remove Booking" << endl;
        cout << "3. Display Bookings" << endl;
        cout << "4. Find Booking" << endl;
        cout << "5. Back" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            insertBooking();
            break;
        case 2:
            removeBooking();
            break;
        case 3:
            displayBookings();
            break;
        case 4:
            findBooking();
            break;
        case 5:
            cout << "Returning to main menu..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 5);
}



int main() {
    int choice;
    do {
         cout << "1. Guest" << endl;
        cout << "2. Branch" << endl;
        cout << "3. Booking" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            manageGuest();
            break;
        case 2:
            manageBranch();
            break;
        case 3:
            manageBooking();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

