#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP
#include <iostream>
#include <vector>
#include <utility>
class Polynomial{
	public:
	
	Polynomial(std::vector<double> elem);
	Polynomial();
	Polynomial(Polynomial const &) = default;

	int degree()const;
	double evaluate(double const x);

	Polynomial &operator +=(Polynomial const &);
  	Polynomial &operator -=(Polynomial const &);
  	Polynomial &operator *=(Polynomial const &);
  	
  
  	friend Polynomial operator+(Polynomial const &,Polynomial const &);
  	friend Polynomial operator-(Polynomial const &,Polynomial const &);
  	friend Polynomial operator*(Polynomial const &,Polynomial const &);
  	friend std::pair<Polynomial,Polynomial> operator/(Polynomial const &,Polynomial const &);

  	friend std::ostream & operator << (std::ostream &, Polynomial const &);
  	
  	friend std::istream & operator >> (std::istream &, Polynomial &);



	private:
	std::vector<double> coeff;
	void P_normalize();

	

};
#endif
