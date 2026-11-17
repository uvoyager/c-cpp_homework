#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <algorithm>

struct Date {
    int day;
    int month;
    int year;
    std::string original_str;
    bool operator<(const Date& other) const {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        return day < other.day;
    }
};

void solveDates(const std::string& inputFilename, const std::string& outputFilename) {
    std::ifstream inFile(inputFilename);
    if (!inFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }
    std::string content((std::istreambuf_iterator<char>(inFile)), 
                         std::istreambuf_iterator<char>());
    inFile.close();

    std::regex pattern(R"((\d+)/(\d+)/(\d+))");
    auto words_begin = std::sregex_iterator(content.begin(), content.end(), pattern);
    auto words_end = std::sregex_iterator();

    std::vector<Date> dates;

    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        int d = std::stoi(match[1].str());
        int m = std::stoi(match[2].str());
        int y = std::stoi(match[3].str());
        if (y >= 0 && y <= 49) {
            y += 2000;
        } else if (y >= 51 && y <= 99) {
            y += 1900;
        }

        std::string orig = "(" + match[1].str() + "./" + match[2].str() + "./" + std::to_string(y) + ")";
        dates.push_back({d, m, y, orig});
    }

    if (dates.empty()) {
        std::cout << "Dates are in the wrong format." << std::endl;
        return;
    }

    auto minmax = std::minmax_element(dates.begin(), dates.end());
    Date oldest = *minmax.first;
    Date newest = *minmax.second;

    std::ofstream outFile(outputFilename);
    if (!outFile.is_open()) {
        std::cerr << "Error creating output file!" << std::endl;
        return;
    }

    outFile << "Earliest date: " << oldest.original_str << "\n";
    outFile << "Latest date: " << newest.original_str << "\n";
    outFile.close();

    std::cout << "Done! results are in the file: '" << outputFilename << "'." << std::endl;
}

int main() {

    solveDates("input.txt", "oldest_newest.txt");

    return 0;
}