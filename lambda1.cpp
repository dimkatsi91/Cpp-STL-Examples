#include <iostream>
#include <vector>

using namespace std;

auto test = []( const vector<int> &vec ) {
  for(auto val : vec)
    cout << val << " ";
  cout << endl;
};

int main()
{
  vector<int> nums{};
  for(size_t i=100; i>=50; i-=10)   nums.push_back( i );
  test(nums);

  return 0;
}
