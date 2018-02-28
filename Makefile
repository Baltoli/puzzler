CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

puzzle: puzzle.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm puzzle
