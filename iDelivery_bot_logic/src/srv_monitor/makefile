CXX = g++
CXXFLAGS= --std=c++17 

REQ=Requests/
BODY=$(REQ)Body/
TESTS=Tests/

all: full_combo monitor parser bodies
	@echo "Running all tests"

full_combo:
	$(CXX) $(CXXFLAGS) $(TESTS)msg_test_full.cpp message_creator.cpp srv_monitor.cpp  $(REQ)req_parser.cpp $(REQ)req.cpp $(BODY)body_types.cpp $(BODY)str_utils.h
	./a.out
	rm -rf a.out

monitor:
	$(CXX) $(CXXFLAGS) $(TESTS)monitor_test.cpp srv_monitor.cpp message_creator.cpp $(REQ)req_parser.cpp $(REQ)req.cpp
	./a.out
	rm -rf a.out

parser:
	$(CXX) $(CXXFLAGS) $(REQ)req_parser.cpp $(REQ)req.cpp $(TESTS)test_parser.cpp message_creator.cpp srv_monitor.cpp   $(BODY)body_types.cpp 
	./a.out
	rm -rf a.out 

bodies:
	$(CXX) $(CXXFLAGS) $(TESTS)body_tests.cpp $(BODY)body_types.cpp $(BODY)str_utils.h
	./a.out
	rm -rf a.out
