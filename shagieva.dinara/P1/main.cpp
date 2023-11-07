#include <iostream>
#include "changeCounter.hpp"
#include "divCounter.hpp"

int main()
{
  int number = 0;
  int seq_length = 0;
  using namespace shagieva;
  ChangeCounter changeCounter;
  DivCounter divCounter;

  do
  {
    std::cin >> number;
    if (!std::cin)
    {
      std::cerr << "Not a sequence.\n";
      return 1;
    }
    else if (number != 0)
    {
      ++seq_length;
      try
      {
        changeCounter(number);
        divCounter(number);
      }
      catch (const std::exception & e)
      {
        std::cerr << "Error:" << e.what() << "\n";
        return 2;
      }
    }
  }
  while (number != 0);

  if (seq_length < 2)
  {
    std::cout << changeCounter() << "\n";
    std::cerr << "The sequence is too short.\n";
    return 2;
  }

  std::cout << changeCounter() << "\n";
  std::cout << divCounter() << "\n";
  return 0;
}
