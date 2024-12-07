#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <tuple>

int n, m;

const std::vector< std::vector<int> > dir = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};

bool simulate(const std::vector< std::string > &grid, int x, int y, int curr_dir) {
    std::set< std::tuple<int, int, int> > visited;

    while(true) {
        std::tuple<int, int, int> state = std::make_tuple(x, y, curr_dir);
        if(visited.find(state) != visited.end()) {
            return true;
        }

        visited.insert(state);

        int next_x = x + dir[curr_dir][0];
        int next_y = y + dir[curr_dir][1];

        if(next_x < 0 || next_x >= n || next_y < 0 || next_y >= m) {
            return false;
        }

        if(grid[next_x][next_y] == '#') {
            curr_dir = (curr_dir + 5) % 4;
        } else {
            x = next_x;
            y = next_y;
        }
    }
    return false;
}

int main() {
    std::freopen("input.txt", "r", stdin);

    std::vector< std::string > grid;
    std::string line;

    while(std::getline(std::cin, line)) {
        if(!line.empty()) {
            grid.push_back(line);
        }
    }

    n = grid.size();
    m = grid[0].size();

    int x, y, start_dir;

    for(int i = 0;n > i;i++) {
        for(int j = 0;m > j;j++) {
            if(grid[i][j] == '^') {
                x = i;
                y = j;
                start_dir = 0;
                break;
            }
        }
    }

    grid[x][y] = '.';
    int ans = 0;

    // The following one could be better eh
    for(int i = 0;n > i;i++) {
        for(int j = 0;m > j;j++) {
            if(i == x && j == y) {
                continue;
            }
            if(grid[i][j] == '.') {
                grid[i][j] = '#';
                if(simulate(grid, x, y, start_dir)) {
                    ans++;
                }
                grid[i][j] = '.';
            }
        }
    }

    std::cout << ans;
}
