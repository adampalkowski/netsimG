//
// Created by adamp on 08.01.2023.
//
#include <iostream>
#include "storage_types.hpp"
#include "types.hpp"



class EmptyQueException : public std::exception {
public:
    char * what () {
        return "Que is empty";
    }
};

bool PackageQueue:: empty() const {
    if(package_list.empty()){
        return true;
    }else{
        return false;
    }
}

Package PackageQueue::pop() {

    // co zwrocic jesli jest pusta ???
    if (empty()){
        try{
            throw EmptyQueException();

        }catch (EmptyQueException mce) {
            std::cout << "Caught EmptyQueException" << std::endl;
            std::cout << mce.what();
        }
    }
    if(get_queue_type()==LIFO){
        auto aPackage=package_list.back();
        package_list.pop_back();
        return *aPackage;
    }else{
        auto aPackage=package_list.front();
        package_list.pop_front();
        return
    }
}

void PackageQueue::push(Package &&) {

}

PackageQueueType PackageQueue::get_queue_type() const {
    return packageQueueType;
}

const_iterator PackageQueue::end() const { return package_list.end();}
const_iterator PackageQueue::begin() const {return package_list.begin();}
const std::reverse_iterator<const_iterator> PackageQueue::rend() const {return package_list.rend();}
const std::reverse_iterator<const_iterator> PackageQueue::rbegin() const {return package_list.rbegin();}

size_type PackageQueue::size() const {}
