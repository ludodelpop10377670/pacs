#include <iostream>
#include <vector>
#include <utility>
#include "polynomial.hpp"

int main(){
	std::vector<double> a={1.,1.,1.,1.};
	std::vector<double> b={2.,1.,4.,1.};
	std::vector<double> c={3.,0.,5.,0.};
	std::vector<double> d={1.,1.,1.};
	std::vector<double> e={2.,3.,2.};

Polynomial p1(a);
Polynomial p2(b);
Polynomial p3(c);
Polynomial p4(d);
Polynomial p5;
Polynomial p6;
Polynomial p7(e);
Polynomial p8;

std::pair<Polynomial,Polynomial> div1,div2;

double x=1.;
auto y=p1.evaluate(x);
std::cout<<y<<std::endl;

p1-=p2;

p5=p3+p1;
p4*=p7;

div1 = p7/p2;
div2 = p3/p7;

std::cout<<p1<<std::endl;
std::cout<<p5<<std::endl;
std::cout<<p4<<std::endl;
std::cout<<"Il quoziente é "<<div1.first<<" il resto é"<< div1.second<<std::endl;
std::cout<<"Il quoziente é "<<div2.first<<" il resto é"<< div2.second<<std::endl;


std::cout<<"Give me a Polynomial in the form 'degree' a,b,c;(polynomial's degree followed by a space)";
std::cin>>p8;
std::cout<<std::endl<<"I have read "<<p8<<std::endl;


return 0;
}


