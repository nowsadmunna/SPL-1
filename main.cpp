#include<iostream>
#include "header.h"
using namespace std;


int main()
{
     // cout<<"----------------Derivative Calculator-------------------"<<endl;
     // cout<<"### Some basic formula of differentiation are given below: "<<endl;
     string equation="(5+15*x^3+5*x+6)/(5*x)";
     string answer=partition_based_on_operator(equation);
     cout<<"Answer= "<<answer<<endl;
}
