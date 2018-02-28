#include <algorithm>
#include <iostream>
#include <numeric>
#include <map>
#include <random>
#include <set>
#include <sstream>
#include <vector>

std::set<char> read_start_chars()
{
  auto line = std::string{};      // create an empty string to read into
  std::getline(std::cin, line);   // read a line of input

  auto chars = std::set<char>{};  // create an empty set of characters
  for(auto c : line) {            // for every character on the line we read...
    chars.insert(c);              // ...put it into the set
  }

  return chars;                   // give the set of characters back
}

std::string read_message()
{
  auto line = std::string{};
  auto sb = std::stringstream{};

  while(std::getline(std::cin, line)) {
    sb << line << '\n';
  }

  return sb.str();
}

std::map<char, int> random_key()
{
  auto&& rd = std::random_device{};

  auto indexes = std::vector<int>(26);
  std::iota(std::begin(indexes), std::end(indexes), 1);
  std::shuffle(std::begin(indexes), std::end(indexes), rd);

  auto map = std::map<char, int>{};

  auto c = 'a';
  for(auto i : indexes) {
    map[c++] = i;
  }

  return map;
}

void print_key(std::set<char> const& starts, 
               std::map<char, int> const& key)
{
  auto line_break = 0;

  for(auto c = 'a'; c <= 'z'; ++c) {
    std::cout << c << " = ";

    if(starts.find(c) != std::end(starts)) {
      std::cout << key.at(c);
    } else {
      std::cout << '?';
    }

    std::cout << '\t';

    if(++line_break % 5 == 0) {
      std::cout << '\n';
    }
  }

  std::cout << '\n';
}

void print_message(std::string const& message,
                   std::map<char, int> const& key)
{
  for(auto c : message) {
    c = std::tolower(c);

    if(key.find(c) != std::end(key)) {
      std::cout << key.at(c) << ' ';
    } else if(std::isspace(c)) {
      std::cout << "/ ";
    } else {
      std::cout << c << ' ';
    }
  }
}

int main()
{
  auto starts = read_start_chars();
  auto message = read_message();
  auto key = random_key();

  print_key(starts, key);
  std::cout << '\n';

  print_message(message, key);
  std::cout << std::endl;
}
