#ifndef HEADER_H
#define HEADER_H


#include<bits/stdc++.h>
using namespace std;

void display();
string removespaces(string equation);
bool check_uv_function(string equation);
string as_uv_function(string equation);
int check_trigonometry_funtion(string equation);
int derivative_sign_of_trigonometry();
string as_trigonometry_function(string equation,string temporary);
int char_type(char c);
bool an_alphabet(char c);
bool a_digit(char c);
bool an_operator(char c);
bool a_power(char c);
bool a_bracket(char c);
string partitioning_equation(string equation);
void as_algebric(string equation);
int check_u_or_uplusv(string equation);
void show_as_uplusv(string equation);
string calculate_derivative(char variable,int power,int coefficient,char sign);
string initial_checking(string equation,string temporary);
string partition_based_on_operator(string equation,string temporary);
string remove_bracket(string equation);
bool check_udivv_function(string equation);
string as_udivv(string equation);
string inside_of_bracket(string equation);
int check_ln_function(string equation);
string as_ln_function(string equation,string temporary);
int check_square_root_function(string equation);
string as_square_root_function(string equation,string temporary);
int check_expotentail_function(string equation);
string as_expotential_function(string equation,string temporary);
string for_return_temporary();
#endif