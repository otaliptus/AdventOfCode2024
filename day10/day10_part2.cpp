#include <iostream>
#include <vector>

int n, m, res;

std::vector< std::vector<int> > dir = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

void dfs(const std::vector< std::string > &grid, int x, int y, char num) {
    if(num == '9') {
        res++;
        return;
    }

    for(auto it : dir) {
        int dx = x + it[0], dy = y + it[1];
        if(dx < 0 || dx >= n || dy < 0 || dy >= m) {
            continue;
        }

        if(grid[dx][dy] - grid[x][y] == 1) {
            dfs(grid, dx, dy, grid[dx][dy]);
        }
    }
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
            if(grid[i][j] == '0') {
                dfs(grid, i, j, '0');
            }
        }
    }

    std::cout << res;
}
