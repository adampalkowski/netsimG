//
// Created by adamp on 08.01.2023.
//

#ifndef NETSIM_STORAGE_TYPES_HPP
#define NETSIM_STORAGE_TYPES_HPP

#include <list>
#include "package.hpp"
#include "types.hpp"
/*
  TODO :IMPLEMENT classes IPackageStockpile, IPackageQueue, PackageQueue
  TODO :IMPLEMENT enumarate PackageQueueType
*/
enum PackageQueueType {
    FIFO, LIFO
};



class IPackageStockpile {
public:

    //Pamiętaj, aby zdefiniować w interfejsie IPackageStockpile wirtualny destruktor (o domyślnej implementacji).
    virtual ~IPackageStockpile() {}

    //metodę do umieszczania półproduktu na składowisku
    virtual void push(Package &&) = 0;

    //metody pozwalające na uzyskanie dostępu “tylko do odczytu” do kontenera przechowującego półprodukty (tj. metody [c]begin(), [c]end() – łącznie 4 metody)
    virtual const_iterator begin() const  =0;

    virtual const_iterator end() const =0;

    virtual const std::reverse_iterator<const_iterator> rend() const =0;

    virtual const std::reverse_iterator<const_iterator> rbegin() const =0;

    //zwracającą wartość logiczną prawda, jeśli kontener nie zawiera żadnych elementów (w przeciwnym razie zwraca fałsz)
    virtual bool empty() const = 0;

    //zwracającą liczbę półproduktów w kontenerze
    virtual size_type size() const = 0;

};

//Interfejs IPackageQueue powinien rozszerzać interfejs IPackageStockpile o metodę do “wyciągania” półproduktu
class IPackageQueue: virtual public IPackageStockpile {
public:
    virtual ~IPackageQueue() {}

    virtual Package pop() = 0;

    virtual PackageQueueType get_queue_type() const = 0;

};

//Klasa PackageQueue implementuje interfejs IPackageQueue.
class PackageQueue:   public IPackageQueue  {
public:
    PackageQueue(PackageQueueType type):packageQueueType{type}{}

    bool empty() const;

    Package pop();

    void push(Package &&);

    PackageQueueType get_queue_type() const;

    const_iterator end() const;

    const std::reverse_iterator<const_iterator> rend() const;

    const_iterator begin() const;

    const std::reverse_iterator<const_iterator> rbegin() const;
    size_type size() const;

private:
    std::list<Package> package_list;
    PackageQueueType packageQueueType;
};


#endif //NETSIM_STORAGE_TYPES_HPP
