#include <iostream>
#include <string>
#include "collection.h"
#include "valid.h"

using namespace std;

int main()
{
	Collection collection;
	string tmp;
	int num;
	int menu = 1;

	while (menu)
	{
		system("cls");
		cout << "1. Add stamps to the collection\n"
			<< "2. Show collection\n"
			<< "3. Load stamps from the file\n"
			<< "0. Exit\n";

		while (true)
		{
			cout << "> ";
			getline(cin, tmp);
			menu = atoi(tmp.c_str());
			if (num_valid(tmp))
				if (menu >= 0 && menu <= 3)
					break;
		}

		switch (menu)
		{
		case 1:
			system("cls");
			cout << "How much stamps do you want to add?\n";

			while (true)
			{
				cout << "> ";
				getline(cin, tmp);
				num = atoi(tmp.c_str());
				if (num_valid(tmp))
					if (num > 0)
						break;
			}

			for (int i = 0; i < num; i++)
			{
				system("cls");
				cout << "1. Existent country\n"
					<< "2. Non-existent country\n";

				while (true)
				{
					cout << "> ";
					getline(cin, tmp);
					if (num_valid(tmp))
						if (tmp == "1" || tmp == "2")
							break;
				}

				if (tmp == "1")
					collection.create_existent();
				else
					collection.create_non_existent();
			}
			break;

		case 2:
			collection.show();
			getchar();
			break;

		case 3:
			system("cls");
			cout << "How much ships do you want to read from file?\n";

			while (true)
			{
				cout << "> ";
				getline(cin, tmp);
				num = atoi(tmp.c_str());
				if (num_valid(tmp))
					if (num > 0)
						break;
			}

			collection.read_from_file(num);
			break;
		}
	}

	collection.write_to_file();
	return 0;
}