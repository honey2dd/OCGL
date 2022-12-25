#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
int main()
{
    char name[80];
    cout<<"Enter name of file:";
    cin>>name;
    
    ofstream fout;
    fout.open(name);
    
    if(!fout)
    {
        cout<<"Error occur";
        exit(1);
    }
    
    cout<<"writing to the file"<<endl;
    cout<<"Enter contents for file end with ctrl+D"<<endl;
    string data;
    while(getline(cin,data))
    {
        if(data == "^D")
            break;
        fout << data << endl;
    }
    fout.close();

    ifstream fin;
    fin.open(name);
    if(!fin)
    {
    cout<<"Error opening file\n";
    exit(1);
    }
    cout << "\nReading from the file" << endl;
    while(fin)
    {
    getline(fin,data);
    cout << data << endl;
    }

    fin.close();
    return 0;
}
