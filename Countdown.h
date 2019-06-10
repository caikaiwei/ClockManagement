#pragma once
#ifndef COUNTDOWN_H_
#define COUNTDOWN_H_
#include "Ctimer.h"
#include <Windows.h>
class Countdown :public Ctimer {
public:
	Countdown(int t=0):Ctimer(t){}
	Countdown(std::string str) {
			std::string s1, s2, s3;
			int start_index = str.find(":");
			s1 = str.substr(0, start_index);
			int index = str.find(":", start_index + 1);
			s2 = str.substr(start_index + 1, index - start_index - 1);
			s3 = str.substr(index + 1, str.length() - index - 1);
			secondnum = atoi(s1.c_str())*3600 + atoi(s2.c_str())*60 + atoi(s3.c_str());
	}
	void response() {
		std::cout << "di~di~di~ time up......" << std::endl;
	}
	bool check() {
		secondnum--;
		std::cout << secondnum << std::endl;/////////
		if (secondnum == 0) {
			response();
			return true;//表示时间到了
		}
		return false;
	}//主函数中循环调用此函数，直到response

};
#endif