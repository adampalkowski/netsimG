//
// Created by adamp on 08.01.2023.
//

#ifndef NETSIM_STORAGE_TYPES_HPP
#define NETSIM_STORAGE_TYPES_HPP

#include <list>
#include "package.hpp"

/*
  TODO :IMPLEMENT classes IPackageStockpile, IPackageQueue, PackageQueue
  TODO :IMPLEMENT enumarate PackageQueueType
*/
enum PackageQueueType {
    FIFO, LIFO
};

class PackageQueue {
    PackageQueue(PackageQueueType) {}
};

class IPackageQueue {
    public:
        virtual ~IPackageQueue() {}

        virtual Package pop() = 0;
        virtual PackageQueueType get_queue_type() const = 0;

};

class IPackageStockpile {
    public:
        //Pamiętaj, aby zdefiniować w interfejsie IPackageStockpile wirtualny destruktor (o domyślnej implementacji).
        virtual ~IPackageStockpile() {}

        //metodę do umieszczania półproduktu na składowisku
        virtual void push(Package&&) = 0;

        //metody pozwalające na uzyskanie dostępu “tylko do odczytu” do kontenera przechowującego półprodukty (tj. metody [c]begin(), [c]end() – łącznie 4 metody)
        const_iterator begin() const
        //zwracającą wartość logiczną prawda, jeśli kontener nie zawiera żadnych elementów (w przeciwnym razie zwraca fałsz)
        virtual bool empty() const= 0;

        //zwracającą liczbę półproduktów w kontenerze
        virtual size_type size() const= 0;

        //korzystaj z niego podczas definiowania metod do przeglądania zawartości składowiska.
        using const_iterator  =std::list<Package>::const_iterator;
};


#endif //NETSIM_STORAGE_TYPES_HPP
