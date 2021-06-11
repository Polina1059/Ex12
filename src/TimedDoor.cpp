// Copyright 2021 Panina Polina
#include "TimedDoor.h"
#include <iostream>
#include <ctime>

DoorTimerAdapter::DoorTimerAdapter(TimedDoor& _door) : door(_door) {}

void Timer::sleep(int _ti) {
  time_t begin = time(nullptr);
  while (time(nullptr) - begin < _ti) {
    continue;
  }
}

void Timer::tregister(int time, TimerClient* timer) { sleep(time); }

int TimedDoor::getTime() { return iTimeout; }

void DoorTimerAdapter::Timeout() {
  Timer timer;
  timer.tregister(door.getTime(), this);
  door.DoorTimeOut();
}

bool TimedDoor::isDoorOpened() {
    return opened;
}

void TimedDoor::lock() {
    opened = false;
}

void TimedDoor::unlock() {
  opened = true;
  adapter->Timeout();
}

TimedDoor::TimedDoor(int time)
    : iTimeout(time), opened(false), adapter(new DoorTimerAdapter(*this)) {}

void TimedDoor::throwState() {
  if (!opened)
    throw std::string("the door is closed!");
  else
    throw std::string("the door is opened!");
}

void TimedDoor::DoorTimeOut() {
    throw std::string("close the door!");
}
