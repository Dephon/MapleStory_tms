 /*This file is part of TitanMS.

    TitanMS is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    TitanMS is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with TitanMS.  If not, see <http://www.gnu.org/licenses/>.*/

#ifndef TIMER_H
#define TIMER_H

#include <queue>
#include <hash_map>
#include "windows.h"

using namespace std;
using namespace stdext;

class Timer {
public:
	static Timer* timer;
	class TimerHandler {
	public:
		virtual void handle (Timer* timer, int id) = 0;
		virtual void remove (int id) = 0;
	};

	Timer ();
	~Timer();

	int setTimer 
		(int msec, TimerHandler* handler);

	void cancelTimer (int id);

	void timerThread();

private:
	bool terminate;
	class OneTimer {
	public:
		long t;
		int id;
		TimerHandler* handler;
		OneTimer (long t, int id, TimerHandler* handler):t(t),id(id),handler(handler){}
	};
	vector<OneTimer*> timers;
	HANDLE timerEvent;
	OneTimer* findMin();
	OneTimer* getTimer(int id);
	void remove(int id);
	int id;
};

#endif