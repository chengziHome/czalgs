//
// Created by chengzi on 18-7-5.
//

#include <queue>
#include <list>
#include <map>
#include <set>
#include <stack>

using namespace std;

void testQueue(){

    queue<int> mQ;
    mQ.push(1);
    mQ.push(2);
    mQ.push(3);
    cout << mQ.size() << endl;
    cout << mQ.front() << endl;
    cout << mQ.back() << endl;
    cout << mQ.size() << endl;
//    cout << mQ.pop() << endl; // pop并没有返回,所以会报错
    cout << mQ.size() << endl;
}


void testPriorityQueue(){
    priority_queue<int> pq;
    pq.push(2);
    pq.push(1);
    pq.push(5);
    pq.push(4);
    pq.push(9);

    cout << pq.size() << endl;
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }

    cout << endl;

}


void testDeque(){
    int myints[] = {15,2,33,5};


    deque<int> mD (myints,myints+ sizeof(myints)/ sizeof(int));
    for(deque<int>::iterator it = mD.begin();it!=mD.end();++it)
        cout << ' ' << *it;
    cout << endl;
}

/**
 * list是双向链表,forward_list是单向链表.
 * 所以注意,cpp的list概念和java的不一样哈.
 */
void testList(){
    int myints[] = {2,3,1,5,6};

    list<int> mL(myints,myints + sizeof(myints)/ sizeof(int));
    cout << "THE content are:\n" << endl;
    for(list<int>::iterator it = mL.begin();it != mL.end();it++)
        cout << *it << ' ';

    cout << "\n";

}



void testMap(){
    std::map<char,int> first;
    first['a'] = 10;
    first['b'] = 20;
    first['c'] = 40;
    first['d'] = 59;

    map<char,int> second(first.begin(),first.end());
    map<char,int> third(second);
    for(map<char,int>::iterator it = third.begin();it != third.end();++it)
        cout << it->first << "->" << it->second << endl;

}

void testSet(){
    set<int> first;

    int myints[] = {10,30,40,54,23};
    set<int> second(myints,myints+5);

    for(set<int>::iterator it = second.begin();it != second.end();++it)
        cout << *it << ' ';
    cout << endl;

}


void testStack(){

    stack<int> mS;
    for(int i=0;i<5;i++)
        mS.push(i);
    cout << "Poping elements ... " << endl;
    while(!mS.empty()){
        cout << ' ' << mS.top() ;
        mS.pop();
    }
    cout << endl;
}


void testVector(){

    vector<int> mV(4,100);
    cout << mV.size() << endl;
    cout << mV.capacity() << endl;
    cout << mV.max_size() << endl;
    mV.push_back(20);
    for(vector<int>::iterator it = mV.begin(); it != mV.end(); ++it)
        cout << ' ' << *it;
    cout << endl;
}



