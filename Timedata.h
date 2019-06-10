#pragma once
#ifndef TIMEDATA_H_
#define TIMEDATA_H_
#include "Ctimer.h"
#include <string>
using namespace std;
typedef struct computertime {
	int tm_second;
	int tm_minute;
	int tm_hour;
	int tm_day;
	int tm_month;
	int tm_year;
}tmm;
//static int flag = 1;
class Timedata :public Ctimer {
protected:
	tmm now_time;
private:
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
public:
	Timedata(int y=2000,int m=1,int d=1,int h=0,int mi=0,int s=0):year(y),month(m),day(d),hour(h),minute(mi),second(s){}
	Timedata(string str);
	//static int flag = 1;
	double getdifftime();//获取本机时间，和自定义时间差
	inline void init() {
		secondnum = (int)(getdifftime() + 1);
	}
	bool check();
	void response();
	void display()const {
		cout << "it's    " << year << "-" << month << "-" << day << " " << hour << ":" << minute << ":" << second << "secondnum="<<secondnum<<endl;
	}
	void getdifftime_2();//获取机内-1970_1_1 0:00:00
	bool isleapyear(int t) {
		if (t % 400 == 0 || (t % 4 == 0 && t % 100 != 0))
			return true;
		return false;
	}
};
#endif