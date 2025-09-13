#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr test;
  
  std::cout << "Empty initially: " << (test.empty() ? "YES" : "NO") << "\n";
  std::cout << "Size initially: " << test.size() << "\n";
  
  test.push_back("A");
  test.push_back("B");
  test.push_back("C");
  test.push_back("D");
  test.push_back("E");
  test.push_back("F");

  std::cout << "Front: " << test.front();
  std::cout << "Back: " << test.back();

  test.push_front("Z");
  test.push_front("Y");
  test.push_front("X");
  test.push_front("R");
  test.push_front("Q");

  std::cout << "Size: " << test.size();
  std::cout << "Front: " << test.front();
  std::cout << "Back: " << test.back();

  std::cout << "Get (2): " << test.get(2);
  test.set(2, "A2");
  std::cout << "Get again (2): " << test.get(2);

  test.pop_front();
  std::cout << "Front: " << test.front();
  std::cout << "Size: " << test.size();

  test.pop_back();
  std::cout << "Back: " << test.back();
  std::cout << "Size: " << test.size();

  test.pop_back();
  test.pop_back();
  test.pop_back();
  test.pop_back();
  test.pop_back();
  test.pop_back();
  test.pop_back();
  test.pop_front();
  test.pop_front();
  test.pop_front();

  std::cout << "Size: " << test.size();










}
