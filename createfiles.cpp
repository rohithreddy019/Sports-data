#include<fstream>
#include<iostream>
#include<string.h>
#include "CreateFiles.h"
using namespace std;
int main()
{
  char filename[30];
  cout<<"Enter the filename of the file\n";
  ofstream out;
  cin>>filename;
  out.open(filename,ios::binary);
  sportdata m[2];
  for(int i=0;i<2;i++)
    m[i].create();
  for(int i=0;i<2;i++)
    out.write((char*) &m[i],sizeof(m[i]));
  out.close();
  return 0;
}
