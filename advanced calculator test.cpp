#include <iostream>
#include <sstream>
#include <vector>
#include <string>

int main() {
    std::cout << "Masukkan ekspresi: ";
    std::string input;
    std::getline(std::cin, input);

    std::stringstream ss(input);
    double num;
    char op;
    std::vector<double> numbers;
    std::vector<char> operators;
    ss >> num;
    numbers.push_back(num);

    while(ss >> op >> num) {
        operators.push_back(op);
        numbers.push_back(num);
    }

    double result = numbers[0];
    for(size_t i = 0; i < operators.size(); i++) {
        if(operators[i] == '+') result += numbers[i+1];
        else if(operators[i] == '-') result -= numbers[i+1];
        else if(operators[i] == '*') result *= numbers[i+1];
        else if(operators[i] == '/') result /= numbers[i+1];
        else {
            std::cout << "Operator tidak dikenali: " << operators[i] << "\n";
            return 1;
        }
    }

    std::cout << "Hasil = " << result << std::endl;
    return 0;
}
