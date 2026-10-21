#include <iostream>
using namespace std;

#define SIZE 10

int main() {

    int table[SIZE];

    for (int i = 0; i < SIZE; i++) {
        table[i] = -1;
    }

    int n;

    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++) {

        int id;

        cout << "Enter student ID: ";
        cin >> id;

        int index = id % SIZE;

        int jump = 7 - (id % 7);

        int start = index;

        while (table[index] != -1) {

            cout << "Slot " << index
                 << " is occupied. Jumping "
                 << jump << " slots." << endl;

            index = (index + jump) % SIZE;

            if (index == start) {
                cout << "No suitable slot found." << endl;
                break;
            }
        }

        if (table[index] == -1) {
            table[index] = id;

            cout << "Student " << id
                 << " stored at slot "
                 << index << endl;
        }
    }

    cout << endl;
    cout << "Final Hash Table:" << endl;

    for (int i = 0; i < SIZE; i++) {

        if (table[i] == -1) {
            cout << "Slot " << i << ": Empty" << endl;
        }
        else {
            cout << "Slot " << i << ": "
                 << table[i] << endl;
        }
    }

    return 0;
}