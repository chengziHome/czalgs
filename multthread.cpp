//
// Created by chengzi on 18-7-16.
//

#include <iostream>
#include <pthread.h>


#define NUM_THREADS 5

using namespace std;

void* say_hello(void* args){
    std::cout << "Chengzi ." << std::endl;
    return 0;
}


int testThread(){
    pthread_t  tids[NUM_THREADS];
    for(int i=0;i<NUM_THREADS;++i){
        int ret = pthread_create(&tids[i],NULL,say_hello,NULL);
        if(ret!=0){
            std::cout << "pthread create error:error_code:" << ret << std::endl;
        }
    }
    pthread_exit(NULL);

}

void *printHello(void *threadid){
    int tid = *((int*)threadid);
    cout << "hello Chengzi,thread id:" << tid << endl;
    pthread_exit(NULL);
}

int testThread2(){
    pthread_t threads[NUM_THREADS];
    int indexs[NUM_THREADS];
    int rc;
    int i;
    for(i = 0;i<NUM_THREADS;i++){
        cout << "create the thread:" << i << endl;
        indexs[i] = i;
        rc = pthread_create(&threads[i],NULL,printHello,(void *)&(indexs[i]));
        if(rc){
            cout << "can't create the thread ." << rc << endl;
            exit(-1);
        }
    }
    pthread_exit(NULL);
}


#include <cstdint>

struct thread_data{
    int thread_id;
    char *message;
};

void *printHello2(void *thread_arg){
    struct thread_data *my_data;
    my_data = (struct thread_data *) thread_arg;

    cout << "Thread ID:" << my_data->thread_id;
    cout << "Message :" << my_data->message << endl;
    pthread_exit(NULL);
}

int testThread3(){
    pthread_t threads[NUM_THREADS];
    struct thread_data td[NUM_THREADS];
    int rc;
    int i;
    for(int i=0;i<NUM_THREADS;i++){
        cout << "create thread: " << i << endl;
        td[i].thread_id =i;
        td[i].message = (char*)"This is a message";
        rc = pthread_create(&threads[i],NULL,printHello2,(void *)&td[i]);
        if(rc){
            cout << "create thread error:" << rc << endl;
            exit(-1);
        }
    }
    pthread_exit(NULL);
}


#include <mutex>
#include <thread>

volatile int val=1;
mutex mut;

void icrement(int thread_id){
    while(1) {
        mut.lock();
        if(val>100){
            mut.unlock();
            break;
        }
        cout << "thread-" << thread_id << " ,take the num:" << (val++) << endl;
        mut.unlock();
    }
}

int testThread4(){
    thread t1(icrement,1);
    thread t2(icrement,2);

    t1.join();
    t2.join();

    cout << val << endl;
    return 0;
}




