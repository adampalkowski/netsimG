//
// Created by adamp on 08.01.2023.
//

#ifndef NETSIM_PACKAGE_HPP
#define NETSIM_PACKAGE_HPP


#include "types.hpp"

/*
 TODO :IMPLEMENT PACKAGE CLASS
 */
class Package {
public :

    //default constructor should create Id with possibly the lowest identificator
    Package();
    Package(ElementID ID) : ID_(ID){}
    Package(Package&& package);
    Package& operator=(Package&& other) {
        return *this;
    }
    ~Package();
    //get id of package , const because {query in uml}
    ElementID get_id() const {return ID_}
private:
    ElementID ID_;
    static std::set<ElementID> assigned_IDs;
    static std::set<ElementID> freed_IDs;
};
#endif //NETSIM_PACKAGE_HPP
