//
// Created by chengzi on 18-7-5.
//

using namespace std;

void testString(){
    std::string str = "abc";
    // Capacity
    printf("size:%d\n",str.size());
    printf("len:%d\n",str.length());//两者没有区别,只不过是兼容性.
    printf("max_size:%d\n",str.max_size());
    printf("capacity:%d\n",str.capacity());
    str.resize(50);
    printf("max_size:%d\n",str.max_size());
    printf("capacity:%d\n",str.capacity());
    printf("empty:%d\n",str.empty());
    str.reserve();
    printf("str:%s\n",str);

    //Element access
    cout << str[1] << endl;
    cout << str.at(3) << endl;
    cout << str.at(4) << endl;
    cout << str.back() << endl;
    cout << str.front() << endl;

    // Modifiers:
    cout << "Modifiers:\n" << endl;
    str += "_chengzi";
    str.append("_db");
    cout << str << endl;
    str.push_back('c');
    cout << str << endl;
    str.insert(2,"_insert__");
    cout << str << endl;
    str.pop_back();
    cout << str << endl;
    str.replace(30,5,"123456");
    cout << str << endl;

    // String Operations
    str = "new_string";
    cout << str.c_str() << endl;
    char* copy_str;
//    cout << str.copy(copy_str,10) << endl;
//    cout << copy_str << endl; // 没太看懂

    cout << str.find("str") << endl;
    cout << str.find_last_of("e") << endl;


    // string 和 char的相互转化
    // 1.C语言风格的string是char*,char[].这些类型转化为C++的string类型很方便
    char *chstr = "chstr";
    char arstr[] = "arstr";
    string str1 = chstr;
    string str2 = arstr;
    cout << str1 << endl;
    cout << str2 << endl;

    // 2,string -> char*
    const char * mystr = str1.c_str();//记得加上const,操作更加安全.很多function的参数列表里面也是这种形式也去就是这个原因.
    cout << mystr << endl;

}






