#include <iostream>
#include <limits>

int main() {
    double num1, num2;
    char operation;

    std::cout << "Welcome to the Basic Calculator!" << std::endl;

    // Input first number
    std::cout << "Enter the first number: ";
    while (!(std::cin >> num1)) {
        std::cin.clear(); // clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
        std::cout << "Invalid input. Please enter a number: ";
    }

    // Input second number
    std::cout << "Enter the second number: ";
    while (!(std::cin >> num2)) {
        std::cin.clear(); // clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
        std::cout << "Invalid input. Please enter a number: ";
    }

    // Input operation
    std::cout << "Enter an operation (+, -, *, /): ";
    std::cin >> operation;

    // Perform the chosen operation
    switch (operation) {
        case '+':
            std::cout << "Result: " << num1 + num2 << std::endl;
            break;
        case '-':
            std::cout << "Result: " << num1 - num2 << std::endl;
            break;
        case '*':
            std::cout << "Result: " << num1 * num2 << std::endl;
            break;
        case '/':
            if (num2 != 0) {
                std::cout << "Result: " << num1 / num2 << std::endl;
            } else {
                std::cout << "Error: Division by zero is not allowed." << std::endl;
            }
            break;
        default:
            std::cout << "Error: Invalid operation." << std::endl;
            break;
    }

    return 0;
}

