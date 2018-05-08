#include<iostream>
#include<fstream>
#include<string.h>
#include "CreateFiles.h"
int main()
{
    try
    {
    cout<<"Enter the section number to know the student names in a class\n";
    char stdname[30],fname[30];
    int n,l;
    cin>>n;
    if(n>3)
        throw "Invalid section input\n";
    ifstream in;
    if(n==1)
        strcpy(fname,"C1");
    else if(n==2)
        strcpy(fname,"C2");
    else if(n==3)
        strcpy(fname,"C3");
    in.open(fname,ios::binary);
    sportdata k[2];
    for(int i=0;i<2;i++)
        in.read((char*)&k[i],sizeof(k[i]));
    while(1)
    {
     for(int i=0;i<2;i++)
        cout<<i+1<<"."<<k[i].studname()<<"\n";
     cout<<"3.EXIT\n";
    cout<<"Enter the s.no of the student\n";
    cin>>l;
    if(l==3)
        break;
    k[l-1].display();
    }

    }
    catch(const char *j)
    {
        cout<<j;
    }
    return 0;
}
