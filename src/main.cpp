#include "iostream"
#include "string"
#include "algorithm"
#include "ExpenseSheet.h"
#include "InputArguments.h"

int main()
{
	std::string line;
	ExpenseSheet expenseSheet;
	while(true)
	{
		// Get command
		std::cout << ">";
		std::getline(std::cin, line);
		InputArguments args(line);

		std::string cmd = args.count() > 0 ? args[0] : "";

		auto argsSubset = args.subset(1);
		
		// Convert command to lowercase
		std::transform(cmd.begin(), cmd.end(), cmd.begin(), [](char c)
		{
			return std::tolower(c);
		});
		
		if (cmd == "add")
		{
			if(argsSubset.count() == 2 || argsSubset.count() == 3)
			{
				const auto& label = argsSubset[0];
				double amount = 0;
				if(argsSubset.count() == 2)
				{
					amount = std::stod(argsSubset[1]);

					if(argsSubset[1][0] != '+' && argsSubset[1][0] != '-')
						amount *= -1;
				}
				else
				{
					amount = std::stod(argsSubset[2]);
					
					if(argsSubset[1] != "+")
						amount *= -1;
				}
				
				if(expenseSheet.Add(label, amount))
				{
					std::cout << "Added \"" << label << "\"\n";
				}
				else
				{
					std::cout << "Label \"" << label << "\" already exists\n";
				}
			}
			else
			{
				std::cout << "Invalid number of arguments\n";
			}
		}
		else if (cmd == "remove")
		{
			if(argsSubset.count() == 1)
			{
				auto label = argsSubset[0];
				bool removed = expenseSheet.Remove(label);
				if(removed)
				{
					std::cout << "Removed \"" << label << "\"\n";
				}
				else
				{
					std::cout << "Label \"" << label << "\" not found\n";
				}
			}
			else
			{
				std::cout << "Invalid number of arguments\n";
			}
		}
		else if (cmd == "list")
		{
			expenseSheet.List(std::cout);
		}
		else if (cmd == "calculate")
		{
			auto total = expenseSheet.Calculate();
			std::cout << "total: "<<total<<"\n";
		}
		else if (cmd == "exit")
		{
			break;
		}
		else
		{
			std::cout << "Invalid command \"" << cmd << "\"\n";
		}
	}
}