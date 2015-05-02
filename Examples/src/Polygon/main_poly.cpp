#include "Polygon.hpp"
#include <iostream>
//! Main program
int main()
{
  using namespace Geometry;

  //! five vertices
  Vertices v(5);

  v[0]={0.5,0.5}; //C++11 sintax!
  v[1]={0.5,0.8};
  v[2]={0.0,0.0};
  v[3]={0.0,-1.0};
  v[4]={0.3,-0.5};

  Polygon aPolygon(v);
  aPolygon.showMe();
  std::cout<<"Area: "<<aPolygon.area()<<std::endl;
  // A triangle built with the first 3 vertices
  Triangle aTriangle(Vertices(v.begin(),v.begin()+3));
  AbstractPolygon * p_ab=&aTriangle;

  p_ab->showMe();
  std::cout<<"Area: "<<aTriangle.area()<<std::endl;
  //! Unit Square
  //C++11 syntax. I expoit the fact that the is an implicit conversion
  //between initializer lists and pairs and Point2d has a constructor taking a pair<double>
  //as argument 
  // In C++98 I would have written
  //Square aSquare(Point2D(0.0,0.0),1.0); 
  Square aSquare({0.0,0.0},1.0);
  Square s2(aSquare); 
  p_ab=&s2;
  p_ab->showMe();
  std::cout<<"Area: "<<aSquare.area()<<std::endl;
}
  

