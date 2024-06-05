#include <iostream>

void calculateEasterSunday(int year) {
    if (year < 1584 || year > 4098) {
        std::cout << "Year " << year << " is outside the valid range (1584 to 4098).\n";
        if (year <= 1583) {
            std::cout << "Boundary case: year <= 1583.\n";
        } else {
            std::cout << "Boundary case: year >= 4099.\n";
        }
        return;
    }

    int C = year % 19;
    int D = year % 4;
    int E = year % 7;
    int A = (19 * C + 24) % 30;
    int B = (2 * D + 4 * E + 6 * A + 5) % 7;
    int MarchDate = 22 + A + B;

    if (year == 1954 || year == 1981 || year == 2049 || year == 2076) {
        MarchDate -= 7;
        std::cout << "Special year adjustment applied for year " << year << " (-7 days).\n";
    }

    if (MarchDate > 31) {
        int AprilDate = MarchDate - 31;
        std::cout << "Easter Sunday for year " << year << " is April " << AprilDate << std::endl;
        if (AprilDate >= 1 && AprilDate <= 26) {
            std::cout << "Equivalence class: year results in April 1-26 (Easter in April).\n";
        }
    } else {
        std::cout << "Easter Sunday for year " << year << " is March " << MarchDate << std::endl;
        if (MarchDate >= 23 && MarchDate <= 31) {
            std::cout << "Equivalence class: year results in March 23-31 (Easter in March).\n";
        }
    }
}

int main() {
    int year;
    std::cout << "Enter a year: ";
    std::cin >> year;
    calculateEasterSunday(year);
    return 0;
}
