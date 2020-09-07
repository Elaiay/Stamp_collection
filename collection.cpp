#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <algorithm>
#include "collection.h"
#include "existent.h"
#include "nonexistent.h"

using namespace std;

void Collection::create_existent()
{
	this->stamps.push_back(new Existent());
}

void Collection::create_non_existent()
{
	this->stamps.push_back(new Nonexistent());
}

void Collection::read_from_file(int num)
{
	Stamp *stamp = new Stamp;
	ifstream fin;
	string str;
	int flag = 1;
	int pos;

	try
	{
		fin.open("stamps.txt");
		if (!fin.is_open())
			throw exception("File \"stamps.txt\" can not be opened");

		if (fin.peek() == EOF)
			throw exception("File \"stamps.txt\" is empty");

		while (fin.peek() != EOF && num != 0)
		{
			getline(fin, str);
			if (str.empty())
				continue;
			
			cout << str << endl;

			switch (flag)
			{
			case 1:
				if (pos = str.find("Country existence: ") != 0)
					throw exception("There is a country existence error in the file");

				str = str.substr(19);
				if (str != "true" && str != "false")
					throw exception("There is a country existence data error in the file");

				stamp->set_country_existence((str == "true") ? true : false);
				break;

			case 2:
				if (pos = str.find("Stamp appointment: ") != 0)
					throw exception("There is a stamp appointment error in the file");

				str = str.substr(19);
				if (str.empty())
					throw exception("There is a stamp appointment data error in the file");

				stamp->set_appointment(str);
				break;

			case 3:
				if (pos = str.find("Issuer nature: ") != 0)
					throw exception("There is a issuer nature error in the file");

				str = str.substr(15);
				if (str.empty())
					throw exception("There is a issuer nature data error in the file");

				stamp->set_issuer(str);
				break;

			case 4:
				if (pos = str.find("Stamp form: ") != 0)
					throw exception("There is a stamp form error in the file");

				str = str.substr(12);
				if (str.empty())
					throw exception("There is a stamp form data error in the file");

				stamp->set_form(str);
				break;

			case 5:
				if (pos = str.find("Stamp material: ") != 0)
					throw exception("There is a stamp material error in the file");

				str = str.substr(16);
				if (str.empty())
					throw exception("There is a stamp material data error in the file");

				stamp->set_material(str);
				break;
			}

			if (flag == 5)
			{
				cout << endl;
				flag = 0;
				this->stamps.push_back(stamp);
				stamp = new Stamp;
				--num;
			}

			++flag;
		}
	}
	catch (exception &ex)
	{
		cout << ex.what() << endl;
	}

	getchar();
	fin.close();
}

void Collection::write_to_file()
{
	ofstream fout;

	this->stamps.sort([](const Stamp *s1, const Stamp *s2)
	{
		return s1->get_country_existence() > s2->get_country_existence();
	});

	try
	{
		fout.open("stamps.txt");
		if (!fout.is_open())
			throw exception("File \"stamps.txt\" can not be opened");

		for (auto el : stamps)
		{
			fout << "Country existence: " << boolalpha << el->get_country_existence() << noboolalpha << "\nStamp appointment: "
				<< el->get_appointment() << "\nIssuer nature: " << el->get_issuer() << "\nStamp form: " << el->get_form()
				<< "\nStamp material: " << el->get_material() << endl << endl;
		}
	}
	catch (exception &ex)
	{
		cout << ex.what() << endl;
		getchar();
	}

	fout.close();
}

void Collection::show()
{
	if (stamps.empty())
		cout << "The collection is empty";
	else
	{
		for (auto el : stamps)
		{
			cout << "Country existence: " << boolalpha << el->get_country_existence() << noboolalpha << "\nStamp sppointment: "
				<< el->get_appointment() << "\nIssuer nature: " << el->get_issuer() << "\nStamp form: " << el->get_form()
				<< "\nStamp material: " << el->get_material() << endl << endl;
		}
	}
}

std::list<Stamp*> Collection::get_stamps()
{
	return stamps;
}