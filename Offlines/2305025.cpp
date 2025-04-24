#include <iostream>
//#include <numeric> // for std::gcd
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

class Fraction {
private:
    int numerator;
    int denominator;

    void reduce() {
        if (denominator == 0) {
            cout << "Denominator cannot be zero. Reset to 1." << endl;
            denominator = 1;
        }
        int gcd_val = gcd(abs(numerator), abs(denominator));
        numerator /= gcd_val;
        denominator /= gcd_val;

        // keep denominator positive
        if (denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }
    }

public:
    Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) {
        reduce();
    }

    // Arithmetic operators
    Fraction operator+(const Fraction& f) const {
        return Fraction(numerator * f.denominator + f.numerator * denominator,
                        denominator * f.denominator);
    }

    Fraction operator-(const Fraction& f) const {
        return Fraction(numerator * f.denominator - f.numerator * denominator,
                        denominator * f.denominator);
    }

    Fraction operator*(const Fraction& f) const {
        return Fraction(numerator * f.numerator, denominator * f.denominator);
    }

    Fraction operator/(const Fraction& f) const {
        if (f.numerator == 0) {
            cout << "Error: Cannot divide by zero fraction!" << endl;
            return Fraction(0, 1);
        }
        return Fraction(numerator * f.denominator, denominator * f.numerator);
    }

    void print() const {
        cout << numerator << "/" << denominator << endl;
    }

    // Comparison helper
    bool equals(const Fraction& f) const {
        return numerator == f.numerator && denominator == f.denominator;
    }
};

class FractionCollection {
private:
    Fraction* fractions;
    int length;
    int capacity;

    void resize() {
        int newCapacity = capacity * 2;
        Fraction* newArray = new Fraction[newCapacity];
        for (int i = 0; i < length; i++) {
            newArray[i] = fractions[i];
        }
        delete[] fractions;
        fractions = newArray;
        capacity = newCapacity;
    }

public:
    FractionCollection(int initialCapacity = 10)
        : length(0), capacity(initialCapacity) {
        fractions = new Fraction[capacity];
    }

    ~FractionCollection() {
        delete[] fractions;
    }

    void insert(const Fraction& f) {
        if (length >= capacity) resize();
        fractions[length++] = f;
    }

    void removeAt(int index) {
        if (index < 0 || index >= length) {
            cout << "Invalid index!" << endl;
            return;
        }
        for (int i = index; i < length - 1; ++i) {
            fractions[i] = fractions[i + 1];
        }
        --length;
    }

    void remove(const Fraction& f) {
        int i;
        for (i = 0; i < length; i++) {
            if (fractions[i].equals(f)) {
                removeAt(i);
                cout << "Fraction removed." << endl;
                return;
            }
        }
        cout << "Fraction not found." << endl;
    }

    void print() const {
        cout << "Fraction Collection (" << length << " elements):" << endl;
        for (int i = 0; i < length; ++i) {
            fractions[i].print();
        }
    }
};

// Main function demonstrating everything
int main() {
    // Fraction a(3, 4), b(2, 5), c;

    // cout << "Fraction A: ";
    // a.print();

    // cout << "Fraction B: ";
    // b.print();

    // cout << "A + B = ";
    // c = a + b;
    // c.print();

    // cout << "A - B = ";
    // c = a - b;
    // c.print();

    // cout << "A * B = ";
    // c = a * b;
    // c.print();

    // cout << "A / B = ";
    // c = a / b;
    // c.print();

    // cout << "\n-- Managing Fraction Collection --" << endl;
    // FractionCollection collection;
    // collection.insert(a);
    // collection.insert(b);
    // collection.insert(Fraction(5, 6));

    // collection.print();

    // cout << "Removing (2/5)..." << endl;
    // collection.remove(Fraction(2, 5));
    // collection.print();

    // cout << "Removing (1/2)..." << endl;
    // collection.remove(Fraction(1, 2)); // Not found
    // collection.print();

        // sample main code from offline
    // create Fraction with numerator, denominator
    Fraction a(5, 2), b(7, 2), c(9, 2), d(28, 5);
    cout << "Fraction" << endl;
    cout << "
        -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -"<<endl;
        cout
         << "A: ";
    a.print();
    cout << "B: ";
    b.print();
    cout << endl;
    cout << "Add(a,b): ";
    a.add(b).print();
    cout << "Add(a,2): ";
    a.add(2).print();
    cout << "Sub(a,b) ";
    a.sub(b).print();
    cout << "Sub(a,2) ";
    a.sub(2).print();
    cout << "Mul(a,b): ";
    a.mul(b).print();
    cout << "Mul(a,2): ";
    a.mul(2).print();
    cout << "Div(a,b): ";
    a.div(b).print();
    cout << "Div(a,2): ";
    a.div(2).print();
    cout << "Div(a,0): ";
    a.div(0).print();
    // Collection of Fractions
    Fraction e, f(5), g(10);
    FractionCollection fc(10);
    fc.insert(a);
    fc.insert(b);
    fc.insert(c);
    fc.print();
    cout << "Sub(Pos0, Pos1): ";
    fc.sub(0, 1).print(); // subtracts the fraction at pos1 from fraction at pos0
    cout << "Div(Pos0, Pos1): ";
    fc.div(0, 1).print(); // divides the fraction at pos0 by the fraction at pos1
    fc.remove(1);         // removed 'b'
    fc.print();
    fc.remove(a);
    fc.print();
    fc.insert(d);
    fc.insert(0, e); // insert at pos0
    fc.insert(f);
    fc.insert(g);
    fc.print();
    fc.remove(); // removed the last fraction
    fc.print();  // notice the output
    return 0;
}