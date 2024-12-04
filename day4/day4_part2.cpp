#include <iostream>
#include <vector>

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

    for(int i = 1;n - 1 > i;i++) {
        for(int j = 1;m - 1 > j;j++) {
            if(grid[i][j] == 'A') {
                char top_left = grid[i - 1][j - 1];
                char top_right = grid[i - 1][j + 1];
                char bottom_left = grid[i + 1][j - 1];
                char bottom_right = grid[i + 1][j + 1];

                if((top_left == top_right && bottom_left == bottom_right)
                    && ((top_left == 'M' && bottom_left == 'S') || (top_left == 'S' && bottom_left == 'M'))) {
                        res++;
                    }

                if((top_left == bottom_left && top_right == bottom_right)
                    && ((top_left == 'M' && top_right == 'S') || (top_left == 'S' && top_right == 'M'))) {
                        res++;
                    }
            }
        }
    }

    std::cout << res;
}
