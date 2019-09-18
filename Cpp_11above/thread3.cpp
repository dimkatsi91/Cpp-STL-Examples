#include "header_one.h"

#include <vector>

using namespace std;


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