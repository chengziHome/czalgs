//
// Created by chengzi on 18-6-27.
//

#include <string>
#include <iostream>

#ifndef CPP_LEARN_EMPLOYEE_H
#define CPP_LEARN_EMPLOYEE_H

#endif //CPP_LEARN_EMPLOYEE_H


#include "employee.h"

namespace cpplearn {


    Employee::Employee(std::string no, std::string name) {
        this->no = no;
        this->name = name;
    }

    void Employee::showMsg() {
        std::cout << "id:" << no << ",name:" << name << ",wages:" << wages << std::endl;
    }

    void Employee::setWages(float wages) {
        this->wages = wages;
    }


    Manager::Manager(std::string no, std::string name) : Employee(no, name) {
        setWages(8000.0f);
        std::cout << "construct a manager" << std::endl;
    }



    Technician::Technician(std::string no, std::string name, std::int8_t hours) : Employee(no, name) {

            this->hours = hours;
            setWages(hours * 100.0f);
        }


    SalesMan::SalesMan(std::string no, std::string name, float sales) : Employee(no, name) {
            this->sales = sales;
            setWages(sales * 0.04f);
        }



    SalesManager::SalesManager(std::string no, std::string name, float) : Employee(no, name) {
            this->sales = sales;
            setWages(sales * 0.005f);
        }


}
