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
int char_type(char c);
bool an_alphabet(char c);
bool a_digit(char c);
bool an_operator(char c);
bool a_power(char c);
bool a_bracket(char c);
void partitioning_equation(string equation);
void as_algebric(string equation);
int check_u_or_uplusv(string equation);
void show_as_uplusv(string equation);
#endif