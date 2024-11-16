#include <iostream>
#include <string>

std::string applyRule(const std::string& input) {
    std::string result = "";
    for (int i = 0; i < input.length(); i += 3) {
        if (i + 2 < input.length()) {
            char xor_result = (input[i] == '1') ^ (input[i + 1] == '1') ^ (input[i + 2] == '1') ? '1' : '0';
            result += xor_result;
            result += input[i];
            result += input[i + 1];
            result += input[i + 2];
        }
    }
    return result;
}

int main() {
    std::string input = "000000000000000000000101001";
    std::string output = applyRule(input);
    std::cout << "Output: " << output << std::endl;
    return 0;
}
