#include <cctype>
#include <ios>
#include <iostream>
#include <map>
#include <set>
#include <vector>

int n, m;

std::map<char, std::vector< std::pair<int, int> > > mp;

std::set< std::pair<int, int> > antinodes;

bool check(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= m) {
        return false;
    }

    antinodes.insert({x, y});
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::freopen("input.txt", "r", stdin);

    std::vector< std::string > grid;
    std::string line;

    while(std::getline(std::cin, line)) {
        grid.push_back(line);
    }

    n = grid.size();
    m = grid[0].size();

    for(int i = 0;n > i;i++) {
        for(int j = 0;m > j;j++) {
            if(std::isalnum(grid[i][j])) {
                mp[grid[i][j]].push_back({i, j});
            }
        }
    }

    for(auto &it : mp) {
        auto vec = it.second;
        for(int i = 0;vec.size() > i;i++) {
            for(int j = i + 1;vec.size() > j;j++) {
                int x1 = vec[i].first, y1 = vec[i].second;
                int x2 = vec[j].first, y2 = vec[j].second;

                std::pair<int, int> dir_1 = {x1 - x2, y1 - y2};
                std::pair<int, int> dir_2 = {x2 - x1, y2 - y1};

                while(check(x1, y1)) {
                    x1 += dir_1.first;
                    y1 += dir_1.second;
                }

                while(check(x2, y2)) {
                    x2 += dir_2.first;
                    y2 += dir_2.second;
                }
            }
        }
    }

    std::cout << antinodes.size();
}
