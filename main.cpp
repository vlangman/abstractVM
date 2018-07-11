#include <iostream>
#include <fstream>
#include "parser.hpp"
#include "lexer.hpp"
#include "vm.hpp"


int		main(int argc, char **argv)
{
	std::string myLine;
	Parser		parser;
	Lexer		lexer;
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
			}
			catch(Parser::instructionException &e){
				std::cout<< "\033[1;31mERROR: Line: " << count << " \033[0m";
				std::cout << e.what() << std::endl;
			}
			count++;
		}
		instruct = parser.getInstructions();
		lexer.checkInstructions(instruct);
		if (lexer.getFlag()){
			lexer.printErrors();
			std::cout << "cannot run with errors exiting..." << std::endl;
		}
		else{
			if (parser.getFlag() == 0){
				parser.printInstructions();
				Vm *machine = new Vm(parser.getInstructions());
				machine->run();
				delete machine;
			}
		}
		return 0;
	}
	else{
		std::ifstream				myFile(argv[1]);

		if (myFile.is_open()){
			while(getline(myFile, myLine)){
				try{
					parser.parseLine(myLine);
				}
				catch(Parser::instructionException &e){
					std::cout<< "\033[1;31mERROR: Line: " << count << " \033[0m";
					std::cout << e.what() << std::endl;
				}
				count++;
			}

			instruct = parser.getInstructions();
			// parser.printInstructions();
			lexer.checkInstructions(instruct);
			if (lexer.getFlag()){
				lexer.printErrors();
				std::cout << "cannot run with errors exiting..." << std::endl;
			}
			else{
				if (parser.getFlag() == 0){
					// parser.printInstructions();
					Vm *machine = new Vm(parser.getInstructions());
					machine->run();
					delete machine;
				}
			}
		}
		else{
			std::cout << "an error occured opening file" << std::endl;
			return 0;
		}
	}
	return 0;
}
