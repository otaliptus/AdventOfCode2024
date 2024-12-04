#include <iostream>
#include <vector>

std::vector < std::vector<int> > dir = {
    {-1, -1},
    {-1, 0},
    {-1, 1},
    {0, -1},
    {0, 1},
    {1, -1},
    {1, 0},
    {1, 1}
};

std::vector<char> word = {'X', 'M', 'A', 'S'};

int main() {
    std::freopen("input.txt", "r", stdin);

    std::vector< std::string > grid;
    std::string line;

    while(std::getline(std::cin, line)) {
        grid.push_back(line);
    }

    int res = 0;
    int n = grid.size();
    int m = grid[0].size();

    for(int i = 0;n > i;i++) {
        for(int j = 0;m > j;j++) {
            if(grid[i][j] == 'X') {
                for(auto it : dir) {
                    int ans = 1;
                    for(int k = 1;3 >= k;k++) {
                        if(i + k * it[0] < 0 || i + k * it[0] >= n
                            || j + k * it[1] < 0 || j + k * it[1] >= m) {
                                ans = 0;
                                break;
                            }
                        if(grid[i + k * it[0]][j + k * it[1]] != word[k]) {
                            ans = 0;
                            break;
                        }
                    }
                    res += ans;
                }
            }
        }
    }

    std::cout << res;
}
