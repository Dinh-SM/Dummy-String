CXXFLAGS= -Wall

OurStringTest.o: OurStringTest.cpp OurString.cpp
	g++ $(CXXFLAGS) -c OurStringTest.cpp -o OurStringTest.o -Igoogletest-release-1.10.0/googletest/include/ -std=c++11
check: OurStringTest.o
	g++ $(CXXFLAGS) -o check OurStringTest.o googletest-release-1.10.0/build/lib/libgtest.a googletest-release-1.10.0/build/lib/libgtest_main.a -pthread
	./check
	rm ./check

