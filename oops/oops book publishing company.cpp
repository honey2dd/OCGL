#include<iostream>
using namespace std;
//*****Base class*****//
class Publication
{
    private:
        string title;
        float price;
    public:
    Publication(){};
        void set()
        {
            cout<<"title= ";
            cin>>title;
            cout<<"price= ";
            cin>>price;
        }
        void display()
        {
            cout<<"title= "<<title<<endl;
            cout<<"price= "<<price<<endl;
        }
};
//******drived class******//
class Book : public Publication
{
    private:
        int page_count;
    public:
    void set_book()
    {
        try
        {
            set();
            cout<<"Page count= ";
            cin>>page_count;
            
            if(page_count<=0)
                throw page_count;
        }
        catch(int x)
        {
            cout<<"invalid page count"<<endl;
            page_count=0;
        }
    }
    void display_book()
    {
        display();
        cout<<"page_count= "<<page_count<<endl;
    }
};
//*****derived class*****//
class Tape : public Publication
{
    private:
        float playing_time;
    public:
        void set_tape()
        {
            try
            {
                set();
                cout<<"playing_time= ";
                cin>>playing_time;
                
                if (playing_time<=0)
                    throw playing_time;
            }
            catch(float x)
            {
                cout<<"invalid time"<<endl;
                playing_time=0;
            }
        }
        void display_tape()
        {
            display();
            cout<<"playing_time= "<<playing_time<<endl;
        }
};

int main()
{
    Book B1;
    Tape T1;
    B1.set_book();
    cout<<"****************"<<endl;
    cout<<"Book information:"<<endl;
    B1.display_book();
    cout<<"****************"<<endl;
    T1.set_tape();
    cout<<"****************"<<endl;
    cout<<"tape information: "<<endl;
    T1.display_tape();
    return 0;
}
 

