#include <iostream>
#include <vector>
#include <thread>

using namespace std;

class ThreadingClass {
public:
    // Calculate the sum S(0...n) recursively
    int rec_sum(int num) {
        if(num<0)
            return -1;
        if(num==0 || num==1)
            return num;
        return num + rec_sum(num-1);        
    }
    // Simple recursive factorial function
    int rec_fact(int num) {
        if(num<0)
            return -1;
        if(num==0 || num==1)
            return 1;
        return num*rec_fact(num-1);
    }
    // Simple void factorial function to call the recursive factorial function !
    void fact(int num) {
        cout << "From Thread ID : "<< this_thread::get_id() << "\n";
        cout << num << "! = " << rec_fact(num) << endl;
    }
};

int main()
{
    ThreadingClass *diman = new ThreadingClass();
    // Calculate the sums as regular
    cout << "Main Thread ID : "<< this_thread::get_id() << "\n";
    for(auto num=1; num<11; num++)
        cout << "SUM(0..." << num << ") = " << diman->rec_sum(num) << endl;
    // Calculate the factorials using a thread
    ThreadingClass threadedObject;
    vector<thread> threads_vector(10);
    for(int num=1; num<11; num++)
    {
        threads_vector[num-1] = thread( &ThreadingClass::fact, &threadedObject, num );
        threads_vector.push_back(move(threads_vector[num-1]));
    }

    for(auto& thread : threads_vector)
        if(thread.joinable())
            thread.join();

    return 0;
}