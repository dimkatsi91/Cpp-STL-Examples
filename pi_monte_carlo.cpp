#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>

using namespace std;

# define REAL_PI           3.14159265358979323846  /* pi nearly perfect approximation */

template<class type>
class Point {
public:
  type x;
  type y;
};


class PI : public Point<double> {
private:
  Point<double> point;
public:
  void monte_carlo() {
	
	/* N_in represents the points that fall inside quarter of the circle
	   N represents the iterations for approximation minimum error
	   Dividing by total number N essentially I normalize the distribution
	   Multiplying with 4 comes from the circle quarter usage 
	*/
	int N, N_in = 0;			
	cout << "Please enter iterations: ";
	cin  >> N;
	double hyp = 0.0, pi = 0.0, error = 0.0;

	for(int i=0; i<N; i++) {

		point.x = ((double) rand() / (RAND_MAX));
		point.y = ((double) rand() / (RAND_MAX));
		hyp = sqrt(point.x*point.x + point.y*point.y);

		N_in   += ( hyp <= 1.0  ?  1  : 0 );
	}		
	
	pi = (double) 4*N_in/N;
	error = abs(pi - REAL_PI);
	cout << "PI ~= " << pi << endl;
	cout << "ERROR = " << setprecision(2) << error*100 << " %\n";
  }		

};



main() {

	PI pi;
	pi.monte_carlo();

}
