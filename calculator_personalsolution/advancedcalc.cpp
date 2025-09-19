#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <stack>
#include <cctype>
#include <limits>
using namespace std;

double calculator(string expression){
    if (expression.empty()) {
        cout << "Ekspresi tidak boleh kosong!" << endl;
        return -1; 
    }
    double result = 0.0;
    vector<int> numbers_sorted;
    vector<char> ops_sorted;
    vector<int> final_numbers;
    vector<char> final_ops;
    bool test = false;



    for (int i = 0; i<=expression.length()-1; ++i){
        if (isdigit(expression[i]))
        {
            string tempor_num;
            while (i<=expression.length()-1 && isdigit(expression[i])){
                tempor_num += expression[i];
                i++;
            } 
            numbers_sorted.push_back(stoi(tempor_num));
            i--; 
        }
        else if (expression[i]=='+' || expression[i]=='-' || expression[i]=='*' || expression[i]=='/'){
            ops_sorted.push_back(expression[i]);
        }
    }

    vector<bool> used(numbers_sorted.size() + 1, false);

    // step 1: ambil * dan /
    for (int i = 0; i < ops_sorted.size(); i++) {
        if (ops_sorted[i] == '*' || ops_sorted[i] == '/') {
            if (!used[i]) {
                final_numbers.push_back(numbers_sorted[i]);
                used[i] = true;
            }
            if (!used[i+1]) {
                final_numbers.push_back(numbers_sorted[i+1]);
                used[i+1] = true;
            }
            final_ops.push_back(ops_sorted[i]);
        }
    }

    // step 2: ambil + dan -
    for (int i = 0; i < ops_sorted.size(); i++) {
        if (ops_sorted[i] == '+' || ops_sorted[i] == '-') {
            if (!used[i]) {
                final_numbers.push_back(numbers_sorted[i]);
                used[i] = true;
            }
            if (!used[i+1]) {
                final_numbers.push_back(numbers_sorted[i+1]);
                used[i+1] = true;
            }
            final_ops.push_back(ops_sorted[i]);
        }
    }
    if (final_numbers.empty() || final_ops.empty() || final_numbers.size() != final_ops.size() + 1) {
        cout << "Invalid number of operators. For example, '2+-2' can be written as '2-2'." << endl;
        return -1; 
    }


    // test output
   if (test) {for (int t = 0; t < final_numbers.size(); t++) {
        cout << final_numbers[t] << " ";
    }
    
    for (int t2 = 0; t2 < final_ops.size(); t2++) {
        cout << final_ops[t2] << " ";
    }
}
    cout << endl;
// calculation
stack<double> num_stack;
num_stack.push(final_numbers[0]);

    for (int i = 0; i < final_ops.size(); i++) {
        double num2 = final_numbers[i + 1];
        char op = final_ops[i];
        double num1 = num_stack.top();
        num_stack.pop();

        double temp_result;
        switch (op) {
    case '+':
        temp_result = num1 + num2;
        break;

    case '-':
        temp_result = num1 - num2;
        break;

    case '*':
        temp_result = num1 * num2;
        break;

    case '/':
        if (num2 != 0) {
            temp_result = num1 / num2;
        } else {
            cout << "PEMBAGIAN DENGAN 0" << endl;
            return -1; 
        }
        break;

    default:
        cout << "OPERATOR TIDAK VALID" << endl;
        return -1; 
       

    }
     num_stack.push(temp_result);

        }
        
    if (!num_stack.empty()) {
        result = num_stack.top();
        num_stack.pop();
    }

    cout << "Result: " << fixed << setprecision(4) << result << endl;
    return result;

}

int main (){
    string exp;
    char yes;
    system("color f8");
    cout<<"=========================="<<endl;
    cout<<"  ADVANCED CALCULATOR    "<<endl;
    do {
    cout<<"masukkan ekspresi matematika: ";
    getline(cin, exp);     
    calculator(exp);
    cout << "ingin menghitung lagi? (y/n): ";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //prevent new program to read previous input
    } while (yes == 'y' || yes == 'Y');


    return 0;
}



