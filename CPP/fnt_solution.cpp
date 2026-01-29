/**
@Author: MrKeanu
@Date: 2025-09-08 18:00:00
@Description: This file is a Registrar framework for the Solution class, and automatically run in the main function.
*/
#include "fnt_solution.h"
#include <iostream>

namespace fnt {
	const static string CMD_EXIT = "exit";
	const static string CMD_RUN = "run";
	const static string CMD_RUN_ALL = "runall";
	const static string CMD_ERASE = "erase";
	const static string CMD_PRINT = "print";
	const static string CMD_CLEAR = "clear";

	// Lazy Initialization for avoid Static Initialization Order Fiasco
	map<string, SolutionFn>& GetSolutionRegistry() {
		static map<string, SolutionFn> _SolutionRegistry;
		return _SolutionRegistry;
	}

	bool RegisterSolution(const string& name, SolutionFn fn) {
		auto& SolutionRegistry = GetSolutionRegistry();
		if (SolutionRegistry.find(name) != SolutionRegistry.end()) {
			cout << "------------- Error: Solution registration failed! -------------" << endl;
			return false;
		}
		SolutionRegistry[name] = fn;
		return true;
	}

	void UnregisterSolution(const string& name) {
		auto& SolutionRegistry = GetSolutionRegistry();
		if (SolutionRegistry.empty() || SolutionRegistry.find(name) == SolutionRegistry.end()) {
			cout << "------------- Info: Solution " << name << ".cpp not found! -------------" << endl;
			return;
		}
		SolutionRegistry.erase(name);
		cout << "------------- Info: Solution " << name << ".cpp unregistered! -------------" << endl;
	}

	void ExecuteSolution(const string& name) {
		auto& SolutionRegistry = GetSolutionRegistry();
		if (SolutionRegistry.empty() || SolutionRegistry.find(name) == SolutionRegistry.end()) {
			cout << "------------- Error: Solution " << name << ".cpp not found! -------------" << endl;
			return;
		}
		cout << "------------- Info: Running solution: " << name << ".cpp -------------" << endl;
		SolutionRegistry[name]();
		cout << "------------- Info: Solution " << name << ".cpp finished! -------------" << endl;
	}

	void EraseSolution(const string& name) {
		UnregisterSolution(name);
	}

	void RunSolutions() {
		auto& SolutionRegistry = GetSolutionRegistry();
		for (auto& pair : SolutionRegistry) {
			cout << "------------- Info: Running solution: " << pair.first << ".cpp -------------" << endl;
			pair.second();
			cout << "------------- Info: Solution " << pair.first << ".cpp finished! -------------" << endl;
		}
	}

	void PrintSolutions() {
		auto& SolutionRegistry = GetSolutionRegistry();
		cout << "------------- Info: Available Solutions: -------------" << endl;
		for (auto& pair : SolutionRegistry) {
			cout << pair.first << ".cpp" << endl;
		}
	}

	void ClearSolutions() {
		GetSolutionRegistry().clear();
		cout << "------------- Info: Solutions cleared! -------------" << endl;
	}

	void Run() {
		cout<< R"(
 ________________________________________________________
/                                                        \
|                                                        |
|    _   _      _ _         _    _            _     _    |
|   | | | |    | | |       | |  | |          | |   | |   |
|   | |_| | ___| | | ___   | |  | | ___  _ __| | __| |   |
|   |  _  |/ _ \ | |/ _ \  | |/\| |/ _ \| '__| |/ _` |   |
|   | | | |  __/ | | (_) | \  /\  / (_) | |  | | (_| |   |
|   \_| |_/\___|_|_|\___/   \/  \/ \___/|_|  |_|\__,_|   |
|                                                        |
|            Code everyday, bugs faraway!                |
|                                                        |
|________________________________________________________|
\________________________________________________________/
			)"<<endl<<endl;
		cout << "------------- Welcome, adventurer!-------------" << endl;

		string command;
		goto RUN;
		while (true) {
			cout << "Enter a command (run, runall, print, erase, clear, exit): ";
			cin >> command;
			if (command == "run") {
			RUN:
				while (true) {
					cout << "please enter the name of the solution to run (or enter 'exit' to exit): ";
					string solutionName;
					cin >> solutionName;
					if (solutionName == CMD_EXIT) break;
					else ExecuteSolution(solutionName);
				}
			}
			else if (command == CMD_PRINT) {
				PrintSolutions();
			}
			else if (command == CMD_ERASE) {
				while (true) {
					cout << "please enter the name of the solution to erase (or enter 'exit' to exit): ";
					string solutionName;
					cin >> solutionName;
					if (solutionName == CMD_EXIT) break;
					else EraseSolution(solutionName);
				}
			}
			else if (command == CMD_CLEAR) {
				ClearSolutions();
			}
			else if (command == CMD_RUN_ALL) {
				RunSolutions();
			}
			else if (command == CMD_EXIT) {
				break;
			}
			else {
				cout << "Invalid command. Please try again." << endl;
			}
		}
		cout << "------------- Farewell, adventurer!-------------" << endl;
	}
}