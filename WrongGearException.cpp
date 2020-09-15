#include "WrongGearException.hpp"
#include <sstream>
#include <iostream>
#include <algorithm>

const char* WrongGearException::what() const noexcept{
return msg.c_str();
}


WrongGearException::WrongGearException(const int gear, const int gears):
gears_(gears),
gear_(gear),
msg("Exception: You choose: " + std::to_string(gear_) +  " when having only " + std::to_string(gears_) + "!\n"){}
