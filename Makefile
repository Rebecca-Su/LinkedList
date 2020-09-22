playlistdriver: dequedriver.cpp deque.h deque.cpp
	g++ -std=c++11 -o dequedriver dequedriver.cpp deque.cpp

clean:
	rm -f dequedriver
