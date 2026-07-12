/**
@Author: MrKeanu
@Date: 2026-07-12
@Description: FntApp CLI implementation — interactive command loop for running solutions.
@History: 2025-09-08 - Initial implementation registration framework.
*/
#include "fnt_solution.h"
#include <iostream>
using namespace std;

namespace fnt {

const static string CMD_EXIT   = "exit";
const static string CMD_RUN    = "run";
const static string CMD_RUNALL = "runall";
const static string CMD_ERASE  = "erase";
const static string CMD_PRINT  = "print";
const static string CMD_CLEAR  = "clear";

void FntApp::Run() {
    cout << R"(
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
    )" << endl << endl;

    cout << "------------- Welcome, adventurer!-------------" << endl;

    string command;
    // 首次进入直接进入 run 子模式
    goto RUN;

    while (true) {
        cout << "Enter a command (run, runall, print, erase, clear, exit): ";
        cin >> command;

        if (command == CMD_RUN) {
        RUN:
            while (true) {
                cout << "please enter the name of the solution to run (or enter 'exit' to exit): ";
                string solutionName;
                cin >> solutionName;
                if (solutionName == CMD_EXIT) break;
                else Execute(solutionName);
            }
        }
        else if (command == CMD_PRINT) {
            Print();
        }
        else if (command == CMD_ERASE) {
            while (true) {
                cout << "please enter the name of the solution to erase (or enter 'exit' to exit): ";
                string solutionName;
                cin >> solutionName;
                if (solutionName == CMD_EXIT) break;
                else Unregister(solutionName);
            }
        }
        else if (command == CMD_CLEAR) {
            Clear();
        }
        else if (command == CMD_RUNALL) {
            RunAll();
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

} // namespace fnt