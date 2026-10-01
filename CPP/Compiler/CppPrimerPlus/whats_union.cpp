#include <iostream>

union MyUnion
{
    /* data */
    int m_int;  // 4B
    char m_ch;  // 1B
    float m_fl; // 4B
    double m_db;    // 8B
};  // max sizeof(m_data), so 8B

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

/* Type Punning */
union FloatConverter
{
    float value;
    uint8_t bytes[4];
};
union UIntConverter
{
    unsigned int value;
    uint8_t bytes[4];
};

int main()
{
    MyUnion data{'A'};  // 初始化时，仅能初始化一个值，默认初始化第一个成员

    std::cout << "MyUnion size: " << sizeof(MyUnion) << std::endl;
    std::cout << "Default data m_int: " << data.m_int << std::endl;

    data.m_ch = 'A';
    std::cout << "Set MyUnion char value: " << data.m_ch << std::endl;
    std::cout << "Current MyUnion size: " << sizeof(MyUnion) << std::endl;

    /* 输出未激活的成员时属于UB未定义行为
     * clang++ 和 g++ 都是直接读取了内存里的数据 */
    std::cout << "Unactivate MyUnion int value: " << data.m_int << std::endl;
    std::cout << "Unactivate MyUnion double value: " << data.m_db << std::endl;
    std::cout << "Unactivate MyUnion float value: " << data.m_fl << std::endl;

    /* 匿名结构体 */
    MyStruct data2;
    data2.m_lgId = 1000;

    std::cout << "MyStruct size: " << sizeof(MyStruct) << std::endl;
    std::cout << "MyStruct long ID value: " << data2.m_lgId << std::endl;
    std::cout << "MyStruct string ID value: " << data2.m_strId << std::endl;

    /* 类型双关 */
    FloatConverter fc {8.0f};
    std::cout << "FloatConverter: float value: " << fc.value << std::endl;
    std::cout << std::hex;
    for (auto b : fc.bytes) std::cout << (int)b << " "; // 不同编译器 字节序 不同

    UIntConverter uic {130};
    std::cout << std::dec;
    std::cout << "UIntConverter: unsigned int value=" << uic.value << std::endl;
    std::cout << std::hex;
    for (auto b : uic.bytes) std::cout << (int)b << " "; // 不同编译器 字节序 不同

    return 0;
}
