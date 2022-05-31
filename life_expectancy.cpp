//Copyright 2022 Anton Pavlyukevich.

//life_expectancy is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.
//
//life_expectancy is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with life_expectancy.  If not, see <https://www.gnu.org/licenses/>.

//
// Created by pavlyukevich.anton@gmail.com on 05.01.22
//

// built and tested on Darwin Kernel Version 18.7.0: Tue Jun 22 19:37:08 PDT 2021; root:xnu-4903.278.70~1/RELEASE_X86_64 x86_64

#include <iostream>

#define B_RED "\033[91m"
#define GREY "\033[2m"
#define BRIGHT_GREY "\033[37m"
#define DARK_GREY "\033[90m"
#define DEFAULT "\033[0m"
#define STRIKETHROUGH "\033[9m"

int main(void)
{
	std::time_t t = std::time(nullptr);
	std::tm *const ltm = std::localtime(&t);
	float birth_year = 1993;
	float many_years = 80;
	unsigned int deadline = birth_year + many_years;
	unsigned int current_year = 1900 + ltm->tm_year;
	unsigned int i = birth_year;
	unsigned int oh_no_no_no_no_no = deadline - 1;
	unsigned int oh_no_no = deadline - 4;
	unsigned int oh_no = deadline - 7;

	while (i <= deadline)
	{
		for (unsigned int k = 0; k < 10; k++)
		{
			if (i == current_year)
				std::cout << B_RED << i << DEFAULT << " ";
			else if (i < current_year)
				std::cout << DARK_GREY << STRIKETHROUGH << i << DEFAULT << " ";
			else if (i > oh_no_no_no_no_no)
				std::cout << DARK_GREY << i << DEFAULT << " ";
			else if (i > oh_no_no)
				std::cout << GREY << i << DEFAULT << " ";
			else if (i > oh_no)
				std::cout << BRIGHT_GREY << i << DEFAULT << " ";
			else if (i > current_year)
				std::cout << i << " ";
			i++;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	return (0);
}
