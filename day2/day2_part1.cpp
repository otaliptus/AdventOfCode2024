#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>

int pre_num, num, dir, res;

int main() {
    std::freopen("input.txt", "r", stdin);

    std::string line;

    while(std::getline(std::cin, line)) {
        std::istringstream input_stream(line);
        int ans = 1;
        input_stream >> pre_num >> num;
        if(pre_num == num or abs(pre_num - num) > 3) {
            continue;
        }
        dir = (pre_num > num ? -1 : 1);
        pre_num = num;
        while(input_stream >> num) {
            if((num - pre_num) * dir < 0) {
                ans = 0;
                break;
            }
            if(pre_num == num or abs(pre_num - num) > 3) {
                ans = 0;
                break;
            }
            pre_num = num;
        }
        res += ans;
    }

    std::cout << res;
}
