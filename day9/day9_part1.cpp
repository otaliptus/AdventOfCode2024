#include <iostream>
#include <string>

int main() {
    freopen("input.txt", "r", stdin);

    std::string line;
    std::cin >> line;

    // You may never guess how tired I am to not to write the solution below

    long long int res = 0, id = 0;
    int cnt = 0;
    std::vector<int> vec;

    for(int i = 0;line.size() > i;i++, id++) {
        for(int j = 0;line[i] - '0' > j;j++) {
            std::cout << id;
            vec.push_back(id);
            cnt++;
        }
        i++;
        if(i == line.size() - 1) {
            break;
        }
        for(int j = 0;line[i] - '0' > j;j++) {
            vec.push_back(-1);
        }
    }

    for(int i = 0;std::min(cnt, (int)vec.size()) > i;i++) {
        if(vec[i] != -1) {
            res += vec[i] * i;
        } else {
            while(vec.back() == -1) {
                vec.pop_back();
            }
            res += i * vec.back();
            vec.pop_back();
        }
    }

    std::cout << res;
}
