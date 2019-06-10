#pragma once
#ifndef ALARMLIST_H_
#define ALARMLIST_H_
#include "Ctimer.h"
typedef struct Node {
	Ctimer &p;
	Node *next, *pre;
	Node(Ctimer &a) :p(a), next(0), pre(0) {};
}alarm;
class Alarmlist {
	int size;
	alarm *first;
public:
	Alarmlist():first(0),size(0){}
	alarm * getfirst()const {
		return first;
	}
	int getsize()const {
		return size;
	}
	void add(Ctimer &a);
	void remove(alarm *p);
	bool isempty()const {
		return !size;
	}
	void travenode();
	~Alarmlist(){}
};
#endif