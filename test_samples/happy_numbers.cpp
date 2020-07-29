#include <iostream>
#include <vector>

using namespace std;

// This function returns a vector of integers
// integers are the digits of the num
// For example :: 
// Input: 13
// Output:  vector<int> digits{1,3}
//
vector<int> digits_of_num(int num)
{
    vector<int> digits{};
    while(num!=0)
    {
        digits.push_back(num%10);
        num /= 10;
    }
    return digits;
}

// Just calculate the sum of sdquares of integers of a vector
//
int calc_squares_sum(vector<int> nums)
{
    int sum=0;
    for(auto & num : nums)
        sum += num*num;
    return sum;
}


// This function checks if an integer number is a happy number or not
// returns a string "happy" or "sad"
// Happy number is a number that eventually reaches '1' when replaced
// by the sum of the square of each digit
//
string is_happy(int num)
{
    int tmp = num;
    int counter=0;

    if(num==1)
        return "happy";
    if(num<=0)
        return "sad";
    
    while(num!=1) {
        num = calc_squares_sum(digits_of_num(num));
        if(num==1) {
            return "happy";
        }
        if(num==tmp || counter>1000) {
            return "sad";
        }
        counter++;
    }
    // add this just for the compiler .. !
    return "sad";
}


int main() 
{
    /*
    cout << "32 is ... " << is_happy(32) << endl;
    cout << "7 is ... " << is_happy(7) << endl;
    cout << "28 is ... " << is_happy(28) << endl;
    cout << "30 is ... " << is_happy(30) << endl;
    cout << "9 is ... " << is_happy(9) << endl;
    cout << "24 is ... " << is_happy(24) << endl;
    cout << "13 is ... " << is_happy(13) << endl;
    */
    //cout << "16 is ... " << is_happy(16) << endl;
    int happy_nums_sum=0;
    for(int i=0; i<101; i++)
    {
        if(is_happy(i)=="happy") {
            happy_nums_sum++;
            cout << i << " ";
        }
    }
    cout << endl;
    cout << "[0-100] --> Happy Numbers = " << happy_nums_sum << endl;

    return 0;
}


/* OUTPUT ::

32 is ... happy
7 is ... happy
28 is ... happy
30 is ... sad
9 is ... sad
24 is ... sad
13 is ... happy
16 is ... sad

*/

