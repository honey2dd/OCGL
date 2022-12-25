/*Write a function template selection Sort. Write a program that inputs, sorts and outputs 
an integer array and a float array.*/
#include<iostream>
using namespace std;
#define n 20
template<class T>
void search(T arr[n])
{
     int i,j;
     int size;
     i=0;
     j=1;
     for (int i=0;i<size;i++)
     {
         for(int j=i+1;j<size;j++)
         {
            if(arr[i]>arr[j])
            {
                T temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
         }
     }   
    cout<<"sorted array:"<<endl;
    for (int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int size;
    cout<<"enter size:";
    cin>>size;
    int arr1[size];
    float arr2[size];
    cout<<"enter elements in integer array:"<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>arr1[i];
    }
    search(arr1);
    cout<<endl;
    cout<<"enter elements in floating point array:"<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>arr2[i];
    }
    search(arr2);
    return 0;
}

