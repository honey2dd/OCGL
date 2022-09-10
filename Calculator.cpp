#include <iostream>

int main()
{
    float a, b;
    char opr, ans;
    do
    {
        std::cout << "Enter first number :" << std::endl;
        std::cin >> a;
        std::cout << "Enter second number :" << std::endl;
        std::cin >> b;
        std::cout << "Enter operator choice:\n+ for addition\n- for subtraction\n* for multiplication\n/ for division\n% for modulus (float values will be rounded of to int)" << std::endl;
        std::cin >> opr;
        switch (opr)
        {
        case '+':
            std::cout << a << '+' << b << '=' << a+b << std::endl;
            break;

        case '-':
            std::cout << a << '-' << b << '=' << a-b << std::endl;
            break;
        
        case '*':
            std::cout << a << '*' << b << '=' << a*b << std::endl;
            break;

        case '/':
            std::cout << a << '/' << b << '=' << a/b << std::endl;
            break;

        case '%':
            std::cout << a << '%' << b << '=' << int(a)%int(b) << std::endl;
            break;
        
        default:
            std::cout << "Please enter correct operator!" << std::endl;
            break;
        }
        std::cout << "Do you want to continue (Y/N):" << std::endl;
        std::cin >> ans;
    } while (ans == 'Y' || ans == 'y'); 
    
}