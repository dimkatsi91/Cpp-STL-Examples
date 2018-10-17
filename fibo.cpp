#include <iostream>
#include <vector>

using namespace std;

vector<int> fibo_nums;

void find_fibo(int limit) {
  /* ------------- */
  int sum = 0;
  vector<int>::iterator itr = fibo_nums.begin();
  for(int i=0; i<limit; i++)
    if( i==0 || i==1 )
      fibo_nums.push_back(i);
    else {
      fibo_nums.push_back( fibo_nums[i-1] + fibo_nums[i-2] );
      itr++;
    }
}

void print() {
  vector<int>::iterator itr = fibo_nums.begin();
  while(itr!=fibo_nums.end()) {
    cout << *itr << " ";
    itr++;
  }
  cout << "\n";
}


main() {

  find_fibo(21);
  print();

  return 0;
}
