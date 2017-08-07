#include<cmath>
#include<iostream>
#include<boost/random.hpp>

inline double V(double x){
  return x*x;
}

int main(){
  boost::mt19937 eng(43921);
  boost::variate_generator<boost::mt19937&,boost::uniform_real<> > random(eng,boost::uniform_real<>());
  double x = 0.0;
  double delta = 10;
  for(int i = 0; i < 1000; ++i){
    double trial = x + delta*(2*random() - 1);
    double rand = random();
    if(rand < std::exp(V(x) - V(trial))) x = trial;
    std::cout << i << " " << x << std::endl;
  }   
  return 0;
}
