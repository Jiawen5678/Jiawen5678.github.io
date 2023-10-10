#include <iostream>
#include <sstream>
#include <stdexcept>
#include <limits>
#include <string>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

class fraction {
private:
// Internal representation of a fraction as two integers
int numerator;
int denominator;

public:
// Class constructor
fraction(int n, int d) : numerator(n), denominator(d) {}
// Methods to update the fraction
void add(fraction f);
void mult(fraction f);
void div(fraction f);
void simplify();
// Display method
void display(void);
};

void fraction::add(fraction f) {
    numerator = numerator * f.denominator + denominator * f.numerator;
    denominator = denominator * f.denominator;
    }

void fraction::mult(fraction f) {
    numerator = numerator * f.numerator;
    denominator = denominator * f.denominator;
    }

void fraction::div(fraction f) {
    if (f.numerator != 0) {
            numerator = numerator * f.denominator;
            denominator = denominator * f.numerator;
        } else {
            throw invalid_argument("Division by zero");
        }
    }

void fraction::display(void) {
    simplify();
    cout << numerator << "/" << denominator << endl;
    }
    
void fraction::simplify() {
        int commonDivisor = gcd(numerator, denominator);
        numerator /= commonDivisor;
        denominator /= commonDivisor;
    }

int main(){
    string command;
    
    while (true) {
        getline(cin, command);
        istringstream iss(command);
        int a, b, c, d;
        string operation;
        
        iss >> a;
        iss.ignore(1); // Ignore '/'
        iss >> b >> operation >> c;
        iss.ignore(1); // Ignore '/'
        iss >> d;    
    
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
        
        
        fraction fraction1(a,b);
        fraction fraction2(c,d);
        if (operation[0] == '+') {
            fraction1.add(fraction2);
            }else if (operation[0] == '*') {
            fraction1.mult(fraction2);
            }else if (operation == "div") {
            fraction1.div(fraction2);
            }
        fraction1.display();
        }
        
    
    return 0;
}
