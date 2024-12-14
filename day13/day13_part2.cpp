#include <iostream>
#include <regex>

std::regex buttonA_regex("Button A: X([+-]?\\d+), Y([+-]?\\d+)");
std::regex buttonB_regex("Button B: X([+-]?\\d+), Y([+-]?\\d+)");
std::regex prize_regex("Prize: X=([+-]?\\d+), Y=([+-]?\\d+)");

long long int res = 0;

void solve(long long int x1, long long int y1,
        long long int x2, long long int y2,
        long long int n, long long int m) {

    // x1 * a + x2 * b = n
    // y1 * a + y2 * b = m
    // a = (ny2 - mx2)/(y2x1 - x2y1)
    // b = (ny1 - mx1)/(x2y1 - y2x1)

    long long int a = (n * y2 - m * x2) / (y2 * x1 - x2 * y1);
    long long int b = (n * y1 - m * x1) / (x2 * y1 - y2 * x1);

    if(a * x1 + b * x2 == n && a * y1 + b * y2 == m) {
        res += 3 * a + b;
    }
}


int main() {
    std::freopen("input.txt", "r", stdin);

    std::string line;

    long long int x1, y1, x2, y2, n, m;
    while (std::getline(std::cin, line)) {
        std::smatch match;

        if (std::regex_search(line, match, buttonA_regex)) {
            x1 = std::stoi(match[1].str());
            y1 = std::stoi(match[2].str());
        } else if (std::regex_search(line, match, buttonB_regex)) {
            x2 = std::stoi(match[1].str());
            y2 = std::stoi(match[2].str());
        } else if (std::regex_search(line, match, prize_regex)) {
            n = std::stoi(match[1].str());
            m = std::stoi(match[2].str());
            solve(x1, y1, x2, y2, 10000000000000 + n, 10000000000000 + m);
        }
    }

    std::cout << res;

    return 0;
}
