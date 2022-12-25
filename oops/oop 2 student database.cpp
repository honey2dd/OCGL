#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<iomanip>
using namespace std;
class Student
{
    private:
        int *roll_no,*DOB;                                      //for using "new" and "delete" keyword data are always
        char *name,*class1,*division,*blood_grp,*address;       //represented by using pointer
        long *mob_no;
        static int count;                                       //static variable
    public:
        Student();                                             //constructor
        ~Student();                                            //desteuctor
        void setdata();
        void showdata();
        void counter();
};
int Student::count;
 Student::Student()
{
    name=new char;                          //new keyword used for dynamic memory allocation
    roll_no=new int;
    class1=new char;
  division=new char;
    DOB=new int;
    blood_grp=new char;
    mob_no=new long;
    address=new char;
}
 Student::~Student()
{
    delete name;                                 //delete keyword used for memory deallocation
    delete roll_no;
    delete class1;
    delete division;
    delete DOB;
    delete blood_grp;
    delete mob_no;
    delete address;
    cout<<"Information is deleted "<<endl;
}

void Student::setdata()
{
    cout<<"Enter details of Student:"<<endl;
    cout<<"name :";
    cin >>name ;
    cout<<"roll_no :";
    cin>> *roll_no;
    cout<<"class1 :";
    cin>>class1;
    cout<<"division :";
    cin>>division;
    cout<<"DOB :";
    cin>> *DOB;
    cout<<"blood_grp :";
    cin>>blood_grp;
    cout<<"mob_no :";
    cin>>*mob_no;
    cout<<"address :";
    cin>>address;
}

void Student::showdata()
{
    cout<<"name :"<<name<<endl;
    cout<<"roll_no :"<<*roll_no<<endl;
    cout<<"class1 :"<<class1<<endl;
    cout<<"division :"<<division<<endl;
    cout<<"DOB :"<<*DOB<<endl;
    cout<<"blood_grp :"<<blood_grp<<endl;
    cout<<"mob_no :"<<*mob_no<<endl;
    cout<<"address :"<<address<<endl;
}

void Student::counter()
{
    count++;
    cout<<"student no :"<<count<<endl;
}

int main()
{
    int n;
    cout<<"Enter no of student: ";
    cin>>n;
    Student s[n];
    for(int i=0;i<n;i++)
    {
        s[i].setdata();
    }
    cout<<"************************"<<endl;
    for(int i=0;i<n;i++)
    {
        s[i].counter();
    }
    
    cout<<"Information of student :"<<endl;
    for(int i=0;i<n;i++)
    {
        s[i].showdata();
    }  
    return 0;
} 

