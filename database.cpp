/* Develop an object oriented program in C++ to create a database of student information
system containing the following information: Name, Roll number, Class, division, Date of
Birth, Blood group, Contact address, telephone number, driving license no. and other.
Construct the database with suitable member functions for initializing and destroying the
data viz constructor, default constructor, Copy constructor, destructor, static member
functions, friend class, this pointer, inline code and dynamic memory allocation
operators-new and delete */

#include <iostream>
class student
{
    public:
    char Name[20], Class[2], div[1], dob[10], bgr[2], addr[140];
    unsigned int Rollno, Telno;
    void getdata()
    {
        std::cout << "Enter Name: ";
        std::cin.getline(Name, 20);
        std::cout << "Enter Class: ";
        std::cin.getline(Class, 2);
        std::cout << "Enter Division: ";
        std::cin.getline(div, 1);
        std::cout << "Enter Date of Birth: ";
        std::cin.getline(dob, 10);
        std::cout << "Enter Blood Group: ";
        std::cin.getline(bgr, 2);
        std::cout << "Enter Contact Address: ";
        std::cin.getline(addr, 140);
        std::cout << "Enter Roll No.: ";
        std::cin >> Rollno;
        std::cout << "Enter Telephone number: ";
        std::cin >> Telno;
    }
    void setdata()
    {
        std::cout << "Name: " << Name << std::endl;
        std::cout << "Class: " << Class << std::endl;
        std::cout << "Division: " << div << std::endl;
        std::cout << "Date of Birth: " << dob << std::endl;
        std::cout << "Blood Group: " << bgr << std::endl;
        std::cout << "Contact Address: " << addr << std::endl;
        std::cout << "Roll Number: " << Rollno << std::endl;
        std::cout << "Telephone Number " << Telno << std::endl;
    }
};

int main()
{
    int n;
    std::cout << "Enter strength of class: ";
    std::cin >> n;
    student obj[n];
    std::cout << "------------------------------------"<< std::endl;
    for (int i=0; i<n; i++)
    {
        std::cout << "Enter details of student " << i+1 << ":" << std::endl;
        obj[i].getdata();
        std::cout << "------------------------------------"<< std::endl;
    }
    std::cout << "------------------------------------"<< std::endl;
    for (int i=0; i<n; i++)
    {
        std::cout << "Student " << i+1 << ":" << std::endl;
        obj[i].setdata();
        std::cout << "------------------------------------"<< std::endl;
    }
    return 0;
}