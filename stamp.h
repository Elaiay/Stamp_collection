#pragma once
#include <string>

class Stamp
{
protected:
	bool existent_country;
	std::string appointment;
	std::string issuer_nature;
	std::string form;
	std::string material;

public:
	Stamp();
	virtual ~Stamp();
	void create();

	void set_country_existence(bool);
	void set_appointment(std::string);
	void set_issuer(std::string);
	void set_form(std::string);
	void set_material(std::string);

	bool get_country_existence() const;
	std::string get_appointment();
	std::string get_issuer();
	std::string get_form();
	std::string get_material();
};