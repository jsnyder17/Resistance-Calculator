//*______ Joshua Snyder ______*//

/*
	Calcualtes the equivalent resistance of series and parallel circuits 
*/

#include <iostream>

template <class T>
T getInput() {
	T input;
	bool goodData = false;

	while (!goodData) {
		std::cin >> input;

		// Check input 
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(256, '\n');

			std::cout << std::endl;
			std::cout << "-- INVALID INPUT --" << std::endl;
			std::cout << "Enter a vaild value -> ";
		}
		else if (input < 0) {
			std::cout << std::endl;
			std::cout << "-- INVALID INPUT --" << std::endl;
			std::cout << "Enter a vaild value -> ";
		}
		else {
			goodData = true;
		}
	}

	return input;
}

double calculateResistance(const int& CONFIG, const int& RESISTOR_AMT) {
	double resistors[RESISTOR_AMT];
	double resistance = 0.0;
	double result = 0.0;
	
	std::cout << std::endl;
	std::cout << "--------------------------------------------------------------------" << std::endl;
	std::cout << std::endl;
	
	// Get resistance of resistors from user 
	for (int i = 0; i < RESISTOR_AMT; i++) {
		std::cout << "Enter the resistance of " << "R" << i + 1 << " -> ";
		resistance = getInput<double>();
		
		resistors[i] = resistance;
		
		std::cout << std::endl;
	}
	
	std::cout << "--------------------------------------------------------------------" << std::endl;
	std::cout << std::endl;
	
	// Determine calculation
	switch (CONFIG) {
		case 0:		// Serial 
			
			std::cout << "Calculating resistance for series ciruit ... " << std::endl;
			
			for (int i = 0; i < RESISTOR_AMT; i++) {
				result += resistors[i];
			}
			
			break;
		case 1:		// Parallel
		
			std::cout << "Calculating resistance for parallel circuit ... " << std::endl;
		
			double rTotal = 0.0;
			
			for (int i = 0; i < RESISTOR_AMT; i++) {
				rTotal += (1/resistors[i]);
			}
			
			result = (1/rTotal);
		
			break;
	}
	
	return result;
}

void start() {
	int config = 0;
	int resistorAmt;
	double result = 0.0;
	
	std::cout << std::endl;
	
	// Display title
	std::cout << "****** Resistance Calculator v0.1 *******" << std::endl;
	std::cout << "By Joshua Snyder " << std::endl << std::endl;
	
	// Get circuit configuration from user 
	std::cout << "Series '0' or parallel '1'? -> ";
	config = getInput<int>();
	
	std::cout << std::endl;
	
	// Get number of resistors in circuit from user 
	std::cout << "Enter the number of resistors in the circuit -> ";
	resistorAmt = getInput<int>();
	
	// Calculate resistance 
	result = calculateResistance(config, resistorAmt);
	
	std::cout << std::endl;
	
	// Output result 
	std::cout << "RESULT: " << result << std::endl;
	
	std::cout << std::endl;
	
	// Prompt user to exit application 
	std::cout << "-- Press 'ENTER' to exit --" << std::endl;
	std::cin.clear();
	std::cin.ignore(256, '\n');
	std::cin.ignore();
}

int main(void) {
	start();
	
	return 0;
}