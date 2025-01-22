#include <bits/stdc++.h>
using namespace std;
// is a leap year or not
bool isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    }
    return false;
}
// Function to calculate the next date
void calculateNextDate(int day, int month, int year) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // Adjust for leap year
    if (isLeapYear(year)) {
        daysInMonth[1] = 29;
    }
    // Increment the day
    day++;
    if (day > daysInMonth[month - 1]) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
    // Print the next date in DD-MM-YYYY format
    cout << setfill('0') << setw(2) << day << "-";
    cout << setfill('0') << setw(2) << month << "-";
    cout << year << endl;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        int day, month, year;
        cin >> day >> month >> year;
        calculateNextDate(day, month, year);
    }
    return 0;
}