#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>

std::vector<std::string> parse(const std::string &line, char delim) {
    std::stringstream input_stream(line);
    std::vector<std::string> nums;

    for(std::string x; input_stream >> x;) {
        nums.push_back(x);
        if(input_stream.peek() == delim) {
            input_stream.ignore();
        }
    }

    return nums;
}

int main() {
    std::freopen("input.txt", "r", stdin);

    std::string line;
    std::getline(std::cin, line);

    auto nums = parse(line, ' ');

    int cnt = 25;
    while(cnt--) {
        std::vector< std::string > new_nums;
        for(auto num : nums) {
            if(num.size() & 1) {
                long long int new_num = std::stoll(num);
                new_nums.push_back(std::to_string(std::max((long long int)1, new_num * 2024)));
            } else {
                int idx = num.size() / 2;
                auto num1 = std::to_string(std::stoll(num.substr(0, idx)));
                auto num2 = std::to_string(std::stoll(num.substr(idx)));

                new_nums.push_back(num1);
                new_nums.push_back(num2);
            }
        }
        nums = new_nums;
    }

    std::cout << nums.size();
}
