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

//TODO: bo niestety nwm jak :((
Package::Package(Package&& package){}

Package::~Package() {
    freed_IDs.insert(ID_);
    assigned_IDs.erase(ID_);
}
