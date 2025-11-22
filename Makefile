CXX = g++
CXXFLAGS = -std=c++17

all: banker

banker: banker_code.cpp
	$(CXX) $(CXXFLAGS) banker_code.cpp -o banker

clean:
	rm -f banker
