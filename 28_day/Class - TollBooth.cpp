#include <iostream>
using namespace std;
class TollBooth {
private:
    int totalCars;
    int totalCash;
public:
    // Constructor
    TollBooth() : totalCars(0), totalCash(0) {}
    // Function to count paying cars
    void payingCar() {
        totalCars++;
        totalCash += 50;
    }
    // Function to count non-paying cars
    void nopayCar() {
        totalCars++;
    }
    // Function to display the totals
    void display() const {
        cout << "Total Cash : " << totalCash << "/-" << endl;
        cout << "Total Cars : " << totalCars << endl;
    }
};
int main() {
    TollBooth tollBooth;
    char input;
    while (true) {
        cin >> input;
        if (input == 'p') {
            tollBooth.payingCar();
        } else if (input == 'n') {
            tollBooth.nopayCar();
        } else if (input == 'q') {
            tollBooth.display();
            break;
        }
    }
    return 0;
}