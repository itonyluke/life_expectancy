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
	return (0);
}
