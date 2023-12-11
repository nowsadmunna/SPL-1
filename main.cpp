#include<iostream>
#include "header.h"
using namespace std;


int main()
{
     // cout<<"----------------Derivative Calculator-------------------"<<endl;
     // cout<<"### Some basic formula of differentiation are given below: "<<endl;
     // cout<<"1. Constant Formula:"<<endl;
     // cout<<"        d/dx(c)=0"<<endl;
     // cout<<"2. Power Formula:"<<endl;
     // cout<<"        d/dx(x^n)=nx^(n-1)"<<endl;
     // cout<<"3. Multiple Rule:"<<endl;
     // cout<<"        d/dx(cf(x))=c*d/dx(f(x))"<<endl;
     // cout<<"4. Sum Rule:"<<endl;
     // cout<<"        d/dx(f(x)+g(x))=d/dx(f(x))+d/dx(g(x))"<<endl;
     // cout<<"5. Difference Rule:"<<endl;
     // cout<<"        d/dx(f(x)-g(x))=d/dx(f(x))-d/dx(g(x))"<<endl;
     // cout<<"6. Product Rule:"<<endl;
     // cout<<"        d/dx(f(x)*g(x))=f(x)*d/dx(g(x))+g(x)*d/dx(f(x))"<<endl;
     // cout<<"7. Division Rule:"<<endl;
     // cout<<"        d/dx(f(x)/g(x))=(g(x)*d/dx(f(x))+f(x)*d/dx(g(x)))/(g(x))^2"<<endl;
     // cout<<"8. Expotential Rule:"<<endl;
     // cout<<"        d/dx(e^x)=e^x"<<endl;
     // cout<<"9. Logarithmic Rule:"<<endl;
     // cout<<"        d/dx(ln(x))=1/x"<<endl;
     // cout<<"10.Square Root Rule:"<<endl;
     // cout<<"        d/dx(sqrt(x))=1/(2*sqrt(x))"<<endl;
     // cout<<"11.Trigonometry Rule:"<<endl;
     // cout<<"       (i)   d/dx(sin(x))  =    cos(x)"<<endl;
     // cout<<"       (ii)  d/dx(cos(x))  =    - sin(x)"<<endl;
     // cout<<"       (iii) d/dx(sec(x))  =    sec(x)*tan(x)"<<endl;
     // cout<<"       (iv)  d/dx(cosec(x))=    - cosec(x)*cot(x)"<<endl;
     // cout<<"       (v)   d/dx(tan(x))  =    sec^2(x)"<<endl;
     // cout<<"       (vi)  d/dx(cot(x))  =    - cosec^2(x)"<<endl;
     string equation="sin(sin(56)+87)";
     string temporary;
     string answer=partition_based_on_operator(equation,temporary);
     cout<<"Answer= "<<answer<<endl;
     //cout<<check_ln_function(equation)<<endl;
     //equation="(-6)";
     //show_as_uplusv(equation);
     //  int c=stoi("-150");
     //  cout<<c<<endl;
     // check_trigonometry_funtion(equation);
     // cout<<as_trigonometry_function(equation)<<endl;
     //partitioning_equation(equation);
     // cout<<endl;
     //cout<<check_u_or_uplusv("(-5)*x")<<endl;
}
