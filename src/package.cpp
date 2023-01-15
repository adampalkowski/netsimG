#include "package.hpp"
#include <iostream>

std::set<ElementID> Package::assigned_IDs {};
std::set<ElementID> Package::freed_IDs {};

Package::Package() {
    if(!freed_IDs.empty()){
        auto new_id = freed_IDs.begin();;
        ID_ = *new_id;
        freed_IDs.erase(new_id);
    }
    else if(!assigned_IDs.empty()){
        auto new_id = assigned_IDs.end();
        new_id--;
        ID_ = *new_id + 1;
        assigned_IDs.insert(ID_);
    }
    else if(freed_IDs.empty() && assigned_IDs.empty()){
        ID_ = 1;
        assigned_IDs.insert(ID_)
    }
}
// via. strona Microsoftu, więc powinno byc ok
//TODO: trzeba sprawdzić czy git
Package::Package(Package&& other) noexcept : ID_(0){
    *this = std::move(other);
}

//TODO: to samo co wyżej
Package& Package::operator=(Package&& other) noexcept{
    if(this != &other){
        delete[] &ID_; //tutaj najbardziej nwm czy git, bo wszędzie używają delete[] ale mają wskaźniki więc usuwają adres
        ID_ = other.ID_;
        other.ID_ = 0;
    }
    return *this;
}

Package::~Package() {
    freed_IDs.insert(ID_);
    assigned_IDs.erase(ID_);
}
