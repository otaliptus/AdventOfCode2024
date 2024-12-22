#include <iostream>
#include <map>
#include <regex>

std::regex line_regex("p=(-?\\d+),(-?\\d+)\\s*v=(-?\\d+),(-?\\d+)");

std::map<std::pair<int, int>, int> mp;

int main() {
    freopen("input.txt", "r", stdin);

    std::string line;
    while(std::getline(std::cin, line)) {
        std::smatch match;

        if(std::regex_search(line, match, line_regex)) {
            int px = std::stoi(match[1].str());
            int py = std::stoi(match[2].str());
            int vx = std::stoi(match[3].str());
            int vy = std::stoi(match[4].str());

            px = px + 100 * vx;
            py = py + 100 * vy;

            px = px % 101;
            py = py % 103;

            if(px < 0) {
                px += 101;
            }

            if(py < 0) {
                py += 103;
            }


            mp[{px, py}] += 1;
        }
    }

    long long int q[2][2] = {{0, 0}, {0, 0}};

    for(auto it : mp) {
        int x = it.first.first;
        int y = it.first.second;
        
        if(x == 50 || y == 51) {
            continue;
        }

        q[x/51][y/52] += it.second;
    }

    std::cout << q[0][0] * q[1][1] * q[0][1] * q[1][0];
}