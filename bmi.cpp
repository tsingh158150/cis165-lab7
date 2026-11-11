/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <iomanip>

using namespace std;


int main() {
    double weight = 0.0;
    double height = 0.0;
    double bmi = 0.0; 
    string category; 
    
    cout << "Enter your weight in pounds: ";
    cin >> weight;
    
    cout << "Enter you height in inches: ";
    cin >> height;
    
    if (weight <= 0.0 || height <= 0.0) {
        cout << "Error: weight and height must be positive. " << endl;
        return 0;
    
    }
    
    // Calculate BMI using the required pounds-and-inches formula.
    bmi = weight * 703.0 / (height * height);
    
    //Classify using the unround BMI value.
    if (bmi < 18.5) {
        category = "Underweight";
    
    } else if (bmi <= 25.0 ) {
        category = "Optimal weight";
    } else {
        category = "Overweight";
    }
    
    cout << fixed << setprecision(2);
    cout << "BMI: " << bmi << endl;
    cout << "Category: " << category << endl;

    return 0;
}