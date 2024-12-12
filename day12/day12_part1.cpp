#include <iostream>
#include <map>
#include <string>

std::vector< std::vector<int> > dir = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}
};

std::vector< std::string > grid;

std::map< std::pair<int, int>, int > mp;
std::map< int, std::pair<int, int> > id_mp;

int n, m;

void dfs(int x, int y, int id) {
    mp[{x, y}] = id;
    id_mp[id].first += 1;

    for(auto &it : dir) {
        int dx = x + it[0], dy = y + it[1];

        if(dx < 0 || dx >= n || dy < 0 || dy >= m) {
            id_mp[id].second += 1;
            continue;
        }

        if(grid[x][y] == grid[dx][dy]) {
            if(mp.find({dx, dy}) == mp.end()) {
                dfs(dx, dy, id);
            }
        } else {
            id_mp[id].second += 1;
        }
    }
}

int main() {
    freopen("sample.txt", "r", stdin);

    std::string line;

    while(std::getline(std::cin, line)) {
        grid.push_back(line);
    }

    n = grid.size(), m = grid[0].size();
    int id = 1;

    for(int i = 0;n > i;i++) {
        for(int j = 0;m > j;j++) {
            if(mp.find({i, j}) == mp.end()) {
                dfs(i, j, id);
                id++;
            }
        }
    }

    long long int res = 0;

    for(auto it : id_mp) {
        res += it.second.first * it.second.second;
    }

    std::cout << res;
    // for(auto it : id_mp) {
    //     std::cout << it.first << ' ' << it.second.first << ' ' << it.second.second << '\n';
    // }

    // std::cout << '\n';

    // for(auto it : mp) {
    //     std::cout << it.first.first << ' ' << it.first.second << ' ' << it.second << '\n';
    // }
}
