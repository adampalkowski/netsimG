//
// Created by adamp on 08.01.2023.
//

#ifndef NETSIM_PACKAGE_HPP
#define NETSIM_PACKAGE_HPP


/*
 TODO :IMPLEMENT PACKAGE CLASS
 */
class Package {
public :

    //default constructor should create Id with possibly the lowest identificator
    Package() {}
    Package(ElementID){}
    Package(Package&&){}
    Package& operator=(Package&& other) {

        return *this;
    }
    ~Package(){};
    //get id of package , const because {query in uml}
    ElementId get_id() const{

    }
};
#endif //NETSIM_PACKAGE_HPP
