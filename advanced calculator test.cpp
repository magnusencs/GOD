#include <iostream>
using namespace std;

int main(){
    char repeat;
do   {
    double num1, num2; 

     long double result;    
    char op;
    
    cout << "Enter numbers: ";
    cin >> num1;
    cout << endl;
    
    cout << "Enter operator (*, /, +, -): ";
    cin >> op;
    cout << endl;
    
    cout << "Enter second number: ";
    cin >> num2;
    
    if (op == '*') {
        result = num1 * num2;
    } else if (op == '/') {
        if (num2 != 0) {
            result = num1 / num2;
        } else {
            cout << "Error: Division by zero" << endl;
            return 1;
        }
    } else if (op == '+') {
        result = num1 + num2;
    } else if (op == '-') {
        result = num1 - num2;
    } else {
        cout << "Invalid operator." << endl;
        return 1;
    }
    
    cout << "Result: " << result << endl;
  
  cout<<"repeat program (y/n)"<<endl;
  
  cin>>repeat;
    
}while ( repeat=='y'|| repeat == 'Y');
    return 0;

}
