CXX = g++
CXXFLAGS= --std=c++17 -pthread

REQ=Requests/
BODY=$(REQ)Body/
TESTS=Tests/
COMMUNICATION=Communication/

REQ_FILES=$(REQ)*.cpp
BODY_FILES=$(BODY)*.cpp
MONITOR_FILES=*.cpp
COMMUNICATION_FILES=$(COMMUNICATION)*.cpp

all: full_combo monitor parser bodies monitor_thread
	@echo "Running all tests..."

full_combo:
	@echo "Full combo test..."
	$(CXX) $(CXXFLAGS) $(TESTS)msg_test_full.cpp $(MONITOR_FILES) $(REQ_FILES) $(BODY_FILES) 
	./a.out
	rm -rf a.out

communication:
	@echo "Communication test..."
	$(CXX) $(CXXFLAGS) $(TESTS)node_comm.cpp $(COMMUNICATION_FILES)
	./a.out
	rm -rf a.out
	
monitor:
	@echo "Monitor Test..."
	$(CXX) $(CXXFLAGS) $(TESTS)monitor_test.cpp $(MONITOR_FILES) $(REQ_FILES) $(BODY_FILES)
	./a.out
	rm -rf a.out

parser:
	@echo "Parser test..."
	$(CXX) $(CXXFLAGS) $(TESTS)test_parser.cpp $(MONITOR_FILES) $(REQ_FILES) $(BODY_FILES) 
	./a.out
	rm -rf a.out 

bodies:
	@echo "Bodies Test..."
	$(CXX) $(CXXFLAGS) $(TESTS)body_tests.cpp $(MONITOR_FILES) $(REQ_FILES) $(BODY_FILES)
	./a.out
	rm -rf a.out
