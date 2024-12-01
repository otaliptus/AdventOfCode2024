#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>

int main() {
    std::freopen("input.txt", "r", stdin);

    std::vector< std::vector<int> > vec(2, std::vector<int>());

    int num, ans = 0, cnt = 0;
    while(std::cin >> num) {
        vec[cnt].push_back(num);
        cnt = 1 - cnt;
    }

    std::sort(vec[0].begin(), vec[0].end());
    std::map<int, int> mp;

    for(const auto &num : vec[1]) {
        mp[num]++;
    }

    for(const auto &num : vec[0]) {
        ans += num * mp[num];
    }

    std::cout << ans;
}
