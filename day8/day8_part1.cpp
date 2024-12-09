#include <cctype>
#include <ios>
#include <iostream>
#include <map>
#include <set>
#include <vector>

int n, m;

std::map<char, std::vector< std::pair<int, int> > > mp;

std::set< std::pair<int, int> > antinodes;

void check(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= m) {
        return;
    }

    antinodes.insert({x, y});
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

                int sym_x1 = 2 * x1 - x2;
                int sym_y1 = 2 * y1 - y2;

                int sym_x2 = 2 * x2 - x1;
                int sym_y2 = 2 * y2 - y1;

                check(sym_x1, sym_y1);
                check(sym_x2, sym_y2);
            }
        }
    }

    std::cout << antinodes.size();
}
