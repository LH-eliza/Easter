#include <iostream>

int calculateEasterSunday(int year) {
    int C = year % 19;
    int D = year % 4;
    int E = year % 7;
    int A = (19 * C + 24) % 30;
    int B = (2 * D + 4 * E + 6 * A + 5) % 7;
    int MarchDate = 22 + A + B;

    //Special Years
    if (year == 1954 || year == 1981 || year == 2049 || year == 2076) {
        MarchDate -= 7;
        std::cout << "Special year adjustment applied (-7 days).\n";
    }
    

    if (MarchDate > 31) {
        int AprilDate = MarchDate - 31;
        std::cout << "Easter Sunday for year " << year << " is April " << AprilDate << std::endl;
    } else {
        std::cout << "Easter Sunday for year " << year << " is March " << MarchDate << std::endl;
    }

    return MarchDate;
}

int main() {
    int year;
    std::cout << "Enter a year (between 1584 and 4098): ";
    std::cin >> year;

    if (year < 1584 || year > 4098) {
        std::cout << "Year out of range. Please enter a year between 1854 and 4098." << std::endl;
        return 1;
    }

    calculateEasterSunday(year);
    return 0;
}
