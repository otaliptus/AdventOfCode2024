#include <iostream>
#include <map>
#include <regex>

std::regex line_regex("p=(-?\\d+),(-?\\d+)\\s*v=(-?\\d+),(-?\\d+)");

std::map<std::pair<int, int>, int> mp;

struct robot {
    int x, y;
    int vx, vy;
};

std::vector<robot> robots;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    std::string line;

    while(std::getline(std::cin, line)) {
        std::smatch match;

        if(std::regex_search(line, match, line_regex)) {
            int px = std::stoi(match[1].str());
            int py = std::stoi(match[2].str());
            int vx = std::stoi(match[3].str());
            int vy = std::stoi(match[4].str());

            auto temp_robot = robot{px, py, vx, vy};

            robots.push_back(temp_robot);
        }
    }

    int cnt = 1;

    while(cnt < 10000) {
        std::map<std::pair<int, int>, int> mp;

        for(auto &r : robots) {
            mp[{r.x, r.y}] += 1;
        }

        // Some print checks applied here.

        for(auto &r : robots) {
            r.x += r.vx;
            r.y += r.vy;
            
            if(r.x < 0) {
                r.x += 101;
            }

            if(r.y < 0) {
                r.y += 103;
            }
        }

        cnt += 1;
    }
}