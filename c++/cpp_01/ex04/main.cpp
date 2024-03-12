#include <iostream>
#include <fstream>

void prog(char **argv)
{
	std::string myText;
	std::string file = argv[1];
	int i = file.find_last_of(".");
	std::string filename = file.substr(0, i) + ".replace";
	std::ofstream outfile (filename);
	std::ifstream MyReadFile(argv[1]);
	while (std::getline (MyReadFile, myText))
	{
		if (myText.compare(argv[2]) == 0)
			outfile << argv[3] << std::endl;
		else
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
