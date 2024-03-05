# include "contact.hpp"

void ft_add(int i, PhoneBook *contact)
{
	string buffer;

	i =  (i % 8);
	contact->num = i + 1;
	cout << "first name : ";
	cin >> buffer;
	contact->Cons[i].first = buffer;
	cout << "last name : ";
	cin >> buffer;
	contact->Cons[i].last = buffer;
	cout << "nickname : ";
	cin >> buffer;
	contact->Cons[i].nick = buffer;
	cout << "phone number : ";
	cin >> buffer;
	contact->Cons[i].phone_num = buffer;
	cout << "darkest secret : ";
	cin >> buffer;
	contact->Cons[i].secret = buffer;
}

void change(PhoneBook *contact, int i)
{
	contact->Cons[i].abr_first = contact->Cons[i].first;
	contact->Cons[i].abr_last = contact->Cons[i].last;
	contact->Cons[i].abr_nick = contact->Cons[i].nick;
	while (contact->Cons[i].abr_first.size() < 10)
		contact->Cons[i].abr_first = " " + contact->Cons[i].abr_first;
	while (contact->Cons[i].abr_last.size() < 10)
		contact->Cons[i].abr_last = " " + contact->Cons[i].abr_last;
	while (contact->Cons[i].abr_nick.size() < 10)
		contact->Cons[i].abr_nick = " " + contact->Cons[i].abr_nick;
	if (contact->Cons[i].abr_first.size() > 10)
		contact->Cons[i].abr_first = contact->Cons[i].abr_first.substr(0,9) + ".";
	if (contact->Cons[i].abr_last.size() > 10)
		contact->Cons[i].abr_last = contact->Cons[i].abr_last.substr(0,9) + ".";
	if (contact->Cons[i].abr_nick.size() > 10)
		contact->Cons[i].abr_nick = contact->Cons[i].abr_nick.substr(0,9) + ".";
}

void ft_search(PhoneBook *contact)
{
	int i = -1;
	string buffer;

	while (++i < 8)
		change(contact, i);
	cout << "|     Index|first name| last name|  nickname|" << endl;
	cout << "|         1|" << contact->Cons[0].abr_first << "|" << contact->Cons[0].abr_last << "|" << contact->Cons[0].abr_nick << "|" << endl;
	cout << "|         2|" << contact->Cons[1].abr_first << "|" << contact->Cons[1].abr_last << "|" << contact->Cons[1].abr_nick << "|" << endl;
	cout << "|         3|" << contact->Cons[2].abr_first << "|" << contact->Cons[2].abr_last << "|" << contact->Cons[2].abr_nick << "|" << endl;
	cout << "|         4|" << contact->Cons[3].abr_first << "|" << contact->Cons[3].abr_last << "|" << contact->Cons[3].abr_nick << "|" << endl;
	cout << "|         5|" << contact->Cons[4].abr_first << "|" << contact->Cons[4].abr_last << "|" << contact->Cons[4].abr_nick << "|" << endl;
	cout << "|         6|" << contact->Cons[5].abr_first << "|" << contact->Cons[5].abr_last << "|" << contact->Cons[5].abr_nick << "|" << endl;
	cout << "|         7|" << contact->Cons[6].abr_first << "|" << contact->Cons[6].abr_last << "|" << contact->Cons[6].abr_nick << "|" << endl;
	cout << "|         8|" << contact->Cons[7].abr_first << "|" << contact->Cons[7].abr_last << "|" << contact->Cons[7].abr_nick << "|" << endl;
	cout << "Choose index : ";
	cin >> buffer;
	if (buffer.compare("1") != 0 && buffer.compare("2") != 0 && buffer.compare("3") != 0 && buffer.compare("4") != 0 && buffer.compare("5") != 0 && buffer.compare("6") != 0 && buffer.compare("7") != 0 && buffer.compare("8") != 0)
	{
		cout << "Index don't exist" << endl;
		return ;
	}
	i = stoi(buffer) - 1;
	cout << "First name : " << contact->Cons[i].first << endl;
	cout << "Last name : "<< contact->Cons[i].last << endl;
	cout << "Nickname : "<< contact->Cons[i].nick << endl;
	cout << "Phone number : "<< contact->Cons[i].phone_num << endl;
	cout << "Darkest secret : "<< contact->Cons[i].secret << endl;
}

int main()
{
	string input;
	PhoneBook contact;
	int i = -1;

	cout << "Write ADD, SEARCH or EXIT : ";
	while (1)
	{
		getline(cin, input);
		if (input == "EXIT")
			break ;
		else if (input == "ADD")
		{
			i++;
			ft_add(i, &contact);
		}
		else if (input == "SEARCH")
			ft_search(&contact);
		else
			cout << "Write ADD, SEARCH or EXIT : ";
	}
	return 0;
}
