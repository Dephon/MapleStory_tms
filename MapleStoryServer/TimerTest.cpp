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

#include "Timer.h"
#include "stdio.h"

long time;
/*
class TimerTest: public Timer::TimerHandler {
	void handle (Timer* timer, int id) {
		printf("received id: %d %d \n", id, GetTickCount() - time);
		timer->setTimer (2000, 3, this);

	}
	void remove(int id){}
};

void timermain () {
	Timer* timer = new Timer();
	TimerTest* handler = new TimerTest();
	time = GetTickCount();
	timer->setTimer (1000, 1, handler);
	timer->setTimer (10000, 2, handler);
	timer->setTimer (10000, 5, handler);
	timer->setTimer (10000, 6, handler);
	timer->setTimer (2000, 3, handler);
	printf("AB");
	Sleep(1000000000);
}
*/