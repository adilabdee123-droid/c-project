
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

int main() {
    // 1. Declare arrays
    string names[5];
    int marks[5][3];
    int total[5];
    double average[5];

    // 2. Input student names and marks
    for (int i = 0; i < 5; i++) {
        cout << "\nEnter name of student " << i + 1 << ": ";
        getline(cin, names[i]);

        for (int j = 0; j < 3; j++) {
            cout << "Enter mark " << j + 1
                 << " for " << names[i] << ": ";
            cin >> marks[i][j];
        }

        if (i < 4) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    for (int i = 0; i < 5; i++) {
        total[i] = 0;

        for (int j = 0; j < 3; j++) {
            total[i] += marks[i][j];
        }

        average[i] = total[i] / 3.0;
    }

    int topIndex = 0;

    for (int i = 1; i < 5; i++) {
        if (average[i] > average[topIndex]) {
            topIndex = i;
        }
    }

    cout << "\n\n";
    cout << "                       MARK SHEET            \n\n";

    cout << left << setw(18) << "Name"
         << right << setw(8) << "M1"
         << setw(8) << "M2"
         << setw(8) << "M3"
         << setw(10) << "Total"
         << setw(10) << "Average" << '\n';

    cout << string(62, '-') << '\n';

    for (int i = 0; i < 5; i++) {
        cout << left << setw(18) << names[i]
             << right << setw(8) << marks[i][0]
             << setw(8) << marks[i][1]
             << setw(8) << marks[i][2]
             << setw(10) << total[i]
             << setw(10) << fixed << setprecision(2)
             << average[i] << '\n';
    }

    cout << "\nTop student: " << names[topIndex] << '\n';
    cout << "Highest average: "
         << fixed << setprecision(2)
         << average[topIndex] << '\n';

    return 0;
}
