CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic

puzzle: puzzle.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm puzzle
