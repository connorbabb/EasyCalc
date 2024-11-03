#include <iostream>
#include <fstream>
using namespace std;

double sum(double num1, double num2) {
    return num1 + num2;
}

double difference(double num1, double num2) {
    return num1 - num2;
}

double product(double num1, double num2) {
    return num1 * num2;
}

double quotient(double num1, double num2) {
    double num10 = static_cast<double>(num1);
    double num20 = static_cast<double>(num2);
    return num10 / num20;
}

int main() {
    ofstream outFile("C:/Users/conno/OneDrive/Documents/BYUI/Fall - 2024/CSE310/module03/history.txt");
    if (!outFile) {  // Error check
        cerr << "Error: Could not open the file 'history.txt' for writing." << endl;
        return 1;
    }

    cout << "Welcome to the Calculator Program!" << endl;
    string do_again = "";

    do {
        double num1, num2;
        cout << "Enter the first number: ";
        cin >> num1;
        cout << "Enter the second number: ";
        cin >> num2;
        cout << endl;

        cout << "What would you like to do with these numbers: " << endl;
        cout << "1. Sum" << endl;
        cout << "2. Difference" << endl;
        cout << "3. Product" << endl;
        cout << "4. Quotient" << endl;
        string choice;
        cin >> choice;
        cout << endl;

        if (choice == "1") {
            double result = sum(num1, num2);
            cout << "Sum: " << result << endl;
            outFile << num1 << " + " << num2 << " = " << result << endl;
        }
        else if (choice == "2") {
            double result = difference(num1, num2);
            cout << "Difference: " << result << endl;
            outFile << num1 << " - " << num2 << " = " << result << endl;
        }
        else if (choice == "3") {
            double result = product(num1, num2);
            cout << "Product: " << result << endl;
            outFile << num1 << " * " << num2 << " = " << result << endl;
        }
        else if (choice == "4") {
            if (num2 != 0) {
                double result = quotient(num1, num2);
                cout << "Quotient: " << result << endl;
                outFile << num1 << " / " << num2 << " = " << result << endl;
            }
            else {
                cout << "Divide by zero error." << endl;
                outFile << "Attempted division by zero with " << num1 << " / " << num2 << endl;
            }
        }
        else {
            cout << "Incorrect Input. Please enter a valid number." << endl;
        }
        cout << "Do you want to solve another equation? (yes/no) ";
        cin >> do_again;
        cout << endl;
    }
    while (do_again != "no");

    outFile.close();
    cout << "Results have been saved to history.txt." << endl;

    return 0;
}
