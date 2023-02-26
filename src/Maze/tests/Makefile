r: clean test

all: gcov_report

gcov_report: testg
	gcovr -r ../ --html --html-details -o report/coverage_report.html

testg:
	g++ -std=c++17 -pthread maze_test.cc ../maze.cc --coverage -lgtest_main -lgtest -lpthread -o test
	./test

test: clean
	g++ -std=c++17 -pthread maze_test.cc ../maze.cc -lgtest_main -lgtest -lpthread -o test
	./test


clean:
	rm -rf *.o *.gc* *.a test a.out report/*
