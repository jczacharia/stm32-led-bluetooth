#ifndef _JLOG_H_
#define _JLOG_H_

#include "stm32f1xx_hal.h"

class jLog
{
public:
	void log(const char* c)
	{
		printf(c);
	}
};

#endif
