#include <gm.hpp>

#include <cstdlib>
#include <iostream>
#include <stdexcept>

int main()
{
  GTR::GameManager gm{};

  try
  {
    gm.run();
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}