# include "contact.hpp"

void ft_add(int i, PhoneBook *contact)
{
	std::string buffer;

	i =  (i % 8);
	contact->num = i + 1;
	std::cout << "first name : ";
	std::cin >> buffer;
	contact->Cons[i].first = buffer;
	std::cout << "last name : ";
	std::cin >> buffer;
	contact->Cons[i].last = buffer;
	std::cout << "nickname : ";
	std::cin >> buffer;
	contact->Cons[i].nick = buffer;
	std::cout << "phone number : ";
	std::cin >> buffer;
	contact->Cons[i].phone_num = buffer;
	std::cout << "darkest secret : ";
	std::cin >> buffer;
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
	std::string buffer;

	while (++i < 8)
		change(contact, i);
	std::cout << "|     Index|first name| last name|  nickname|" << std::endl;
	std::cout << "|         1|" << contact->Cons[0].abr_first << "|" << contact->Cons[0].abr_last << "|" << contact->Cons[0].abr_nick << "|" << std::endl;
	std::cout << "|         2|" << contact->Cons[1].abr_first << "|" << contact->Cons[1].abr_last << "|" << contact->Cons[1].abr_nick << "|" << std::endl;
	std::cout << "|         3|" << contact->Cons[2].abr_first << "|" << contact->Cons[2].abr_last << "|" << contact->Cons[2].abr_nick << "|" << std::endl;
	std::cout << "|         4|" << contact->Cons[3].abr_first << "|" << contact->Cons[3].abr_last << "|" << contact->Cons[3].abr_nick << "|" << std::endl;
	std::cout << "|         5|" << contact->Cons[4].abr_first << "|" << contact->Cons[4].abr_last << "|" << contact->Cons[4].abr_nick << "|" << std::endl;
	std::cout << "|         6|" << contact->Cons[5].abr_first << "|" << contact->Cons[5].abr_last << "|" << contact->Cons[5].abr_nick << "|" << std::endl;
	std::cout << "|         7|" << contact->Cons[6].abr_first << "|" << contact->Cons[6].abr_last << "|" << contact->Cons[6].abr_nick << "|" << std::endl;
	std::cout << "|         8|" << contact->Cons[7].abr_first << "|" << contact->Cons[7].abr_last << "|" << contact->Cons[7].abr_nick << "|" << std::endl;
	std::cout << "Choose index : ";
	std::cin >> buffer;
	if (buffer.compare("1") != 0 && buffer.compare("2") != 0 && buffer.compare("3") != 0 && buffer.compare("4") != 0 && buffer.compare("5") != 0 && buffer.compare("6") != 0 && buffer.compare("7") != 0 && buffer.compare("8") != 0)
	{
		std::cout << "Index don't exist" << std::endl;
		return ;
	}
	i = std::stoi(buffer) - 1;
	std::cout << "First name : " << contact->Cons[i].first << std::endl;
	std::cout << "Last name : "<< contact->Cons[i].last << std::endl;
	std::cout << "Nickname : "<< contact->Cons[i].nick << std::endl;
	std::cout << "Phone number : "<< contact->Cons[i].phone_num << std::endl;
	std::cout << "Darkest secret : "<< contact->Cons[i].secret << std::endl;
}

int main()
{
	std::string input;
	PhoneBook contact;
	int i = -1;

	std::cout << "Write ADD, SEARCH or EXIT : ";
	while (1)
	{
		getline(std::cin, input);
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
			std::cout << "Write ADD, SEARCH or EXIT : ";
	}
	return 0;
}
