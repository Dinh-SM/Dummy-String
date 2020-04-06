CXXFLAGS= -Wall

OurStringTest.o: OurStringTest.cpp
	g++ -c OurStringTest.cpp -o OurStringTest.o -Igoogletest-release-1.10.0/googletest/include/ -std=c++11
check: OurStringTest.o
	g++ -o check OurStringTest.o googletest-release-1.10.0/build/lib/libgtest.a googletest-release-1.10.0/build/lib/libgtest_main.a -pthread
	./check