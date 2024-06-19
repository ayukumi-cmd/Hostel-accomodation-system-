
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Hostel {
private:
    string Name;
    int Rent, Bed;
public:
    Hostel(string name, int rent, int bed) {
        Name = name;
        Rent = rent;
        Bed = bed;
    }

    string getName() {
        return Name;
    }

    int getRent() {
        return Rent;
    }

    int getBed() {
        return Bed;
    }

    void reserve() {
        ifstream in("C:/HostelFiles/Hostel.txt");
        ofstream out("C:/HostelFiles/Hostel Temp.txt");

        string line;
        while (getline(in, line)) {
            int pos = line.find("3star");
            if (pos != string::npos) {
                int bed = Bed - 1;
                Bed = bed;

                stringstream ss;
                ss << bed;
                string strBed = ss.str();

                int bedPos = line.find_last_of(':');
                line.replace(bedPos + 1, string::npos, strBed);
            }
            out << line << endl;
        }
        out.close();
        in.close();
        remove("C:/HostelFiles/Hostel.txt");
        rename("C:/HostelFiles/Hostel Temp.txt", "C:/HostelFiles/Hostel.txt");
        cout << "\tBed Reserved Successfully!" << endl;
    }
};

class Student {
private:
    string Name, RollNo, Address;
public:
    Student() : Name(""), RollNo(""), Address("") {}

    void setName(string name) {
        Name = name;
    }

    void setRollNo(string rollNo) {
        RollNo = rollNo;
    }

    void setAddress(string address) {
        Address = address;
    }

    string getName() {
        return Name;
    }

    string getRollNo() {
        return RollNo;
    }

    string getAddress() {
        return Address;
    }
};

int main() {
    // Create the initial hostel data
    Hostel h("3star", 5000, 2);
    ofstream out("C:/HostelFiles/Hostel.txt");
    out << "\t" << h.getName() << " : " << h.getRent() << " : " << h.getBed() << endl << endl;
    cout << "Hostel Data Saved" << endl;
    out.close();

    Student s;
    bool exit = false;

    while (!exit) {
        system("cls");
        int val;
        cout << "\tWelcome To Hostel Accommodation System" << endl;
        cout << "\t**************************************" << endl;
        cout << "\t1. Reserve A Bed." << endl;
        cout << "\t2. Exit." << endl;
        cout << "\tEnter Choice: ";
        cin >> val;

        if (val == 1) {
            system("cls");
            string name, rollNo, address;
            cout << "\tEnter Name of Student: ";
            cin >> name;
            s.setName(name);

            cout << "\tEnter RollNo of Student: ";
            cin >> rollNo;
            s.setRollNo(rollNo);

            cout << "\tEnter Address of Student: ";
            cin >> address;
            s.setAddress(address);

            if (h.getBed() > 0) {
                h.reserve();
                ofstream outFile("C:/HostelFiles/Student.txt", ios::app);
                outFile << "\t" << s.getName() << " : " << s.getRollNo() << " : " << s.getAddress() << endl << endl;
                outFile.close();
            } else {
                cout << "\tSorry, Bed Not Available!" << endl;
            }
            Sleep(5000);
        } else if (val == 2) {
            system("cls");
            exit = true;
            cout << "Good Luck!" << endl;
            Sleep(3000);
        }
    }
    return 0;
}

