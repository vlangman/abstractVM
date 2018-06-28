#include <iostream>
#include <fstream>
#include "parser.hpp"
#include "lexer.hpp"

int		main(int argc, char **argv)
{
	std::string myLine;
	Parser		parser;
	Lexer		lexer;
	int			parserError = 0;
	int			count = 1;
	
	std::vector<Instruction*>	instruct;

	if (argc < 2){
		std::cout << "no args entering command mode..." << std::endl;
		std::ofstream writeFile;
		writeFile.open ("custom.avm");

		for(;;){
			std::getline (std::cin,myLine);
			writeFile << myLine << std::endl;
			if (!myLine.compare(";;")){
				break;
			}
		}
		writeFile.close();
		std::ifstream	myFile("custom.avm");
		while(getline(myFile, myLine)){
			try{
				parser.parseLine(myLine);
			}catch(std::exception &e){
				std::cout<< "\033[1;31mLine: " << count << " Error: \033[0m";
				std::cout << e.what() << std::endl;
				parserError = 1;
			}
			count++;
		}
		instruct = parser.getInstructions();
		lexer.checkInstructions(instruct);
		if (lexer.getFlag()){
			lexer.printErrors();
		}
		return 0;
	}
	else{
		
		std::ifstream				myFile(argv[1]);

		if (myFile.is_open()){
			while(getline(myFile, myLine)){
				try{
					parser.parseLine(myLine);
				} catch(std::exception &e){
					std::cout<< "\033[1;31mLine: " << count << " Error: \033[0m";
					std::cout << e.what() << std::endl;
					parserError = 1;
				}
				count++;
			}

			instruct = parser.getInstructions();
			lexer.checkInstructions(instruct);
			if (lexer.getFlag()){
				lexer.printErrors();
			}
		}
		else{
			std::cout << "an error occured opening file" << std::endl;
			return 0;
		}
	}
	return 0;
}
