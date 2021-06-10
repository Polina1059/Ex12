// Copyright 2021 Panina Polina
#include <iostream>
#include "TimedDoor.h"

int main() {
  TimedDoor tDoor(3);
  tDoor.lock();
  tDoor.unlock();
  return 0;
}
