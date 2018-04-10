/**
 * CSC131 - Computational Thinking
 * Missouri State University, Spring 2018.
 *
 * @file: hw04.cpp
 * TODO: Remove this TODO and modify the line below accordingly.
 * @author: Your Name <email@live.missouristate.edu>
 */

#include <cstdlib>
#include <cctype>
#include <iostream>
#include <string>

std::string convertToMilitaryTime(std::string);

int main(int argc, char* argv[])
{
    /* TODO: Prompt user and print converted time. */
  std::cout << "Enter time: ";
  std::string standardTime;
  std::getline(std::cin, standardTime);
  std::cout << std::endl;
  std::cout << "Corresponding military time is "
	    << convertToMilitaryTime(standardTime)
	    << " hours" << std::endl;
    return EXIT_SUCCESS;
}

std::string convertToMilitaryTime(std::string st)
{
  std::size_t colonPosition{st.find(":")};
  std::string hour{st.substr(0, colonPosition)};
  std::string min{st.substr(colonPosition + 1, st.find(" ") - colonPosition - 1)};
  std::string timeOfDay{st.substr(st.length() - 2)};
  if (tolower(timeOfDay[0]) == 'p') {
    int iHour{stoi(hour) + 12};
    hour = std::to_string(iHour);
  }
  if (stoi(hour) < 10) {
    hour = "0" + hour;
  }
    return hour + min;
}
