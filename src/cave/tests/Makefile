r: clean test valgrind

all: gcov_report valgrind

gcov_report: testg
	gcovr -r ../ --html --html-details -o report/coverage_report.html


testg:
	g++ -std=c++17 -pthread tests.cc ../cave.cc --coverage -lgtest_main -lgtest -lpthread -lgcov -o test
	./test

test: clean
	g++ -std=c++17 -pthread tests.cc ../cave.cc -lgtest_main -lgtest -lpthread -lgcov -o test
	./test

valgrind:
	valgrind ./test

clean:
	rm -rf *.o *.gc* *.a test a.out report/*
