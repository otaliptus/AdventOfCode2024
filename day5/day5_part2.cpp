#include <iostream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

std::unordered_map<int, std::unordered_set<int> > mp;

int res = 0;

std::vector<int> parse(const std::string &line, char delim) {
    std::stringstream input_stream(line);
    std::vector<int> nums;

    for(int x; input_stream >> x;) {
        nums.push_back(x);
        if(input_stream.peek() == delim) {
            input_stream.ignore();
        }
    }

    return nums;

}

void check_and_add(std::vector<int> &nums) {
    std::unordered_set<int> banned;
    for(auto it : nums) {
        if(banned.find(it) != banned.end()) {
            sort(nums.begin(), nums.end(), [](int a, int b) {
                return mp[a].contains(b);
            });

            res += nums[nums.size() / 2];
            return;
        }
        if(mp.find(it) != mp.end()) {
            banned.insert(mp[it].begin(), mp[it].end());
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::freopen("input.txt", "r", stdin);

    std::string line;
    while(std::getline(std::cin, line)) {
        if(!line.size()) {
            break;
        }

        std::vector<int> nums = parse(line, '|');
        mp[nums[1]].insert(nums[0]);
    }

    while(std::getline(std::cin, line)) {
        std::vector<int> nums = parse(line, ',');

        check_and_add(nums);
    }

    std::cout << res;
}
