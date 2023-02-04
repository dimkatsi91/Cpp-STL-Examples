/* 
 * Prime numbers: A prime number is a whole number greater than 1 whose only factors are 1 and itself
*/

#include <iostream>
#include <vector>
using namespace std;

class Numbers {
public:
    Numbers(int n) : N(n) {}
    ~Numbers() {}
    bool isPrime(int n) {
        if(n==0 || n==1) { return true; }
        int i=2;
        while(i!=n) {
            if(n%i == 0) { return false; }
            i++;
        }
        return true;
    }
    void findPrimes() {
        int i=1;
        while(i != N) {
            if(isPrime(i)) {
                primes.push_back(i);
            }
            i++;
        }
    }
    void printPrimes() {
        vector<int>::iterator itr = primes.begin();
        while(itr++ != primes.end()) {
            cout << *itr << " ";
        }
    }
    int getPrimes() {
        return primes.size();
    }
private:
    // Find how many prime numbers exist inside the set [0, N] 
    int N;
    vector<int> primes{};
};

int main() {

    int N =10000;
    Numbers primes(N);
    primes.findPrimes();
    primes.printPrimes();
    cout << endl;
    cout << "Primes inside set [0, " << N << " ] = " << primes.getPrimes() << endl;

    return 0;
}