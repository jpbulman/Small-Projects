all: qSim

# Set CFLAGS to allow Debug and issue all warnings.
CFLAGS = -g -Wall

qSim: qSim.o Event.o eventLinkedList.o TellerEvent.o CustomerEvent.o Customer.o Teller.o TellerQueue.o
	g++ $(CFLAGS) qSim.o Event.o eventLinkedList.o TellerEvent.o CustomerEvent.o Customer.o Teller.o TellerQueue.o -o qSim

qSim.o: qSim.cpp Event.h eventLinkedList.h TellerEvent.h CustomerEvent.h Customer.h Teller.h TellerQueue.h
	g++ $(CFLAGS) -c qSim.cpp

Event.o: Event.cpp Event.h
	g++ $(CFLAGS) -c Event.cpp

clean:
	rm -f eventLinkedList.o Event.o TellerEvent.o CustomerEvent.o  Customer.o qSim.o Teller.o TellerQueue.o qSim
	rm -f -r html latex

docs:
	doxygen
	# Following lines are only needed if we want to access doc pages
	#   using a Web server.
	#chmod go+r html/*
	#cp html/* ~/public_html/cs2303assig3