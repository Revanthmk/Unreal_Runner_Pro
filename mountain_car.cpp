/* This program is to evaluate derivative using 3 point method for different step sizes 'h' 
with single precision and double precision and compare it with the actual value to 
evaluate the absolute error involved*/
#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;
float func1(float x)
{
    float res = atan(x);
    return res;
}
double func2(double x)
{
    double res = atan(x);
    return res;
}
int main()
{
ofstream file("3pt_error.dat");
double N = 1;
double a = 10;
float exact1;
exact1 = 0.333333333333333333;
file<<"Single precision"<<endl;
file<<"h"<<"        "<<"Absolute error"<<endl;
for (N=1;N<=pow(10,8);N=N*10){
    float h1 = a/N;
    float diff1 = (func1((pow(2,0.5)+h1))-func1((pow(2,0.5))-h1))/(2*h1);
    cout<<diff1<<endl;
    file<<h1<<"      "<<abs((diff1-exact1))<<endl;
}
file<<endl;
cout<<endl;
double exact2 = 0.3333333333333333333333333333;
file<<"Double precision"<<endl;
file<<"h"<<"        "<<"Absolute error"<<endl;
for (N=1;N<=pow(10,16);N=N*10){
    double h2 = a/N;
    double diff2 = (func2((pow(2,0.5)+h2))-func2((pow(2,0.5))-h2))/(2*h2);
    cout<<diff2<<endl;
    file<<h2<<"      "<<abs((diff2-exact2))<<endl;
}
return 0;
}
