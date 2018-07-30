//
// Created by chengzi on 18-6-27.
//
#include <iostream>


namespace cpplearn{

    class Felid{
    public:
        virtual void sound()=0;
    };


    class Cat: public Felid{
    public:
        void sound(){
            std::cout << "I am a cat!" << std::endl;
        }
    };


    class Leopard:public Felid{
    public:
        void sound(){
            std::cout << "I am a leopard !" << std::endl;
        }
    };




}



