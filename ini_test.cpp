// ini_test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ini.h"

#include <sstream>

int main()
{
#if 0
		INI config_ini("c:\\programdata\\sun.ini", false);
		std::string paskey, id;
		if (config_ini.Parse())
		{
			id = config_ini.Get("base", "fastcode", "empty");
			id.erase(0, 1);
			paskey = config_ini.Get("base", "encry_pwd", "empty");
		}
		std::cout << id << " " << paskey << std::endl;
#else
		std::ifstream in("c:\\programdata\\sun.ini", std::ios::in | std::ios::binary);
        auto current = in.tellg();
        in.seekg(0, in.end);
        auto length = in.tellg();
        in.seekg(current, in.beg);

		if(length == 0)
			return 0;
		char* content = new char[length];
		memset(content, 0, length);
		in.read(content, length);
		in.close();

		std::string scontent;
		scontent.assign(content, length);
		//delete[] content;
		//std::shared_ptr<std::istream> is = std::make_shared<std::istringstream>(content, length);
		//or
		std::shared_ptr<std::istream> is = std::make_shared<std::istringstream>(content);
		INI config_ini(is);
		std::string paskey, id;
		if (config_ini.Parse())
		{
			id = config_ini.Get("base", "fastcode", "empty");
			id.erase(0, 1);
			paskey = config_ini.Get("base", "encry_pwd", "empty");
		}
		std::cout << id << " " << paskey << std::endl;
#endif
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
