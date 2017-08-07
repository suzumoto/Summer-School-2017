#include<cmath>
#include<iostream>
#include<boost/random.hpp>

inline double V(double x){
  return x*x;
}

int main(){
  boost::mt19937 eng(39201);
  boost::variate_generator<boost::mt19937&,boost::uniform_real<> > random(eng,boost::uniform_real<>());
  for(double x = -3; x <= 3; x = x + 0.01){
    std::cout << x << " " << V(x) << " " << std::exp(-V(x))*5 << std::endl;
  }
  return 0;
}
