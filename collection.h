#pragma once
#include <list>
#include "factory.h"

class Collection : public Factory
{
private:
	std::list<Stamp *> stamps;

public:
	void create_existent() override;
	void create_non_existent() override;
	void read_from_file(int) override;
	void write_to_file() override;
	void show();
	std::list<Stamp *> get_stamps();
};