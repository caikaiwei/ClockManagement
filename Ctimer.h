#pragma once
#ifndef CTIMER_H_
#define CTIMER_H_
#include <ctime>
#include <iostream>
#include <string>
#include <Windows.h>
class Ctimer {
public:
	int secondnum;
	Ctimer(int t=0):secondnum(t){}
	virtual void response() = 0;
	virtual bool check() = 0;
};

#endif