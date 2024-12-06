#include <iostream>
#include <set>
#include <vector>

int n, m;

// std::unordered_set and eternal struggles of std::pair hashing
std::set< std::pair<int, int> > visited;

const std::vector< std::vector<int> > dir = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};

void dfs(const std::vector< std::string > &grid, int x, int y, int curr_dir) {
    if(x < 0 || y < 0 || x >= n || y >= m) {
        std::cout << visited.size();
        exit(0);
    }

    visited.insert({x, y});

    int next_x = x + dir[curr_dir][0];
    int next_y = y + dir[curr_dir][1];

    if(grid[next_x][next_y] == '#') {
        curr_dir += 1;
        curr_dir %= 4;
        dfs(grid, x + dir[curr_dir][0], y + dir[curr_dir][1], curr_dir);
    }

    dfs(grid, next_x, next_y, curr_dir);
}

int main() {
    std::freopen("input.txt", "r", stdin);

    std::vector< std::string > grid;
    std::string line;

    while(std::getline(std::cin, line)) {
        grid.push_back(line);
    }

    n = grid.size();
    m = grid[0].size();

    int pos_x = 0, pos_y = 0;

    // Too lazy to not to do another pass
    for(int i = 0;n > i;i++) {
        for(int j = 0;m > j;j++) {
            if(grid[i][j] == '^') {
                pos_x = i;
                pos_y = j;
                break;
            }
        }
    }

    dfs(grid, pos_x, pos_y, 0);
}
