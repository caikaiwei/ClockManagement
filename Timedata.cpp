#include "Timedata.h"

Timedata::Timedata(string str)
{
	int lengh1 = str.find(" ");
	string s1, s2, s3;
	int start_index = str.find("-");
	s1 = str.substr(0, start_index);
	int index = str.find("-", start_index + 1);
	s2 = str.substr(start_index + 1, index - start_index -1);
	s3 = str.substr(index + 1, lengh1 - index-1);
	year= atoi(s1.c_str());
	month = atoi(s2.c_str());
	day = atoi(s3.c_str());

	string s4, s5, s6;
	start_index = str.find(" ");
	int second_index = str.find(":");
	s4 = str.substr(start_index+1,second_index-start_index-1);
	index = str.find(":", second_index + 1);
	s5 = str.substr(second_index+ 1, index - second_index - 1);
	s6 = str.substr(index + 1, str.length()- index - 1);
	hour = atoi(s4.c_str());
	minute = atoi(s5.c_str());
	second = atoi(s6.c_str());
	//getdifftime_2();
}//初始化时间

double Timedata::getdifftime()
{
	time_t t;
	time(&t);
	tm *p = new tm();
	p->tm_year = year;
	p->tm_mon = month;
	p->tm_mday = day;
	p->tm_hour = hour;
	p->tm_min = minute;
	p->tm_sec = second;
	time_t timep1,timep2=0;
	timep1 = mktime(p);//得到自定义时钟到1970-1-1来的秒数
	time(&timep2);
	if (timep1 < timep2) {
		cerr << "error timeset" << endl;
	}
	double differenttime= difftime(timep1, timep2);
	return differenttime;
}

bool Timedata::check()
{
	secondnum--;
	if (secondnum == 0) {
		response();
		return true;
	}
	return false;
}

void Timedata::response()
{
	cout << "ding~  ding~ ding~~~   time up......:)\n";
	cout << "it's    " << year << "-" << month << "-" << day << " " << hour << ":" << minute << ":" << second << endl;
}

void Timedata::getdifftime_2()
{
	time_t t = time(NULL);
	int subsecond = 0,time1=0;
	int num_leapyear = 0;
	/*for (int i = 1970; i < year; ++i) {
		if (isleapyear())
			num_leapyear++;
	}*/
	for (int i = 1971; i <= year; ++i) {
		time1 += (isleapyear(i) ? 31622400 : 31536000);
	}
	int ys[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	for (int i = 1; i < month; ++i) {
		time1 += ys[i] * 3600*24;
	}
	for (int i = 1; i < day; ++i)
		time1 += 24 * 3600;
	time1 += (hour-8) * 3600 + minute * 60 + second;
	secondnum = time1 - (int)t;
	if (secondnum <= 0)
		cerr << "error time_set!\n";
	cout << "allsecond=" << t << endl;
	cout << "time1=" << time1 << endl;
}
