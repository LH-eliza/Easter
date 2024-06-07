#include <iostream>
#include <vector>
#include <algorithm> // Include the algorithm header for std::find
#include <sstream> // Include sstream for input parsing

std::string calculateEasterDate(int year) {
    // Special years where the calculated date must be reduced by 7
    std::vector<int> specialYears = {1954, 1981, 2049, 2076};

    int C = year % 19;
    int D = year % 4;
    int E = year % 7;

    int A = (19 * C + 24) % 30;
    int B = (2 * D + 4 * E + 6 * A + 5) % 7;

    int date = 22 + A + B;

    // Adjust for special years
    if (std::find(specialYears.begin(), specialYears.end(), year) != specialYears.end()) {
        date -= 7;
    }

    std::string month = "March";
    if (date > 31) {
        date -= 31;
        month = "April";
    }

    return month + " " + std::to_string(date);
}

void findSpecificEasterDate(int startYear, int endYear, const std::string& targetDate) {
    std::vector<int> matchingYears;
    for (int year = startYear; year <= endYear; ++year) {
        std::string easterDate = calculateEasterDate(year);
        if (easterDate == targetDate) {
            matchingYears.push_back(year);
        }
    }

    std::cout << "Years with Easter on " << targetDate << ":\n";
    for (int year : matchingYears) {
        std::cout << year << std::endl;
    }
}

int main() {
    int startYear = 1854;
    int endYear = 4098;
    std::string month;
    int day;

    std::cout << "Enter the target date (format: Month day, e.g., April 1): ";
    std::getline(std::cin, month, ' ');
    std::cin >> day;

    std::stringstream targetDateStream;
    targetDateStream << month << " " << day;
    std::string targetDate = targetDateStream.str();

    findSpecificEasterDate(startYear, endYear, targetDate);

    return 0;
}
