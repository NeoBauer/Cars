#include "ElectricCar.hpp"
#include <iostream>

ElectricCar::ElectricCar(std::unique_ptr<ElectricEngine> engine)
    : engine_(std::move(engine)) {
  std::cout << __FUNCTION__ << std::endl;
}

ElectricCar::~ElectricCar() { std::cout << __FUNCTION__ << std::endl; }

void ElectricCar::charge() { std::cout << __FUNCTION__ << std::endl; }

ElectricEngine *ElectricCar::getElectricEngineData() const {
  if(engine_ != nullptr)
  return engine_.get();
  else throw std::runtime_error("You can't get to data, because engine doesn't exists\n");
}

std::unique_ptr<ElectricEngine> ElectricCar::pullOutElectricEngine() {
    if(speed == 0){
      std::cout << "Electric engine is pulled out\n";
  return std::move(engine_);
    }else throw std::runtime_error("This car is moving, you can't pull out engine\n");
}

void ElectricCar::restore(){
    charge();
}

void ElectricCar::accelerate(int a) {
  if (engine_) {
    if (a >= 0) {
      std::cout << "Accelerate to: " << a << "km\\h\n";
      speed = a;
    } else
      throw std::invalid_argument("Invalid speed, can't be negative\n");
  } else
    std::cout << "This car doesn't have an engine!\n";
}

void ElectricCar::putInElectricEngine(std::unique_ptr<ElectricEngine> newEngine){
  if(engine_ != nullptr){
  std::cout << "There is an engine in car!\n";
  } else engine_.swap(newEngine);
}
