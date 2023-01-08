TU JEST KOD UML NIE SKOCZNONY

@startuml
' TODO

' --------

' ==== < CONFIGURATION > ====

hide empty members
hide <<function>> circle

' ==== END of < CONFIGURATION > ====

package "Storage" {

	interface IPackageStockpile <<interface>> {
	    + {abstract} push(Package&&) : void
	    + {abstract} empty() : bool {query}
	    + {abstract} size() : size_type {query}
	    + {method} /iteratory/
	    + ~IPackageStockpile()
	} 

	interface IPackageQueue <<interface>> {
	    + {abstract} pop() : Package
	    + {abstract} get_queue_type() : PackageQueueType {query}
	} 
	IPackageQueue <|--- IPackageStockpile

	enum PackageQueueType <<enumeration>> {
		FIFO
		LIFO
	}
	PackageQueueType <.. IPackageQueue: << uses >> 
        Package <.. IPackageQueue: << uses >> 

	class PackageQueue {
	    + PackageQueue(PackageQueueType)
	}
	PackageQueue ..|> IPackageQueue

	class Package {
		+ Package()
		+ Package(ElementID)
		+ Package(Package&&)
		+ operator=(Package&&) : Package&
		+ get_id(): ElementID {query}
		+ ~Package()
	}

}

' == END of package "Storage"

' .. DATA TYPES --
together {
	class ElementID << (T,orchid) primitive>>
}

' == END of together


' ==== END of < POSITIONING > ====


' TODO

' --------

' ==== < CONFIGURATION > ====

hide empty members
hide <<function>> circle

' ==== END of < CONFIGURATION > ====

package "Factory Package" {

	class NodeCollection<Node> << (T,olive) >> {
	    + add(node: Node&&) : void
	    + remove_by_id(id: ElementID) : void
	    + find_by_id(id: ElementID) : NodeCollection<Node>::iterator
	    + find_by_id(id: ElementID) : NodeCollection<Node>::const_iterator {query}
	    + {method} /iteratory/
	}

	Ramps .. NodeCollection
	Workers .. NodeCollection
	Storehouses .. NodeCollection

	class Factory {
		+ add_ramp(Ramp&&) : void
		+ remove_ramp(id: ElementID) : void
		+ find_ramp_by_id(id: ElementID) : NodeCollection<Ramp>::iterator
		+ find_ramp_by_id(id: ElementID) : NodeCollection<Ramp>::const_iterator {query}
	    + ramp_cbegin() : NodeCollection<Ramp>::const_iterator {query}
	    + ramp_cend() : NodeCollection<Ramp>::const_iterator {query}

    	... (analogicznie dla pozostałych typów węzłów)

		- remove_receiver(collection: NodeCollection<Node>&, id: ElementID) : void

		+ is_consistent(void) : bool {query}
		+ do_deliveries(Time) : void
		+ do_package_passing(void) : void
		+ do_work(Time) : void
	}
	Factory .. Ramps
	Factory .. Workers
	Factory .. Storehouses

}

' == END of package "Factory"


' ==== END of < POSITIONING > ====




' TODO

' --------

' ==== < CONFIGURATION > ====

hide empty members
hide <<function>> circle

' ==== END of < CONFIGURATION > ====

package "Storage" {

	interface IPackageStockpile <<interface>> {
	} 

	interface IPackageQueue <<interface>> {
	} 
	IPackageQueue . IPackageStockpile

}
' == END of package "Storage"


package "Nodes" {

	interface IPackageReceiver <<interface>> {
		+ {abstract} receive_package(p: Package&&) : void
'		+ {abstract} get_receiver_type(void) : ReceiverType {query}
		+ {abstract} get_id(void) : ElementID {query}
	}

'	enum ReceiverType <<enumeration>> {
'	}
'	IPackageReceiver .. ReceiverType


	class ReceiverPreferences {
		+ preferences_t
		+ ReceiverPreferences(pg: ProbabilityGenerator)
		+ add_receiver(r: IPackageReceiver*) : void
		+ remove_receiver(r: IPackageReceiver*) : void
		+ choose_receiver(void) : IPackageReceiver*
		+ get_preferences(void) : preferences_t& {query}
	}


	class PackageSender {
		+ PackageSender(PackageSender&&)
		+ receiver_preferences_: ReceiverPreferences
		+ send_package(void) : void
		+ get_sending_buffer(void) : std::optional<Package>& {query}
		# push_package(Package&&) : void
	}

	PackageSender .. ReceiverPreferences

	class Ramp {
		+ Ramp(id: ElementID, di: TimeOffset) : void
		+ deliver_goods(t: Time) : void
		+ get_delivery_interval(void) : TimeOffset {query}
		+ get_id(void) : ElementID {query}
	}

	Ramp .. PackageSender


	class Worker {
		+ Worker(id: ElementID, pd: TimeOffset, q: std::unique_ptr<IPackageQueue>) : void
		+ do_work(t: Time) : void
		+ get_processing_duration(void) : TimeOffset {query}
		+ get_package_processing_start_time(void) : Time {query}
	}

	Worker .. PackageSender
	Worker .. IPackageReceiver
	IPackageQueue .. Worker

	class Storehouse {
		+ Storehouse(id: ElementID, d: std::unique_ptr<IPackageStockpile>)
	}

	Storehouse .. IPackageReceiver
	IPackageStockpile .. Storehouse

	Ramp -[hidden] Worker
	Worker -[hidden] Storehouse

	' == POSITIONING ==
	PackageSender -[hidden]> IPackageReceiver
	Ramp ..[hidden] PackageSender
	ReceiverPreferences -[hidden]- PackageSender

	IPackageQueue -[hidden]- Worker


	' == END of POSITIONING ==
}
' == END of package "Nodes"


' .. HELPERS ----

' .. DATA TYPES --
together {
	class Time << (T,orchid) primitive>>
	class TimeOffset << (T,orchid) primitive>>
	class ElementID << (T,orchid) primitive>>
	class ProbabilityGenerator << (T,orchid) primitive>>

	ElementID -[hidden] Time
	Time -[hidden] TimeOffset
	TimeOffset -[hidden] ProbabilityGenerator
}

' == END of together


' ==== < POSITIONING > ====

'ReceiverPreferences <-[hidden]- IPackageStockpile

'IPackageStockpile -[hidden]-> Storehouse

ReceiverPreferences -[hidden]- Time

' ==== END of < POSITIONING > ====
@enduml
