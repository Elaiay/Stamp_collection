#pragma once
#include "stamp.h"

class Factory
{
public:
	virtual void create_existent() = 0;
	virtual void create_non_existent() = 0;
	virtual void read_from_file(int) = 0;
	virtual void write_to_file() = 0;
};