#include <string>
using namespace std;
string a[]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
int keypad(int num, string output[]){
   if(num==0)
   {
       output[0]="";
       return 1;
   }
    int b=num%10;
    num=num/10;
    int c=keypad(num,output);
    for(int i=0;i<a[b-2].size()*c;i++)
    {output[c+i]=output[i%c];
    }
    int i=0;
    for(int j=0;j<a[b-2].size();j++)
    {
        for(;i<c*(j+1);i++)
            output[i]=output[i]+a[b-2][j];
    }
    return c*a[b-2].size();
}