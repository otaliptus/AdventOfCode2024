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

    for(int i = 0;input_str.size() - 5 > i;i++) {
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
