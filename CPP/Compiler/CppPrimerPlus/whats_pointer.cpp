#include <iostream>

void hello_malloc()
{
    using namespace std;
    // C use malloc, free

    // C++ use new, delete
    int *ptr = new int;
    cout << "pointer value: " << ptr << endl;
    cout << "pointer dereference: " << *ptr << endl;    // 0
    delete ptr;
    ptr = nullptr;

    /* new array */
    int len = 0;
    cout << "Pls input length of arry: " << endl;
    cin >> len;
    int *pArr = new int [len];
    cout << "size of array pointer: " << sizeof(*pArr) << endl;  // 退化为指针后，无法再得到数组真实长度

    *pArr = {0};
    cout << "pArr[0]: " << pArr[0] << endl;
    pArr[0] = 1;
    pArr[2] = 3;
    pArr[1] = 2;
    pArr[10] = 10;  // over flow, but compiler will not check it, so be careful
    cout << "pArr[0]: " << pArr[0] << endl;
    cout << "pArr + 1: " << pArr + 1 << endl;
    pArr = pArr + 1; // pointer arithmetic, move to next element
    cout << "after 'pArr = pArr + 1' pArr[0]: " << pArr[0] << endl;

    // delete pArr;    // Undefined Behavior
    delete [] pArr; // must use delete []
    pArr = nullptr;
    delete ptr;    // delete nullptr is fine, won`t casue error
}

void pointer_dec()
{
    using namespace std;
    int *p1;    // C style
    int* p2;    // C++ style
    int*p3;     // nevermind space
    int *p4, p5;

    cout << "int* p4, p5;" << endl;
    cout << "sizeof p4: " << sizeof(p4) << "; sizeof p5: " << sizeof(p5) << endl;

    // Output
    /*
     * sizeof p4: 8; sizeof p5: 4
     */
    cout << "means p4 is a pointer, but p5 is a int" << endl;

    cout << "int*p3" << endl;
    cout << "pointer p3 value: " << p3 << endl;
    cout << "this means uninitialize pointer is random" << endl;
    *p3 = 1024;
    cout << "*p3 = 1024" << endl;
    cout << "*p3 = " << *p3 << endl;
    // Output
    /*
    * *p3 = 1024
    * *p3 = 1024
    */
    cout << "eventhough maybe *p3 will set successfully, but use uninitialize pointer will cause UB" << endl;
}

void whats_pointer()
{
    using namespace std;
    double dbNum = 512.0;
    double *pDb = &dbNum; // C style pointer declare
    cout << "double size: " << sizeof(dbNum) << "Bytes" << endl;
    cout << "address size: " << sizeof(&dbNum) << "Bytes" << endl;
    cout << "pointer size: " << sizeof(pDb) << "Bytes" << endl;
    cout << "double value: " << dbNum << endl;
    cout << "address value: " << &dbNum << endl;
    cout << "pointer value: " << pDb << endl;
    cout << "pointer reference value: " << *pDb << endl;

    float flNum = 512.0;
    float* pFl = &flNum; // C++ style pointer declare
    float*ptr = &flNum; // compiler never mind space beside with pointer*
    cout << "float size: " << sizeof(flNum) << endl;
    cout << "address size: " << sizeof(&flNum) << endl;
    cout << "float value: " << flNum << endl;
    cout << "address value: " << &flNum << endl;
    cout << "pointer value: " << pFl << endl
         << "another pointer value: " << ptr << endl;
}

int main()
{
    // whats_pointer();
    // pointer_dec();
    hello_malloc();
    return 0;
}