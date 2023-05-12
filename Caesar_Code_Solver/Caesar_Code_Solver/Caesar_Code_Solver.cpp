#include <iostream>
#include <string>

std::string Decoder(std::string code, int key)
{
	std::string result = "";
	int new_number;
	char new_letter;

	for (char c : code)
	{
		if (c >= 'a' && c <= 'z')
		{
			new_number = int(c) + key;
			if (new_number > 'z')
			{
				new_letter = char('a' + (new_number - 'z'));
			}
			else if (new_number < 'a')
			{
				new_letter = char('z' - ('a' - new_number - 1));
			}
			else {
				new_letter = char(new_number);
			}
		}
		else if (c >= 'A' && c <= 'Z')
		{
			new_number = int(c) + key;
			if (new_number > 'Z')
			{
				new_letter = char('A' + (new_number - 'Z'));
			}
			else if (new_number < 'A')
			{
				new_letter = char('Z' - ('A' - new_number));
			}
			else {
				new_letter = char(new_number);
			}
		}
		else
		{
			new_letter = c;
		}
		result += new_letter;
	}
	return result;
}

int main()
{
	std::string text_to_decipher_1 = "zbw nytbelgz qmvnyn anjrg qyn m v n"; // offset to decode -13
	std::string text_to_decipher_2 = "Zbw nytbelgz qmvnyn qyn qbqngavrtb cemrfhavrpvn"; // offset to decode 13


	std::cout << Decoder(text_to_decipher_1, -13) << std::endl;
	std::cout << Decoder(text_to_decipher_2, 13) << std::endl;
}


