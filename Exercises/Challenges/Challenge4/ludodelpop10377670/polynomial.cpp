#include "polynomial.hpp"

Polynomial::Polynomial(std::vector<double> elem):coeff(elem){this->P_normalize();}
Polynomial::Polynomial(){this->coeff.push_back(0);}

int Polynomial::degree()const{
	auto d=this->coeff.size()-1;
	return d;
}

void Polynomial::P_normalize(){
	auto i=this->coeff.end()-1;
	while (*i == 0){
		this->coeff.erase(i);
		i--;
		}
}



double Polynomial::evaluate(double const x){
	double u = coeff.back();
  	for (int i = coeff.size()-2 ; i != -1; --i) 
    	u = u*x + coeff[i];
  	return u;
	
}


Polynomial &
Polynomial::operator +=(Polynomial const &r){
	
	if(coeff.size()<r.coeff.size())
		coeff.resize(r.coeff.size());
	
	for(unsigned int i=0;i<coeff.size();++i)
		coeff[i] += r.coeff[i];
	
	this->P_normalize();
	return *this;
}

Polynomial operator+(Polynomial const &l, Polynomial const &r){
	Polynomial tmp=l;
	tmp += r;
	return tmp;
}

Polynomial &
Polynomial::operator -=(Polynomial const &r){
	if(coeff.size()<r.coeff.size())
		coeff.resize(r.coeff.size());
	
	for(unsigned int i=0;i<coeff.size();++i)
		coeff[i] -= r.coeff[i];
	
	this->P_normalize();
	return *this;
}

Polynomial &
Polynomial::operator *=(Polynomial const &r){
	std::vector<double> tmp;
	tmp.resize(coeff.size()+r.coeff.size());
	for(unsigned int i=0;i<coeff.size();i++){
		for (unsigned int j=0;j<r.coeff.size();j++){
			tmp[i+j] += coeff[i]*r.coeff[j];
		}
	}
	coeff=tmp;
	this->P_normalize();
	
	return *this;
}

Polynomial operator *(Polynomial const &l, Polynomial const &r){
	Polynomial tmp=l;
	tmp*=r;
	return tmp;
}


std::pair<Polynomial,Polynomial> operator /(Polynomial const &l,Polynomial const &r){
	std:: pair<Polynomial,Polynomial> tmp;
	
	if(l.degree() < r.degree()){ 
		tmp.first.coeff.push_back(0);
		tmp.second=l;
		return tmp;
	}else{
	Polynomial quoz;
	Polynomial rest;
	quoz.coeff.resize(l.degree()-r.degree()+1);
	rest=l;
	while(rest.degree()>= r.degree()){
		quoz.coeff[rest.degree()-r.degree()]=rest.coeff[rest.degree()]/r.coeff[r.degree()];
		for(auto i=r.degree(); i>=0; i--)
			rest.coeff[rest.degree()-r.degree()+i]-=quoz.coeff[rest.degree()-r.degree()]*r.coeff[i];

		quoz.P_normalize();
		rest.P_normalize();
	}
	tmp.first=quoz;
	tmp.second=rest;
	return tmp;}
}

std::ostream & operator << (std::ostream & str, Polynomial const & r){
  	for (unsigned i=0;i<r.coeff.size()-1;i++)
	str << r.coeff[i] << 'x'<<'^'<<i<<'+';
	str << r.coeff[r.coeff.size()-1]<<'x'<<'^'<<r.coeff.size()-1;
	 
	return str;
}

std::istream & operator >> (std::istream & str, Polynomial & r){
	std::string tmp;
	unsigned gdr;
	double x;
	char vir;
	std::getline(str,tmp,';');
	std::size_t found=tmp.find(' ');
	std::istringstream s(tmp.substr(0,found));
	s >> gdr;
	std::istringstream f(tmp.substr(found+1,tmp.size()));
	r.coeff.resize(gdr+1);
	for(unsigned i=0; i<=gdr; ++i){
		f >> x;
		r.coeff[i] = x;
		f >> vir;
	}
	r.P_normalize();
	return str;
}	

