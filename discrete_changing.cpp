#include <iostream>
#include <sys/time.h>
#include <iostream>
#include <random>
#include <vector>

int random(int low, int high)
{
    return low + rand() % (high - low + 1);
}

int main() {
  std::vector<float> weights = {}; // each weight is an item in data structure
  std::default_random_engine generator;
  
  for(int i = 0; i < 100000; i++){
    weights.push_back(random(1,10));
  }	      

  //start time
  struct timeval start, end;
  gettimeofday(&start, NULL);
  std::discrete_distribution<> selector(weights.begin(), weights.end());
  for (int i = 0; i < 100000; i++){
    int index = selector(generator);
    weights[index] = random(1,10);
    selector = std::discrete_distribution<>(weights.begin(), weights.end());
  }

  //end time
  gettimeofday(&end, NULL);
  double elapsedtime_sec = double(end.tv_sec - start.tv_sec) + 
    double(end.tv_usec - start.tv_usec)/1000000.0;
  std::cout << "Time: " << elapsedtime_sec << std::endl;
}
 
