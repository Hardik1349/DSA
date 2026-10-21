#include <iostream>
using namespace std;

#define SIZE 10

int main() {

    int parking[SIZE];

    for (int i = 0; i < SIZE; i++) {
        parking[i] = -1;
    }

    int n;

    cout << "Enter number of vehicles: ";
    cin >> n;

    for (int i = 0; i < n; i++) {

        int number;

        cout << "Enter vehicle registration number: ";
        cin >> number;

        int slot = number % 10;

        int start = slot;

        while (parking[slot] != -1) {

            cout << "Slot " << slot << " is occupied. Trying next slot." << endl;

            slot = (slot + 1) % SIZE;

            if (slot == start) {
                cout << "Parking lot is full. Vehicle cannot be parked."
                     << endl;
                break;
            }
        }

        if (parking[slot] == -1) {
            parking[slot] = number;

            cout << "Vehicle " << number
                 << " parked at slot " << slot << endl;
        }
    }

    cout << endl;
    cout << "Final Parking Lot:" << endl;

    for (int i = 0; i < SIZE; i++) {

        if (parking[i] == -1) {
            cout << "Slot " << i << ": Empty" << endl;
        }
        else {
            cout << "Slot " << i << ": "
                 << parking[i] << endl;
        }
    }

    return 0;
}