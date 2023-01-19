//Szymon Pająk <411633>, Adam Pałkowski <411994>,Mateusz Płatek <410324>

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
    using const_iterator = std::list<Package>::const_iterator;

    //Pamiętaj, aby zdefiniować w interfejsie IPackageStockpile wirtualny destruktor (o domyślnej implementacji).
    virtual ~IPackageStockpile() = default;

    //metodę do umieszczania półproduktu na składowisku
    virtual void push(Package &&package) = 0;

    //metody pozwalające na uzyskanie dostępu “tylko do odczytu” do kontenera przechowującego półprodukty (tj. metody [c]begin(), [c]end() – łącznie 4 metody)
    virtual const_iterator begin() const = 0;

    virtual const_iterator cbegin() const = 0;

    virtual const_iterator end() const = 0;

    virtual const_iterator cend() const = 0;

    //zwracającą wartość logiczną prawda, jeśli kontener nie zawiera żadnych elementów (w przeciwnym razie zwraca fałsz)
    virtual bool empty() const = 0;

    //zwracającą liczbę półproduktów w kontenerze
    virtual size_type size() const = 0;

};

//Interfejs IPackageQueue powinien rozszerzać interfejs IPackageStockpile o metodę do “wyciągania” półproduktu
class IPackageQueue : public IPackageStockpile {
public:

    virtual Package pop() = 0;

    virtual PackageQueueType get_queue_type() const = 0;

};

//Klasa PackageQueue implementuje interfejs IPackageQueue.
class PackageQueue : public IPackageQueue {
public:
    PackageQueue(PackageQueueType type) :package_list{ std::list<Package>()}, packageQueueType{type} {}

    bool empty() const override { return size() == 0; };

    Package pop() override;

    void push(Package &&) override;

    PackageQueueType get_queue_type() const override;

    const_iterator end() const override { return package_list.end(); };

    const_iterator cend() const override { return package_list.cend(); };

    const_iterator begin() const override{ return package_list.begin(); };

    const_iterator cbegin() const override { return package_list.cbegin(); };

    size_type size() const override;

private:
    std::list<Package> package_list;
    PackageQueueType packageQueueType;
};


#endif //NETSIM_STORAGE_TYPES_HPP
