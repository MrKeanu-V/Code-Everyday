#include <iostream>
#include <cstring>
#include <string>
using namespace std;

void whats_char()
{
    // char ch = '中';
    // cout << ch << endl;
    cout << "sizeof(char) = " << sizeof(char) << endl;
    // char8_t str[] = u8"中";     // 明确这是 UTF-8 字节流，占 3 个 char8_t
    // cout << str << endl;
    // cout << "sizeof(char8_t) = " << sizeof(char8_t) << endl;
    char32_t ch = U'中';        // 明确这是一个完整的 32 位码点，占 4 字节，大小永远不变
    // cout << ch << endl;
    size_t size = sizeof(ch);
    cout << "sizeof(char32_t) = " << size << endl;
}

void whats_char_arry()
{
    // C style string
    char str1[] = "Hello" "World";
    cout << "sizeof(str1) = " << sizeof(str1) << endl; // 11 bytes (10 chars + null terminator)
    cout << "str1 = " << str1 << endl;

    // concatenation of string literals
    cout << "String 1" "String 2" << endl; // String 1String 2
    cout << "String 3 " 
            "String 4" << endl; // String 3 String 4
}

void overflow_char_arry()
{
    const int C_SIZE = 10;
    char str[C_SIZE];

    cout << "Length of str: " << strlen(str) << endl; // 未初始化的数组，strlen 可能返回随机值，逻辑和指针未初始化相同
    cout << "Uninitialized str: " << str << endl; // 未初始化的数组，输出可能是随机字符，甚至可能导致未定义行为

    cout << "Enter a string (max " << C_SIZE - 1 << " characters): ";
    cin >> str; // 输入超过 9 个字符时会发生缓冲区溢出，导致未定义行为
    cout << "You entered: " << str << endl;

    cout << "Enter a string with cin.getline (max " << C_SIZE - 1 << " characters): ";
    cin.ignore(); // 忽略上一次输入留下的换行符
    cin.getline(str, C_SIZE); // 安全读取，最多读取 9 个
    cout << "You entered: " << str << endl;

    // cin.get
    cout << "Enter a string with cin.get (max " << C_SIZE - 1 << " characters): ";
    cin.ignore(); // 忽略上一次输入留下的换行符
    cin.get(str, C_SIZE); // 安全读取，最多读取 9 个
    cout << "You entered: " << str << endl;
}


// 1. 验证字符串比较的区别
void demonstrateComparison() {
    std::cout << "\n===== 验证字符串比较 =====\n";
    
    char c_str1[] = "apple";
    char c_str2[] = "apple";
    std::string s_str1 = "apple";
    std::string s_str2 = "apple";

    // C 风格字符串比较：不能使用 ==，必须使用 strcmp 函数
    if (std::strcmp(c_str1, c_str2) == 0) {
        std::cout << "C 风格: c_str1 和 c_str2 内容相同 (使用 strcmp)\n";
    }
    
    // C++ string 比较：可以直接使用 == 运算符
    if (s_str1 == s_str2) {
        std::cout << "C++ string: s_str1 和 s_str2 内容相同 (使用 ==)\n";
    }
    
    // 陷阱：C 风格字符串用 == 比较的是内存地址（指针），而不是内容
    if (c_str1 == c_str2) {
        std::cout << "C 风格: 意外相等 (说明数组退化为同一地址指针)\n";
    } else {
        std::cout << "C 风格: c_str1 和 c_str2 地址不同 (使用 == 比较的是地址)\n";
    }
    // warning: comparison between two string arrays compare their addresses and will be deprecated in C++20 [-Wdeprecated]; to compare array addresses, use unary '+'
}

// 2. 验证字符串遍历和获取字符的区别
void demonstrateTraversal() {
    std::cout << "\n===== 验证字符串遍历 =====\n";
    
    char c_str[] = "Hello";
    std::string s_str = "Hello";

    // C 风格字符串遍历：依赖末尾的 '\0' 终止符
    std::cout << "C 风格遍历: ";
    for (int i = 0; c_str[i] != '\0'; ++i) {
        std::cout << c_str[i];
    }
    std::cout << "\n";

    // C++ string 遍历：可以直接使用 size() 成员函数，或使用范围 for 循环
    std::cout << "C++ string 遍历: ";
    for (char c : s_str) {
        std::cout << c;
    }
    std::cout << "\n";
}

int strtype3()
{
    char charr1[20];
    char charr2[20] = "jaguar";
    string str1;
    string str2 = "panther";

    cout << "The string charr1 length is " << strlen(charr1) << endl;

    cout << "Uninitialized string charr1 is " << charr1 << endl;

    // assignment for string objects and character arrays
    str1 = str2;              // copy str2 to str1
    strcpy(charr1, charr2);   // copy charr2 to charr1

    // appending for string objects and character arrays
    str1 += " paste";         // add paste to end of str1
    strcat(charr1, " juice"); // add juice to end of charr1

    // finding the length of a string object and a C-style string
    int len1 = str1.size();      // obtain length of str1
    int len2 = strlen(charr1);   // obtain length of charr1

    cout << "The string " << str1 << " contains "
         << len1 << " characters.\n";
    cout << "The string " << charr1 << " contains "
         << len2 << " characters.\n";

    demonstrateComparison();
    demonstrateTraversal();

    return 0;
}

int main()
{
    // whats_char();
    // whats_char_arry();
    // overflow_char_arry();
    strtype3();

    return 0;
}