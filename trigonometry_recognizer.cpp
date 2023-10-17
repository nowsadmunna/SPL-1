#include<iostream>
#include"header.h"
using namespace std;
int which_trigonometry=0;
int kt=0;
bool check_trigonometry_funtion(string equation)
{
   int ln_count=500,trigonometry_count=500,root_count=500;
   int i;
   for(i=0;equation[i]!='\0';i++)
   {
       if(equation[i]=='l' && equation[i+1]=='n')
       {
           ln_count=i;
       }
       else if(equation[i]=='s' && equation[i+1]=='q' && equation[i+2]=='r' && equation[i+3]=='t')
       {
           root_count=i;
       }

       else if(equation[i]=='t' || equation[i]=='s' || equation[i]=='c')
       {
           trigonometry_count=i;
       }
   }
   if(ln_count<trigonometry_count)
   {
       return false;
   }
   if(root_count<trigonometry_count)
   {
       return false;
   }
   for(i=0;equation[i]!='\0';i++)
   {
       if(equation[i]=='s' && equation[i+1]=='i' && equation[i+2]=='n')
       {
           which_trigonometry=1;
           return true;
       }
       else if(equation[i]=='t' && equation[i+1]=='a' && equation[i+2]=='n')
       {
           which_trigonometry=3;
           return true;
       }
       else if(equation[i]=='s' && equation[i+1]=='e' && equation[i+2]=='c')
       {
           which_trigonometry=5;
           return true;
       }
       else if(equation[i]=='c' && equation[i+1]=='o' && equation[i+2] =='s' && equation[i+3]=='e' && equation[i+4]=='c')
       {
           which_trigonometry=2;
           return true;
       }
       else if(equation[i]=='c' && equation[i+1]=='o' && equation[i+2]=='s')
       {
           which_trigonometry=4;
           return true;
       }
       else if(equation[i]=='c' && equation[i+1]=='o' && equation[i+2]=='t')
       {
           which_trigonometry=6;
           return true;
       }
   }
   if(which_trigonometry==0)
   {
       return false;
   }
}
int derivative_sign_of_trigonometry()
{
    return which_trigonometry;
}


