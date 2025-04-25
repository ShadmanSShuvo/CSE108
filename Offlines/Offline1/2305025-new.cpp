#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return abs(a);
    return gcd(b, a % b);
}

class Fraction {
private:
    int numerator, denominator;
    void reduce() {
        if (denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }
        int g = gcd(numerator, denominator);
        numerator /= g;
        denominator /= g;
    }

public:
    Fraction() : numerator(0), denominator(1) {}
    Fraction(int n) : numerator(n), denominator(1) {}
    Fraction(int n, int d) {
        if (d == 0) {
            cout << "Invalid fraction with denominator 0. Setting to 0/1." << endl;
            numerator = 0;
            denominator = 1;
        } else {
            numerator = n;
            denominator = d;
            reduce();
        }
    }

    ~Fraction() {}

    Fraction add(const Fraction &f) const {
        return Fraction(numerator * f.denominator + f.numerator * denominator, denominator * f.denominator);
    }

    Fraction add(int n) const {
        return add(Fraction(n));
    }

    Fraction sub(const Fraction &f) const {
        return Fraction(numerator * f.denominator - f.numerator * denominator, denominator * f.denominator);
    }

    Fraction sub(int n) const {
        return sub(Fraction(n));
    }

    Fraction mul(const Fraction &f) const {
        return Fraction(numerator * f.numerator, denominator * f.denominator);
    }

    Fraction mul(int n) const {
        return Fraction(numerator * n, denominator);
    }

    Fraction div(const Fraction &f) const {
        if (f.numerator == 0) {
            cout << "Can not divide by 0" << endl;
            return Fraction(0, 1);
        }
        return Fraction(numerator * f.denominator, denominator * f.numerator);
    }

    Fraction div(int n) const {
        if (n == 0) {
            cout << "Can not divide by 0" << endl;
            return Fraction(0, 1);
        }
        return Fraction(numerator, denominator * n);
    }

    void print() const {
        if (denominator == 1)
            cout << numerator << endl;
        else
            cout << numerator << "/" << denominator << endl;
    }

    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }

    bool isEqual(const Fraction &f) const {
        return numerator * f.denominator == f.numerator * denominator;
    }

    bool isLessThan(const Fraction &f) const {
        return numerator * f.denominator < f.numerator * denominator;
    }
};

class FractionCollection {
private:
    Fraction *fractions;
    int maxlength, length;

public:
    FractionCollection(int maxlen = 10) {
        maxlength = maxlen;
        fractions = new Fraction[maxlength];
        length = 0;
    }

    ~FractionCollection() {
        delete[] fractions;
    }

    void insert(Fraction f) {
        if (length >= maxlength) {
            cout << "Array full, can't insert more." << endl;
            return;
        }
        fractions[length++] = f;
    }

    void insert(int pos, Fraction f) {
        if (length >= maxlength || pos > length || pos < 0) {
            cout << "Invalid position." << endl;
            return;
        }
        for (int i = length; i > pos; --i)
            fractions[i] = fractions[i - 1];
        fractions[pos] = f;
        length++;
    }

    void remove() {
        if (length > 0) length--;
    }

    void remove(int pos) {
        if (pos >= length || pos < 0) return;
        for (int i = pos; i < length - 1; ++i)
            fractions[i] = fractions[i + 1];
        length--;
    }

    void remove(Fraction f) {
        for (int i = 0; i < length; ++i) {
            if (fractions[i].isEqual(f)) {
                remove(i);
                return;
            }
        }
    }

    Fraction getmax() const {
        if (length == 0) return Fraction(0, 1);
        Fraction max = fractions[0];
        for (int i = 1; i < length; ++i) {
            if (max.isLessThan(fractions[i]))
                max = fractions[i];
        }
        return max;
    }

    Fraction getmin() const {
        if (length == 0) return Fraction(0, 1);
        Fraction min = fractions[0];
        for (int i = 1; i < length; ++i) {
            if (fractions[i].isLessThan(min))
                min = fractions[i];
        }
        return min;
    }

    Fraction add(int start, int end) const {
        Fraction sum(0);
        for (int i = start; i <= end && i < length; ++i)
            sum = sum.add(fractions[i]);
        return sum;
    }

    Fraction mul(int start, int end) const {
        Fraction product(1);
        for (int i = start; i <= end && i < length; ++i)
            product = product.mul(fractions[i]);
        return product;
    }

    Fraction sub(int pos1, int pos2) const {
        if (pos1 >= length || pos2 >= length) return Fraction(0, 1);
        return fractions[pos1].sub(fractions[pos2]);
    }

    Fraction div(int pos1, int pos2) const {
        if (pos1 >= length || pos2 >= length) return Fraction(0, 1);
        return fractions[pos1].div(fractions[pos2]);
    }

    void print() const {
        cout << "\nFractions\n-------------------------------\n";
        for (int i = 0; i < length; ++i) {
            cout << "Fraction " << i << ": ";
            fractions[i].print();
        }
        if (length > 0) {
            cout << "Max: "; getmax().print();
            cout << "Min: "; getmin().print();
            cout << "Summation: "; add(0, length - 1).print();
            cout << "Multiplication: "; mul(0, length - 1).print();
        }
        cout << endl;
    }
};

int main()
{

    // sample main code from offline
    // create Fraction with numerator, denominator
    Fraction a(5, 2), b(7, 2), c(9, 2), d(28, 5);
    cout << "Fraction" << endl;
    cout << "-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -" << endl;
    cout << "A: ";
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