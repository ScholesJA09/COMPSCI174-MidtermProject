#include <iostream>
#include <string>

int main()
{
	//Minamal Viable Product
	//1
	std::string temp;
	int convert_num;
	while (true) {
		while (true) {
			std::cout << "Type the measurement you want to convert (1 for distance, 2 for temperature, 3 for mass)." << std::endl;
			std::cout << "Type 'exit' or 'quit' to leave." << std::endl;
			std::getline(std::cin, temp);
			if (temp == "quit" || temp == "exit") { 
				std::cout << "Goodbye!" << std::endl;
				return 0; }
			else {}

			try
			{
				convert_num = std::stoi(temp);
			}
			catch (std::exception e)
			{
				std::cout << "Invalid input, please enter a number." << std::endl;
				continue;
			}

			if (convert_num < 1 || convert_num > 3)
			{
				std::cout << "Invalid input, number must be 1, 2 or 3." << std::endl;
				continue;
			}
			else { break; }
		}
		//2
		int measurement_num;
		while (true) {
			std::cout << "Would you like your value in Metric or Imperial (1 for metric, 2 for imperial)?" << std::endl;
			std::getline(std::cin, temp);

			try
			{
				measurement_num = std::stoi(temp);
			}
			catch (std::exception e)
			{
				std::cout << "Invalid input, please enter a number." << std::endl;
				continue;
			}

			if (measurement_num < 1 || measurement_num > 2)
			{
				std::cout << "Invalid input, number must be 1 or 2." << std::endl;
				continue;
			}
			else { break; }
		}
		//3
		double value;
		while (true) {
			std::cout << "What value do you wish to convert?" << std::endl;
			std::getline(std::cin, temp);

			try
			{
				value = std::stod(temp);
			}
			catch (std::exception e)
			{
				std::cout << "Invalid input, please enter a number." << std::endl;
				continue;
			}
			//4
			if (convert_num == 1)
			{
				if (value < 0)
				{
					std::cout << "Invalid input, distance cannot be negative." << std::endl;
					continue;
				}
				else { break; }
			}
			else if (convert_num == 2)
			{
				if (value < -273.15)
				{
					std::cout << "Invalid input, temperature cannot be below absolute zero." << std::endl;
					continue;
				}
				else { break; }
			}
			else
			{
				if (value < 0)
				{
					std::cout << "Invalid input, mass cannot be negative." << std::endl;
					continue;
				}
				else { break; }
			}
		}


		//5
		double convert_value;
		if (convert_num == 1)
		{
			if (measurement_num == 1)
			{
				convert_value = value * 0.3048;
				std::cout << "Conversion: " << value << "ft = " << convert_value << "m." << std::endl;
			}
			else
			{
				convert_value = value / 0.3048;
				std::cout << "Converstion: " << value << "m. = " << convert_value << "ft." << std::endl;
			}
		}
		else if (convert_num == 2)
		{
			if (measurement_num == 1)
			{
				convert_value = (value - 32) * 5 / 9;
				std::cout << "Conversion: " << value << "F = " << convert_value << "C" << std::endl;
			}
			else
			{
				convert_value = value * 9 / 5 + 32;
				std::cout << "Conversion: " << value << "C = " << convert_value << "F" << std::endl;
			}
		}
		else
		{
			if (measurement_num == 1)
			{
				convert_value = value * 453.592;
				std::cout << "Conversion: " << value << "lb. = " << convert_value << "g." << std::endl;
			}
			else
			{
				convert_value = value / 453.592;
				std::cout << "Conversion: " << value << "g. = " << convert_value << "lb." << std::endl;
			}
		}
	}
	
	return 0;
}