#include <iostream>

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

    friend std::ostream &operator <<(std::ostream &out, const complex &c);
    friend std::istream &operator >>(std::istream &in, complex &c);
};

std::istream &operator >> (std::istream &in, complex &c)
{
    std::cout << "Enter real part: ";
    in >> c.r;
    std::cout << "Enter imaginary part: ";
    in >> c.i;
    return in;
}

std::ostream &operator << (std::ostream &out, const complex &c)
{
    out << c.r << "+" << c.i << "i";
    return out;
}

int main()
{
    complex c1, c2, csum, cprod;
    std::cout << "The default value is: " << c1 << std::endl;
    std::cout << "Enter first complex number: " << std::endl;
    std::cin >> c1;
    std::cout << "Enter second complex number: " << std::endl;
    std::cin >> c2; 
    csum = c1 + c2;
    cprod = c1*c2; 
    std::cout << "The sum is: " << csum << std::endl;
    std::cout << "The product is: " << cprod << std::endl;
}