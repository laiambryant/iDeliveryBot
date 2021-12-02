CXX = g++
CXXFLAGS= --std=c++17 

REQ=Requests/
BODY=$(REQ)Body/

all:
	$(CXX) $(CXXFLAGS) msg_test_full.cpp message_creator.cpp srv_monitor.cpp  $(REQ)req_parser.cpp $(REQ)req.cpp $(BODY)body_types.cpp $(BODY)req_body.cpp $(BODY)str_utils.h
	./a.out
	rm -rf a.out

monitor:
	$(CXX) $(CXXFLAGS) test.cpp srv_monitor.cpp message_creator.cpp $(REQ)req_parser.cpp $(REQ)req.cpp
	./a.out
	rm -rf a.out

parser:
	$(CXX) $(CXXFLAGS) $(REQ)req_parser.cpp $(REQ)req.cpp $(REQ)test_parser.cpp message_creator.cpp
	./a.out
	rm -rf a.out 

bodies:
	$(CXX) $(CXXFLAGS) $(BODY)body_tests.cpp $(BODY)body_types.cpp $(BODY)req_body.cpp $(BODY)str_utils.h
	./a.out
	rm -rf a.out
