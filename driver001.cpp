#include <iostream>
#include "Countdown.h"
#include "Timedata.h"
#include "Alarmlist.h"
using namespace std;
int main() {
	string cstr = "0:0:15";
	Countdown c1(10), c2(cstr);//ֱ�Ӷ�����������ʱ//
	string str1 = "2019-6-9 23:2:0",str2="2019-6-9 23:2:15";
	Timedata t1(str1), t2(str2);
	//t1.getdifftime(), t2.getdifftime();
	t1.getdifftime_2(), t2.getdifftime_2();
	t1.display();
	t2.display();
	Alarmlist a;
	a.add(c1);
	a.add(c2);
	a.add(t1);
	a.add(t2);
	//cout << "size=" << a.getsize() << endl;
	a.travenode();
	system("pause");
	return 0;
	/*
	���ڵ���ʱ��ʱ����int�����ݱ�ʾ����ʱ����������string��0��0��0��ʾ
	�����������ʱ����ֻ�ܸ�����ȷ��ʱ���ʾ��ʱ��Ӧʱ��
	*/
}