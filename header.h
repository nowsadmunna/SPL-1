#ifndef HEADER_H
#define HEADER_H


#include<bits/stdc++.h>
using namespace std;


void display();
string removespaces(string equation);
bool check_uv_function(string equation);
string as_uv_function(string equation);
bool check_trigonometry_funtion(string equation);
int derivative_sign_of_trigonometry();
string as_trigonometry_function(string equation);

#endif