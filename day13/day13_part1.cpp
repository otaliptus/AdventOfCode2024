#include <iostream>
#include <regex>

std::regex buttonA_regex("Button A: X([+-]?\\d+), Y([+-]?\\d+)");
std::regex buttonB_regex("Button B: X([+-]?\\d+), Y([+-]?\\d+)");
std::regex prize_regex("Prize: X=([+-]?\\d+), Y=([+-]?\\d+)");

long long int res = 0;

void solve(int x1, int y1, int x2, int y2, int n, int m) {
    int a = 0, b = 0;
    while(a <= 100) {
        while(b <= 100) {
            if(a * x1 + b * x2 == n && a * y1 + b * y2 == m) {
                res += 3 * a + b;
                return;
            }
            b++;
        }
        a++;
        b = 0;
    }
}


int main() {
    std::freopen("input.txt", "r", stdin);

    std::string line;

    int x1, y1, x2, y2, n, m;
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
            solve(x1, y1, x2, y2, n, m);
        }
    }

    std::cout << res;

    return 0;
}
