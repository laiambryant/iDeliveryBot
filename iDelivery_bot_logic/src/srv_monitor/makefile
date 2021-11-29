CXXFLAGS= -Wall --std=c++17

REQ=Requests/

monitor:
	g++ test.cpp srv_monitor.cpp message_creator.cpp
	./a.out
	rm -rf a.out

parser:
	g++ $(CXXFLAGS) $(REQ)req_parser.cpp $(REQ)req.cpp $(REQ)test_parser.cpp message_creator.cpp
	./a.out
	rm -rf a.out 