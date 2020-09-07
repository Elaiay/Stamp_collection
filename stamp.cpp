#include <iostream>
#include "stamp.h"
#include "valid.h"

using namespace std;

Stamp::Stamp()
{
}

Stamp::~Stamp()
{
}

void Stamp::create()
{
	do
	{
		cout << "1. Stamp appointment: ";
		getline(cin, appointment);
	} while (!str_valid(appointment));

	do
	{
		cout << "2. Issuer nature: ";
		getline(cin, issuer_nature);
	} while (!str_valid(issuer_nature));

	do
	{
		cout << "3. Stamp form: ";
		getline(cin, form);
	} while (!str_valid(form));

	do
	{
		cout << "4. Stamp material: ";
		getline(cin, material);
	} while (!str_valid(material));
}

void Stamp::set_country_existence(bool is_real)
{
	this->existent_country = is_real;
}

void Stamp::set_appointment(string appointment)
{
	this->appointment = appointment;
}

void Stamp::set_issuer(string issuer_nature)
{
	this->issuer_nature = issuer_nature;
}

void Stamp::set_form(string form)
{
	this->form = form;
}

void Stamp::set_material(string material)
{
	this->material = material;
}

bool Stamp::get_country_existence() const
{
	return this->existent_country;
}

string Stamp::get_appointment()
{
	return this->appointment;
}

string Stamp::get_issuer()
{
	return this->issuer_nature;
}

string Stamp::get_form()
{
	return this->form;
}

string Stamp::get_material()
{
	return this->material;
}