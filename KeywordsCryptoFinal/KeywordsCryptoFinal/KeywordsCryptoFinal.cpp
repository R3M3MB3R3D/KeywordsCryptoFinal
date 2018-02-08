#include "stdafx.h"
#include "iostream"
#include "string"
#include "cstdlib"
#include "ctime"

using namespace std;

int main()
{
	enum fields { WORD, HINT, NUM_FIELDS }; // the lists we can put questions and answers into
											//enum difficulty {EASY, MEDIUM, HARD, NUM_DIFF_LEVEL}; // difficulty selector (not used)
	const int NUM_WORDS = 10; // the number of guessable words
	const string WORDS[NUM_WORDS][NUM_FIELDS] = //list of words with their hints
	{
		{ "superfluous", "Redundant, extra, more than necessary, way too much." },
		{ "enigmatic", "guarded, secretive, mysterious." },
		{ "reconciliation", "to make amends, to become friendly again, to bring together." },
		{ "determination", "persistent, motivated, not gonna give up." },
		{ "discombobulated", "to be confused, to not understand, not knowing whats going on." },
		{ "aerodynamic", " mostly regarding airplanes, interacting with wind" },
		{ "cyberphobia", "to fear computers, ahmish people are this, among other things." },
		{ "antidisestablishmentarianism", "good luck" },
		{ "incomprehensible", "not being able to be understood, illogical, possibly ironic" },
		{ "unimaginatively", "without imagination, not inspired, practical" }
	};

	//cout << "There are " << NUM_DIFF_LEVEL << " difficulty levels.\n\n";
	srand(static_cast<unsigned int>(time(0))); //seeding a random number generator
	char playAgain;

	cout << "Welcome to Keywords!\n";
	cout << "Unscramble the letters to make a word.\n";
	cout << "Enter -hint- for a hint.\n";
	cout << "Enter -quit to exit the program!\n";
	cout << "=========================================\n\n";

	do //creating a way to start a new iteration
	{
		int totalAttempts = 0;

		for (int answers = 0; answers < 3; answers++) //creating an iteration
		{
			int choice = (rand() % NUM_WORDS); // using the random number generator to select a word
			string theWord = WORDS[choice][WORD]; //word to guess
			string theHint = WORDS[choice][HINT]; //hint for word
			string jumble = theWord; //mixing up the word
			int length = jumble.size(); //length of the word

			for (int i = 0; i < length; ++i)
			{
				int index1 = (rand() % length);
				int index2 = (rand() % length);
				char temp = jumble[index1];
				jumble[index1] = jumble[index2];
				jumble[index2] = temp;
			} //the randomizer, basically rebuilds the word by scrambling it once for every letter in the word... I think...

			cout << "The jumble is: " << jumble; string guess;
			cout << "\nYour Guess: ";
			cin >> guess;
			int attempts = 1;
			totalAttempts++;

			while ((guess != theWord) && (guess != "quit"))
			{
				if (guess == "hint")
				{
					cout << theHint << "\n";
				}
				else
				{
					cout << "I'm not sorry, but that's not it.\n";
					attempts++;
					totalAttempts++;
				}
				cout << "Your Guess: ";
				cin >> guess;
			}

			if (guess == theWord)
			{
				cout << "That's it!\n";
				cout << "You got it in: " << attempts << " attempts.\n\n"; //showing attempts for the current word
			}
		}

		cout << "You completed this iteration with " << totalAttempts << " total guesses.  Congratulations.\n"; //showing total tries for each iteration

		cout << "Would you like to go another round?\n";
		cout << "Please input y or n to answer: ";
		cin >> playAgain;
		while ((playAgain != 'y') && (playAgain != 'Y') && (playAgain != 'n') && (playAgain != 'N')) //ensuring a proper response
		{
			cout << "That is not an acceptable response, please input y or n.\n";
			cin >> playAgain;
		}
	} while ((playAgain == 'y') || (playAgain == 'Y')); //the end of the do loop that allows replay

	cout << "Thanks for training!\n";
	system("pause");

	return 0;
}