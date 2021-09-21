// Game «Hangman»

#include <iostream>
#include <string>

int main()
{
	std::string words[] = {"BODY", "BOY", "CHILD", "EYE", "FACE", "FAMILY", "FATHER", "FRIEND", "GIRL", "GUY", "HAND", "HEAD",
	"HAUSBAND", "MAN", "MOTHER", "NAME", "PEOPLE", "WIFE", "WOMAN", "DAY", "EVENING", "HOUR", "LIFE", "MINUTE", "MONTH", "MOORNING",
	"NIGHT", "TIME", "WEEK", "YEAR", "AIR", "ANIMAL", "FIRE", "FOOD", "SUN", "TREE", "WATER", "WORLD", "ART", "CASE", "CITY", "COUNTRY",
	"ISSUE", "GAME", "GROUP", "HEALTH", "HISTORY", "HOUSE", "LINE", "PLACE", "ROOM", "SCHOOL", "SHOP", "STREET", "WORK", "BOOK", "CAR",
	"CHAIR", "DOOR", "MONEY", "PAPER", "PEN", "TABLE", "THING", "ANSWER", "END", "QUESTION", "NUMBER", "PRICE", "WAY"
	};

	std::string hidden_word = words[rand() % (sizeof(words) / sizeof(words[0]))];
	std::string guessed_word(hidden_word.length(), '-');
	int attempts = 8;
	char guess;
	std::string used_letters;


	std::cout << "Welcome to the game \"Hangman\"!" << std::endl;
	std::cout << "You need to name the hidden word." << std::endl;
	std::cout << std::endl;

	do {
		std::cout << "WORD: " << guessed_word << std::endl;
		if (!used_letters.empty()) {
			std::cout << "Used letters: ";
			for (int i = 0; i < used_letters.length(); i++) {
				std::cout << used_letters[i] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << attempts << " attempts left." << std::endl;
		std::cout << "Enter a letter: ";
		std::cin >> guess;
		guess = toupper(guess);
		if (used_letters.find(guess) != std::string::npos) {
			std::cout << "Ops.. You have already entered this letter." << std::endl;
			std::cout << std::endl;
			continue;
		}
		used_letters += guess;

		if (hidden_word.find(guess) != std::string::npos) {
			for (int i = 0; i < hidden_word.length(); i++) {
				if (hidden_word[i] == guess) {
					guessed_word[i] = guess;
				}
			}
		}
		else {
			attempts--;
			std::cout << "You entered the wrong letter." << std::endl;
		}
		std::cout << std::endl;
	} while (guessed_word != hidden_word && attempts != 0);

	if (attempts == 0) {
		std::cout << "You have run out of attempts." << std::endl;
		std::cout << "You lose!" << std::endl;

	}
	else {
		std::cout << "Excellent! Word is: " << hidden_word << "." << std::endl;
		std::cout << "You won!";
		std::cout << std::endl;
	}
	system("pause");
	return 0;
}