#ifndef EVENT_H
#define EVENT_H
#include "wire.h"

struct Event
{
    uint64_t time;
    Wire* wire;
    char state;
};

typedef struct EventLess {
        //write the operator() required to make this a functor that compares Events by time

        bool operator()(const Event* first, const Event* last){
            return first -> time < last -> time;
        }
} EventLess;
	
#endif
