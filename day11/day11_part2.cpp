#include <iostream>
#include <map>
#include <string>
#include <sstream>

std::map<std::string, std::vector<std::string> > mp;
std::map< std::pair< std::string, int>, long long int > dfs_memo;

long long int ans = 0;

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

long long int dfs(std::string num, int cnt) {
    if(dfs_memo.find({num, cnt}) != dfs_memo.end()) {
        return dfs_memo[{num, cnt}];
    }

    if(cnt == 0) {
        return dfs_memo[{num, cnt}] = 1;
    }

    long long int curr_res = 0;
    if(mp.find(num) != mp.end()) {
        for(auto x : mp[num]) {
            curr_res += dfs(x, cnt - 1);
        }
        dfs_memo[{num, cnt}] = curr_res;
        return curr_res;
    }

    if(num.size() & 1) {
        long long int n = std::stoll(num);
        auto temp = std::to_string(2024 * n);
        mp[num] = {temp};
        return dfs_memo[{num, cnt}] = dfs(temp, cnt - 1);
    }

    auto str1 = num.substr(0, num.size() / 2);
    auto str2 = num.substr(num.size() / 2);

    long long int n1 = std::stoll(str1);
    long long int n2 = std::stoll(str2);

    auto temp1 = std::to_string(n1);
    auto temp2 = std::to_string(n2);

    mp[num] = {temp1, temp2};

    return dfs_memo[{num, cnt}] = dfs(temp1, cnt - 1) + dfs(temp2, cnt - 1);
}

int main() {
    std::freopen("input.txt", "r", stdin);

    std::string line;
    std::getline(std::cin, line);

    auto nums = parse(line, ' ');

    int cnt = 75;
    mp["0"] = {"1"};

    long long int res = 0;
    for(auto num : nums) {
        res += dfs(num, cnt);
    }

    std::cout << res << '\n';
}
