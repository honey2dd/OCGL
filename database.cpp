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
    char Name[25], Class[5], div[5], dob[15], bgr[5], addr[150];
    unsigned int Rollno, Telno;
    student()
    {
        std::cout << "------------------------------------"<< std::endl;
        std::cout << "Enter Name: ";
        (std::cin >> std::ws).getline(Name, 25);
        std::cout << "Enter Class: ";
        (std::cin >> std::ws).getline(Class, 5);
        std::cout << "Enter Division: ";
        (std::cin >> std::ws).getline(div, 5);
        std::cout << "Enter Date of Birth: ";
        (std::cin >> std::ws).getline(dob, 15);
        std::cout << "Enter Blood Group: ";
        (std::cin >> std::ws).getline(bgr, 5);
        std::cout << "Enter Contact Address: ";
        (std::cin >> std::ws).getline(addr, 150);
        //The std::ws is a manipulator, that will skip all the leading whitespaces
        //This is done because the getline() method of the std::cin stream object takes the input
        //until a \n character is used.
        //So, if a \n character is already stored in the buffer, the getline() may skip the input entirely.
        std::cout << "Enter Roll No.: ";
        std::cin >> Rollno;
        std::cout << "Enter Telephone number: ";
        std::cin >> Telno;
        std::cout << "------------------------------------"<< std::endl;
    }
/* 
//If you want to use the string header, first
#include <string> 
class student
{
    public:
    std::string Name, Class, div, dob, bgr, addr;
    unsigned int Rollno, Telno;
    student()
    {
        std::cout << "Enter details of student " << ;
        std::cout << "------------------------------------"<< std::endl;
        std::cout << "Enter Name: ";
        std::getline(std::cin >> std::ws, Name);
        std::cout << "Enter Class: ";
        std::getline(std::cin >> std::ws, Name);
        std::cout << "Enter Division: ";
        std::getline(std::cin >> std::ws, Name);
        std::cout << "Enter Date of Birth: ";
        std::getline(std::cin >> std::ws, Name);
        std::cout << "Enter Blood Group: ";
        std::getline(std::cin >> std::ws, Name);
        std::cout << "Enter Contact Address: ";
        std::getline(std::cin >> std::ws, Name);
        //Note: Here, we have used the std::getline() function which is actually
        //a part of the string header which we have included.
        //The std::ws has the same application here as above.
        std::cout << "Enter Roll No.: ";
        std::cin >> Rollno;
        std::cout << "Enter Telephone number: ";
        std::cin >> Telno;
        std::cout << "------------------------------------"<< std::endl;

    }
 */
    void display()
    {
        std::cout << "------------------------------------"<< std::endl;
        std::cout << "Name: " << Name << std::endl;
        std::cout << "Class: " << Class << std::endl;
        std::cout << "Division: " << div << std::endl;
        std::cout << "Date of Birth: " << dob << std::endl;
        std::cout << "Blood Group: " << bgr << std::endl;
        std::cout << "Contact Address: " << addr << std::endl;
        std::cout << "Roll Number: " << Rollno << std::endl;
        std::cout << "Telephone Number " << Telno << std::endl;
        std::cout << "------------------------------------"<< std::endl;
    }
};

int main()
{
    int n;
    std::cout << "Enter strength of class: ";
    std::cin >> n;
    student obj[n];
    std::cout << '\n';
    for (int i=0; i<n; i++)
    {
        std::cout << "Student " << i+1 << ":" << std::endl;
        obj[i].display();
    }
    return 0;
}
