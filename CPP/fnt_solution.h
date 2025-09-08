/**
@Author: MrKeanu
@Date: 2025-09-08 18:00:00
@Description: This file is a registryor framework for the Solution class, and automatically run in the main function.
*/
#pragma once

#include <functional>
#include <map>
#include <string>
using namespace std;

namespace fnt {
	using SolutionFn = function<void()>;
	// Register a solution with a name, and return a bool indicating whether the registration was successful.
	bool RegisterSolution(const string& name, SolutionFn fn);
	// Unregister a solution with a name.
	void UnregisterSolution(const string& name);
	// Execute the solution with the given name.
	void ExecuteSolution(const string& name);
	// Run all registered solutions.
	void RunSolutions();
	// Print all registered solutions.
	void PrintSolutions();
	// Clear all registered solutions.
	void ClearSolutions();
	// Run the solution with the given name.
	void Run();
}
