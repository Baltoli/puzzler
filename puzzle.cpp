#include <algorithm>
#include <iostream>
#include <numeric>
#include <map>
#include <random>
#include <set>
#include <sstream>
#include <vector>

using namespace std;

set<char> read_start_chars()
{
  auto line = string{};      // create an empty string to read into
  getline(cin, line);   // read a line of input

  auto chars = set<char>{};  // create an empty set of characters
  for(auto c : line) {            // for every character on the line we read...
    chars.insert(c);              // ...put it into the set
  }

  return chars;                   // give the set of characters back
}

string read_message()
{
  auto line = string{};
  auto sb = stringstream{};

  while(getline(cin, line)) {
    sb << line << '\n';
  }

  return sb.str();
}

map<char, int> random_key()
{
  auto&& rd = random_device{};

  auto indexes = vector<int>(26);
  iota(begin(indexes), end(indexes), 1);
  shuffle(begin(indexes), end(indexes), rd);

  auto key = map<char, int>{};

  auto c = 'a';
  for(auto i : indexes) {
    key[c++] = i;
  }

  return key;
}

void print_key(set<char> const& starts, 
               map<char, int> const& key)
{
  auto line_break = 0;

  for(auto c = 'a'; c <= 'z'; ++c) {
    if(starts.find(c) != end(starts)) {
      cout << key.at(c);
    } else {
      cout << '?';
    }

    cout << " = " << c;

    cout << '\t';

    if(++line_break % 5 == 0) {
      cout << '\n';
    }
  }

  cout << '\n';
}

void print_message(string const& message,
                   map<char, int> const& key)
{
  for(auto c : message) {
    c = tolower(c);

    if(key.find(c) != end(key)) {
      cout << key.at(c) << ' ';
    } else if(isspace(c)) {
      cout << "/ ";
    } else {
      cout << c << ' ';
    }
  }
}

int main()
{
  auto starts = read_start_chars();
  auto message = read_message();
  auto key = random_key();

  print_key(starts, key);
  cout << '\n';

  print_message(message, key);
  cout << endl;
}
