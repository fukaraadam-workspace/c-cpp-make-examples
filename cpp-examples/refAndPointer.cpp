#include <iostream>
#include <vector>
#include <string>

using namespace std;

// https://code.visualstudio.com/docs/cpp/config-mingw
int main()
{
    string food = "Pizza";  // A food variable of type string
    string &refFood = food;    // reference to food
    string* ptrFood = &food;

    cout << food << "\n";  // Outputs Pizza
    cout << refFood << "\n";  // Outputs Pizza
    cout << *ptrFood << "\n";  // Outputs Pizza

    cout << &food << "\n";  // Outputs 0x5ffe50
    cout << &refFood << "\n";  // Outputs 0x5ffe50
    cout << ptrFood << "\n";  // Outputs 0x5ffe50

    food = "Hamburger";  // Change food variable to Hamburger

    cout << food << "\n";  // Outputs Hamburger
    cout << refFood << "\n";  // Outputs Hamburger
    cout << *ptrFood << "\n";  // Outputs Hamburger
}