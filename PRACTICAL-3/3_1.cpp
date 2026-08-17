#include <iostream>
using namespace std;

int main() {
    int a[5] = {35, 60, 25, 15, 98};
    int i, j, temp;
    cout << "Sorting by Bubble Sort Method:" << endl;
    cout << endl;
    cout << "Array before sorting:" << endl;
    for (i = 0; i < 5; i++) {
        cout << a[i] << " ";
    }
    for (i = 0; i < 5 - 1; i++) {
        for (j = 0; j < 5 - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    cout << "\nArray after sorting:" << endl;
    for (i = 0; i < 5; i++) {
        cout << a[i] << " ";
    }
    cout << "\n\n";
    int ar[5] = {38, 19, 68, 57, 29};
    int b, c, tempp;
    cout << "Sorting by Selection Sort Method:" << endl;
    cout << endl;
    cout << "Array before sorting:" << endl;
    for (b = 0; b < 5; b++) {
        cout << ar[b] << " ";
    }
    cout << endl;
    for (b = 0; b < 5 - 1; b++) {
        int min = b;
        for (c = b + 1; c < 5; c++) {
            if (ar[c] < ar[min]) {
                min = c;
            }
        }
        tempp = ar[b];
        ar[b] = ar[min];
        ar[min] = tempp;
    }
    cout << "Array after sorting:" << endl;
    for (b = 0; b < 5; b++) {
        cout << ar[b] << " ";
    }
    cout << "\n\n";
    int array[5] = {38, 19, 68, 57, 29};
    int d, e, temporary;
    cout << "Sorting by Insertion Sort Method:" << endl;
    cout << endl;
    cout << "Array before sorting:" << endl;
    for (d = 0; d < 5; d++) {
        cout << array[d] << " ";
    }
    cout << endl;
    for (d = 1; d < 5; d++) {
        temporary = array[d];
        e = d - 1;
        while (e >= 0 && array[e] > temporary) {
            array[e + 1] = array[e];
            e--;
        }
        array[e + 1] = temporary;
    }
    cout << "Array after sorting:" << endl;
    for (d = 0; d < 5; d++) {
        cout << array[d] << " ";
    }
    cout << endl;
    return 0;
}
