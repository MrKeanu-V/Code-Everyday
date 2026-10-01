#include <iostream>
/* Struct最大成员决定对齐边界：整个结构体的对齐模数（Alignment Requirement）为最大成员大小的倍数。 */

/* Anonymous Union */
struct MyStruct
{
    /* struct data */
    int m_int;      // 4B
    char m_ch;      // 1B -> 4B
    float m_fl;     // 4B -> 8B
    double m_db;    // 8B
    /* union data */
    union 
    {
        char m_strId[20];   // 20B
        long m_lgId;    // 8B
    };  // 20B -> 24B
};  // 37B, compiler auto align to 48B

struct TestStruct
{
    char m_ch;  // 1B
    int  m_int; // 4B
    long m_lg;  // 8B
    char m_id[20];  // 20B
};  // 33B, actually size 40B

int main()
{
    std::cout << "char size = " << sizeof(char) << "Bytes" << std::endl;    // 1B
    std::cout << "int size = " << sizeof(int) << "Bytes" <<std::endl;       // 4B
    std::cout << "long size = " << sizeof(long) << "Bytes" <<std::endl;     // 8B
    std::cout << "float size = " << sizeof(float) << "Bytes" <<std::endl;   // 4B
    std::cout << "double size = " << sizeof(double) << "Bytes" <<std::endl; // 8B
    std::cout << "std::string size = " << sizeof(std::string) << "Bytes" << std::endl;   // 24B

    std::cout << "TestStruct size = " << sizeof(TestStruct) << "Bytes" << std::endl;
    std::cout << "MyStruct size: " << sizeof(MyStruct) << "Bytes" << std::endl;
}