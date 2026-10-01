#include <iostream>
using namespace std;

// Same value
enum bits
{
    null, zero = 0,
    one, numera_one = 1,
    two = 2,
    four = 4,
    eight = 8,
};

int main()
{
    std::cout << "bits null = " << bits::null << std::endl;
    std::cout << "bits zero = " << bits::zero << std::endl;
    bits b = bits(6);
    cout << "bist 6 = " << b << std::endl;  // cout 6, UB
    return 0;
}