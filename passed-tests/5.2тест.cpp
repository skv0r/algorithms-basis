#include <iostream>
#include <string>

using namespace std;

string applyRule(const string& input) {
    string result = "";
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

string generate_M(const string& C) {
    string M;
    for (int i = 0; i < 4; ++i) {
        int xor_result = (C[i+4] - '0') ^ (C[i+8] - '0') ^ (C[i+12] - '0') ^ (C[i+16] - '0') ^
                         (C[i+20] - '0') ^ (C[i+24] - '0') ^ (C[i+28] - '0') ^ (C[i+32] - '0');
        M += to_string(xor_result);
    }
    return M;
}

string generate_D(const string& C) {
    string D;
    for (int i = 0; i < 8; ++i) {
        char xor_result = (C[i+8] == '1') ^ (C[i+16] == '1') ^ (C[i+24] == '1') ^ (C[i+32] == '1') ? '1' : '0';
        D += xor_result;
    }
    return D;
}

int main() {
    string input = "000000000000000000000101001";   
    string C = applyRule(input);   
    string M = generate_M(C);  
    string D = generate_D(C);
    
    // Выводим недостающие байты
    cout << 'x' << ((64 - (D + M + C).size()) + 7) / 8  << endl;
    
    
    for (int i = 0; i < (D+M+C).length(); i += 8) {
        cout << (D+M+C).substr(i, 8) << endl;
    }
    
    
    return 0;
}
