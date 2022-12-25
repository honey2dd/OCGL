#include <iostream>
using namespace std;
class complex
{
    private:
    float r, i;
    public:
    complex()
    {
        r=0;
        i=0;
    }
    complex operator+(complex c)
    {
        complex add;
        add.r = r + c.r;
        add.i = i + c.i;
        return add;
    }
    complex operator*(complex c)
    {
        complex mult;
        mult.r = r*c.r - i*c.i;
        mult.i = r*c.i + i*c.r;
        return mult;
    }

    friend ostream &operator <<(ostream &out, const complex &c);
    friend istream &operator >>(istream &in, complex &c);
};

istream &operator >> (istream &in, complex &c)
{
    cout << "Enter real part: ";
    in >> c.r;
    cout << "Enter imaginary part: ";
    in >> c.i;
    return in;
}

ostream &operator << (ostream &out, const complex &c)
{
    out << c.r << "+" << c.i << "i";
    return out;
}

int main()
{
    complex c1, c2, csum, cprod;
    cout << "The default value is: " << c1 << endl;
    cout << "Enter first complex number: " << endl;
    cin >> c1;
    cout << "Enter second complex number: " << endl;
    cin >> c2; 
    csum = c1 + c2;
    cprod = c1*c2; 
    cout << "The sum is: " << csum << endl;
    cout << "The product is: " << cprod << endl;
}
