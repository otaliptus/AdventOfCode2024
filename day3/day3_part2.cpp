#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::ifstream input("input.txt");
    std::stringstream buffer;
    buffer << input.rdbuf();
    std::string input_str = buffer.str();

    int res = 0;
    input_str += "00000000";

    int flag = 0;

    for(int i = 0;input_str.size() - 5 > i;i++) {
        if(input_str[i] == 'd' && input_str[i + 1] == 'o' && input_str[i + 2] == '(' && input_str[i + 3] == ')') {
            flag = 0;
            i = i + 3;
            continue;
        }
        if(flag) {
            continue;
        }
        if(input_str[i] == 'd' && input_str[i + 1] == 'o' && input_str[i + 2] == 'n'
            && input_str[i + 3] == '\'' && input_str[i + 4] == 't'
            && input_str[i + 5] == '(' && input_str[i + 6] == ')') {
            flag = 1;
            i = i + 6;
            continue;
        }
        if(input_str[i] == 'm' && input_str[i + 1] == 'u' && input_str[i + 2] == 'l' && input_str[i + 3] == '(') {
            i = i + 4;
            int j = i;
            std::string num1 = "";
            std::string num2 = "";
            while(input_str[j] >= 48 && input_str[j] <= 57 && j < input_str.size()) {
                num1 += input_str[j];
                j++;
            }
            if(input_str[j] != ',') {
                i = j;
                continue;
            }
            j++;
            while(input_str[j] >= 48 && input_str[j] <= 57 && j < input_str.size()) {
                num2 += input_str[j];
                j++;
            }
            if(input_str[j] != ')') {
                i = j;
                continue;
            }
            res += std::stoi(num1) * std::stoi(num2);
        }
    }

    std::cout << res;
}
