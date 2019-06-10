#include "Alarmlist.h"

void Alarmlist::add(Ctimer & a)
{
	alarm *p = new alarm(a);
	if (first) {
		p->next = first;
		first->pre = p;
	}
	first = p;
	size++;
}

void Alarmlist::remove(alarm *p)
{
	if (p->pre) p->pre->next = p->next;
	if (p->next) p->next->pre = p->pre;
	if (p == first) first = p->next;
	delete p;
	size--;
}

void Alarmlist::travenode()
{

	while (!isempty()) {
		alarm *pn = first;
		for (int i = 0; i < getsize(); ++i,pn=pn->next) {
			if ((pn->p).check()) {
				if (pn->pre) pn->pre->next = pn->next;
				if (pn->next) pn->next->pre = pn->pre;
				if (pn == first) first = pn->next;
				delete pn;
				size--;
				//std::cout << "leftszie=" << getsize() << std::endl;
			}
				//remove(pn);
		}
		Sleep(1000);
	}//遍历所有时钟，删除到点的时钟
}
