#include <iostream>

int main()
{
    int number1;
    int number2;

    std::cout << "Digite o primeiro número: ";
    std::cin >> number1;
    std::cout << "Digite o segundo número: ";
    std::cin >> number2;

    int sum = number1 + number2;
    int sub = number1 - number2;
    int mul = number1 * number2;
    int div = number1 / number2;
    float fdiv = (float)number1 / (float)number2;
    int res = number1 % number2;
}
