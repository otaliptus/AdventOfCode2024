#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>

int num, res;

bool check_increase(const std::vector<int> &vec) {
    int flag1 = 0, last_num1 = vec[0];
    int flag2 = 0, last_num2 = vec[0];
    int flag3 = 0, last_num3 = vec[1];
    int flag4 = 0, last_num4 = vec[1];
    for(int i = 1;vec.size() - 1 > i;i++) {
        if(vec[i] <= last_num1 or vec[i] - last_num1 > 3) {
            flag1++;
        } else {
            last_num1 = vec[i];
        }

        if(vec[i] >= last_num2 or last_num2 - vec[i] > 3) {
            flag2++;
        } else {
            last_num2 = vec[i];
        }

        if(vec[i + 1] <= last_num3 or vec[i + 1] - last_num3 > 3) {
            if(i != vec.size() - 2) {
                flag3++;
            }
        } else {
            last_num3 = vec[i + 1];
        }

        if(vec[i + 1] >= last_num4 or last_num4 - vec[i + 1] > 3) {
            if(i != vec.size() - 2) {
                flag4++;
            }
        } else {
            last_num4 = vec[i + 1];
        }
    }

    return (std::min(flag1, flag2) < 2 || std::min(flag3, flag4) == 0) ? true : false;
}

int main() {
    std::freopen("input.txt", "r", stdin);

    std::string line;

    while(std::getline(std::cin, line)) {
        std::istringstream input_stream(line);
        std::vector<int> vec;
        while(input_stream >> num) {
            vec.push_back(num);
        }
        vec.push_back(0);

        res += check_increase(vec);
    }

    std::cout << res;
}
