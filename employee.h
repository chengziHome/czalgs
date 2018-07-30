//
// Created by chengzi on 18-6-27.
//

#ifndef CPP_LEARN_EMPLOYEE_H
#define CPP_LEARN_EMPLOYEE_H

#endif //CPP_LEARN_EMPLOYEE_H


/***
 *  inheritance
 */
namespace cpplearn {

    class Employee {
    private:
        std::string no;
        std::string name;
        float wages;
    public:
        Employee(std::string no, std::string name);


        void setWages(float wages);

        void showMsg();
    };



    class Manager : public Employee {
    public:
        Manager(std::string no, std::string name);

    };


    class Technician : public Employee {
    private:
        std::int8_t hours;
    public:
        Technician(std::string no, std::string name, std::int8_t hours);
    };


    class SalesMan : public Employee {
    private:
        float sales;
    public:
        SalesMan(std::string no, std::string name, float sales);
    };


    class SalesManager : public Employee {
    private:
        float sales;
    public:
        SalesManager(std::string no, std::string name, float);
    };


}
