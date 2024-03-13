#include <iostream>
#include <fstream>

void prog(char **argv)
{
	std::string myText;
	std::ifstream MyReadFile(argv[1]);
	if (!MyReadFile.is_open())
	{
		std::cerr << "Failed to open the file.\n";
		return ;
	}
	std::string file = argv[1];
	int i = file.find_last_of(".");
	std::string filename = file.substr(0, i) + ".replace";
	std::ofstream outfile (filename);
	while (std::getline (MyReadFile, myText))
	{
		while (1)
		{
			size_t pos = myText.find(argv[2]);
			if (pos != std::string::npos)
    			myText = myText.substr(0, pos) + argv[3] + myText.substr(pos + strlen(argv[2]));
			else
				break ;
		}
		outfile << myText << std::endl;
	}
	MyReadFile.close();
	outfile.close();
}

int main(int argc, char **argv)
{
	if (argc != 4)
		std::cout << "Wrong number of arg" << std::endl;
	else
		prog(argv);
	return 0;
}
