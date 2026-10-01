#include <iostream>

// C++ style struct declaration
struct MyStruct
{
    char name[20];
    float volume;
    double price;
};

// 位域
struct Date
{
    unsigned int day : 5;   // 1-31日，需要5个bit (2^5=32)
    unsigned int month : 4; // 1-12月，需要4个bit (2^4=16)
    unsigned int year : 7;  // 0-127年，需要7个bit (2^7=128)
};

// 位域测试
struct BitFieldTest
{
    unsigned char bit1 : 1; // 1 bit
    unsigned char bit2 : 1; // 1 bit
    unsigned char bit3 : 6; // 6 bit
}; // 1 byte

// 匿名位域：
struct HardwareRegister {
    unsigned int mode : 3;      // 0-2 位
    unsigned int : 5;           // 3-7 位，5个bit的填充（未使用）
    unsigned int interrupt : 1; // 8 位
    unsigned int : 0;           // 特殊用法：强制下一个字段对齐到下一个基本单元边界
    unsigned int data : 8;      // 将从一个新的 unsigned int 开始
};


void WhatsBitField()

{
    // 初始化，像普通结构体一样
    Date my_date = {25, 9, 26}; // {day, month, year}
    // 如果初始化时，为一个bitfeild位域属性赋值超过其大小，不会报错，但会有警告，结果相当于求余运算

    // 访问，也像普通结构体一样
    std::cout << "Date: " << my_date.year << "-" << my_date.month << "-" << my_date.day << std::endl;

    // 查看其大小，远小于三个独立int的大小
    std::cout << "Size of unsigned int: " << sizeof(unsigned int) << " bytes" << std::endl;
    std::cout << "Size of Date struct: " << sizeof(Date) << " bytes" << std::endl;

    // 初始化
    BitFieldTest bfTest {0, 1, 32};

    std::cout << "Size of unsigned char: " << sizeof(unsigned char) << " bytes" << std::endl;
    std::cout << "Size of bool: " << sizeof(bool) << " bytes" << std::endl;
    std::cout << "Size of BitFieldTest: " << sizeof(BitFieldTest) << " bytes" << std::endl;
    std::cout << "BitFieldTest: flag1=" << (int)(bfTest.bit1) << " flag2=" << (int)(bfTest.bit2) << " flag3=" << (int)(bfTest.bit3) << std::endl;

    // uintptr_t tmp = &bfTest.bit1;   //  位域不能取地址
}


void ArryStruct()
{
    using namespace std;
    MyStruct arr[10] { { "test", 0.233, 22.33L} };  // 默认 0 初始化
    for( int idx=0;idx<10;++idx )
    {
        cout << "Struct " << idx << ": " << arr[idx].name << " for $";
        cout << arr[idx].price << endl;
    }
}

void WhatsStruct()
{
    using namespace std;

    MyStruct stc1 = { "sunflowers", 0.20, 12.49 };
    MyStruct stc2;

    cout << "Struct 1: " << stc1.name << " for $";
    cout << stc1.price << endl;

    stc2 = stc1;    // 测试结构体struct的默认赋值运算符
    cout << "Struct 2 after assginment" << stc2.name << "for $";
    cout << stc2.price << endl;
}

int main()
{
    // WhatsStruct();
    WhatsBitField();
    // ArryStruct();
    return 0;
}