#include <iostream>
#include <sstream>
#include <string>
#include <vector>

bool flag = 0;

std::vector<long long int> parse(const std::string &line, char delim) {
    std::stringstream input_stream(line);
    std::vector<long long int> nums;
    long long int target;

    for(long long int x; input_stream >> x;) {
        if(input_stream.peek() == delim) {
            target = x;
            input_stream.ignore();
            continue;
        }
        nums.push_back(x);
    }

    nums.push_back(target);

    return nums;
}

bool solve(long long int target, std::vector<long long int> &vec, std::vector<char> &op) {
    long long int res = vec[0];
    for(long long int i = 1; i < vec.size(); i++) {
        if(op[i - 1] == '+') {
            res += vec[i];
        } else if (op[i - 1] == '*') {
            res *= vec[i];
        } else {
            res = std::stoll(std::to_string(res) + std::to_string(vec[i]));
        }
        if(res > target) {
            return false;
        }
    }

    return res == target;
}

void dfs(long long int target, std::vector<long long int> &vec, std::vector<char> &op) {
    if(vec.size() == op.size() + 1) {
        if(solve(target, vec, op)) {
            flag = 1;
        }
        return;
    }

    op.push_back('+');
    dfs(target, vec, op);
    op.pop_back();

    op.push_back('*');
    dfs(target, vec, op);
    op.pop_back();

    op.push_back('|');
    dfs(target, vec, op);
    op.pop_back();
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::freopen("input.txt", "r", stdin);

    long long int res = 0;

    std::vector<char> op_list;
    std::string line;

    while(std::getline(std::cin, line)) {
        if(!line.size()) {
            break;
        }

        std::vector<long long int> nums = parse(line, ':');

        long long int target = nums.back();
        nums.pop_back();

        dfs(target, nums, op_list);
        if(flag == 1) {
            std::cout << target << '\n';
        }
        res += flag * target;
        flag = 0;
    }

    std::cout << res;
}
