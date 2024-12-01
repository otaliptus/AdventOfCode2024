#include <algorithm>
#include <cstdio>
#include <iostream>

int main() {
    std::freopen("input.txt", "r", stdin);

    std::vector< std::vector<int> > vec(2, std::vector<int>());

    int num, ans = 0, cnt = 0;
    while(std::cin >> num) {
        vec[cnt].push_back(num);
        cnt = 1 - cnt;
    }

    std::sort(vec[0].begin(), vec[0].end());
    std::sort(vec[1].begin(), vec[1].end());

    for(int i = 0;vec[0].size() > i;i++) {
        ans += std::abs(vec[0][i] - vec[1][i]);
    }

    std::cout << ans;
}
