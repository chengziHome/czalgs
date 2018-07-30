//
// Created by chengzi on 18-7-5.
//



void  testConst(){
    /**
     * const对于指针来说:
     * 在*前面,代表指针所指向的内容不能边.
     * 在*后面,代表指针本身指向不能变化.
     */

//    char* const pContent = "a";
//    const char* pContent = "a";
//    string ch = "c";
//    pContent = ch;
//    printf("pContent:%s",*pContent);
}


/**
 * test reference
 */

void testReference(){
    int a = 5;
    int &b = a;

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    b = 6;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    int c = 7;
    b = c;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
}


/**
 * test cast
 */
void testCast(){
    //const_cast :用来去const
    const int a = 10;
    int& b = const_cast<int&>(a);
    b = 12;
    std::cout << a << std::endl;
    std::cout << b << std::endl;

    //static_cast: 基本数据类型之间转换
    float f = static_cast<float>(a);
    std::cout << typeid(f).name() << std::endl;

    //dynamic_cast: 动态类型之间的转换

    //reinterpret_cast: 没太看懂怎么用.

    int c = 19;
    int *ptr = &c;
//    int num = reinterpret_cast<int>(ptr);
//    std::cout << num << std::endl;


}