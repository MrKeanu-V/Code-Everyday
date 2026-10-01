#include <cstdint>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <limits>

void whats_float()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield); // fixed-point
    float tub = 10.0 / 3.0;      // good to about 6 places
    double mint = 10.0 / 3.0;    // good to about 15 places
    const float million = 1.0e6;

    cout << "tub = " << tub;
    cout << ", a million tubs = " << million * tub;
    cout << ",\nand ten million tubs = ";
    cout << 10 * million * tub << endl;

    cout << "mint = " << mint << " and a million mints = ";
    cout << million * mint << endl;
    
    // Output:
    /* clang++ floatnum.cpp -o floatnum_clang
    tub = 3.333333, a million tubs = 3333333.250000,
    and ten million tubs = 33333332.000000
    mint = 3.333333 and a million mints = 3333333.333333
    */
}

void float_add()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield); // fixed-point
    auto a = 2.3456789101112E+22L;
    long double b = a + 1.0E+0L;
    long double c = b - a;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    cout << "1.0E+0L = " << 1.0E+0L << endl;

    // Output:
    /* clang++ floatadd.cpp -o floatadd_clang
    a = 23456789101112002084864.000000
    b = 23456789101112002084864.000000
    c = 0.000000
    1.0E+0L = 1.000000
    */
}

/**
 * IEEE 754 浮点数表示法
 * | 符号位 S | 指数位 E | 尾数位 M |
 * | 1 bit   | 8 bits  | 23 bits | float 32bits
 * | 1 bit   | 11 bits | 52 bits | double 64bits
 * | 1 bit   | 15 bits | 112 bits | long double 128bits
 * 
 * 计算公式：(-1)^S * (1.M) * 2^(E-127) for float
 *         (-1)^S * (1.M) * 2^(E-1023) for double
 *         (-1)^S * (1.M) * 2^(E-16383) for long double
 */

int main()
{
    // 0 10000110 01100100010000000000000
    float x = 178.125f;
    std::uint32_t bits;
    std::memcpy(&bits, &x, sizeof bits);

    // std::hex 输出十六进制，std::showbase 显示前缀 0x
    // 类似的还有 std::dec 输出十进制，std::oct 输出八进制，
    // 二进制则是 C++20 新增的 std::format("{:b}", bits) 或 std::bitset<32>(bits)
    std::cout << "178.125f = ";
    std::cout << std::hex << std::showbase << bits << '\n';

    // 输出不同浮点数的有效位数和范围
    std::cout << std::dec; // 恢复十进制输出
    std::cout << "float: " << std::numeric_limits<float>::digits10 << " digits, range: [" 
              << std::numeric_limits<float>::lowest() << ", "
              << std::numeric_limits<float>::max() << "]\n";
    std::cout << "double: " << std::numeric_limits<double>::digits10 << " digits, range: [" 
              << std::numeric_limits<double>::lowest() << ", "
              << std::numeric_limits<double>::max() << "]\n";
    std::cout << "long double: " << std::numeric_limits<long double>::digits10 << " digits, range: [" 
              << std::numeric_limits<long double>::lowest() << ", "
              << std::numeric_limits<long double>::max() << "]\n";
    // 输出浮点数的bitwidth和指数范围
    std::cout << "float: " << std::numeric_limits<float>::digits << " bits, exponent range: [" 
              << std::numeric_limits<float>::min_exponent << ", "
              << std::numeric_limits<float>::max_exponent << "]\n";
    std::cout << "double: " << std::numeric_limits<double>::digits << " bits, exponent range: [" 
              << std::numeric_limits<double>::min_exponent << ", "
              << std::numeric_limits<double>::max_exponent << "]\n";
    std::cout << "long double: " << std::numeric_limits<long double>::digits << " bits, exponent range: [" 
              << std::numeric_limits<long double>::min_exponent << ", "
              << std::numeric_limits<long double>::max_exponent << "]\n";
}