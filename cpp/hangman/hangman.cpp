#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cctype>


std::string select_word();
std::string generate_output(std::string letterGuesses, std::string secretWord);
bool start_game();
std::string get_guess(const std::string letterGuesses, const std::string guessOutput, const int strikes);

int main()
{
    bool wantToPlay = start_game();

    if (!wantToPlay) // they dont want to play
    {
        std::cout << "\nfine i didnt want to play either\n\n";
        return 1;
    }
    else // they do want to play
    {
        std::string secretWord = select_word(); // get the random word
        std::cout << secretWord << '\n';
        std::string letterGuesses; // list of the letters they have guessed
        int strikes = 0;
        bool playerWon = false;
        std::string guessOutput;
        std::string letterGuess;

        while (strikes < 6 && !playerWon) // if player wins or gets to many strikes, game ends
        {
            guessOutput = generate_output(letterGuesses, secretWord);
            std::string guess = get_guess(letterGuesses, guessOutput, strikes);

            if (guess.length() == 1) // if they guessed a letter
            {
                bool guessWasRight = false;

                for (int i = 0; i < secretWord.length(); i++) // check if guess is right
                {
                    if (guess[0] == secretWord[i])
                    {
                        guessWasRight = true;
                        break;
                    }
                }
                if (!guessWasRight) // if guess wasnt right
                {
                    strikes++;
                }
                letterGuesses.push_back(guess[0]); // add guess to the guesses

                bool AllLettersGuessed = true;
                for (int i = 0; i < secretWord.length(); i++) // check if the person guessed all of the letters
                {
                    if (secretWord[i] == ' ')
                    {
                        continue;
                    }

                    bool letterWasGuessed = false;

                    for (int j = 0; j < letterGuesses.length(); j++)
                    {
                        if (letterGuesses[j] == secretWord[i])
                        {
                            letterWasGuessed = true;
                            break;
                        }
                    }
                    if (!letterWasGuessed)
                    {
                        AllLettersGuessed = false;
                        break;
                    }
                }
                if (AllLettersGuessed)
                {
                    playerWon = true;
                }
            }

            else // if they guessed the whole sentance
            {
                bool guessWasNotRight = false;

                if (guess.length() != secretWord.length())
                {
                    std::cout << "\n\ncheck how long that guess was...\n\n";
                    continue;
                }
                for (int i = 0; i < secretWord.length(); i++)
                {
                    if (guess[i] != secretWord[i])
                    {
                        guessWasNotRight = true;
                        break;
                    }
                }
                if (guessWasNotRight)
                {
                    strikes++;
                }
                else // guess was right
                {
                    playerWon = true;
                }
            }
        }
        if (playerWon)
        {
            std::cout << "\nCongratulations!! You Won!\nthe word was " << secretWord << '\n';
        }
        else // if person got too many strikes
        {
            std::cout << "\nSowwy, looks like you lost :(\nthe word was " << secretWord << '\n';
        }
    }
}
std::string select_word()
{
    std::vector<std::string> words = { // list of all possible words
        "hangman",
        "benjamin",
        "cool guy",
        "flying toaster",
        "angry cactus",
        "space waffle",
        "awkward penguin",
        "robot dentist",
        "lost sock",
        "tired wizard",
        "sneezing panda",
        "haunted taco",
        "grumpy unicorn",
        "banana phone",
        "tiny tornado",
        "secret potato",
        "loud sandwich",
        "bored dragon",
        "melting snowman",
        "hidden pickle",
        "exploding marshmallow",
        "pirate hamster",
        "flamingo ballet",
        "zombie coffee",
        "moon cheese",
        "nervous turtle",
        "shouting broccoli",
        "dancing spaghetti",
        "cheeseburger planet",
        "giggling ghost",
        "broken broomstick",
        "escaped donut",
        "howling cat",
        "suspicious pancake",
        "whistling teapot",
        "lazy ninja",
        "stuck zipper",
        "giant chicken",
        "sparkling couch",
        "juggling octopus",
        "tripping elephant",
        "screaming muffin",
        "sleepy volcano"
    };

    std::srand(std::time(nullptr)); // seed random generator
    int randomIndex = rand() % (words.size()); // get the random index
    return words[randomIndex];
}

std::string generate_output(const std::string letterGuesses, const std::string secretWord)
{
    std::string guessOutput;
    for (int i = 0; i < secretWord.length(); i++)
    {
        if (secretWord[i] == ' ') // if space
        {
            guessOutput.push_back(' ');
            guessOutput.push_back(' ');
        }
        else // if letter
        {
            bool letterGuessed = false;

            for (int j = 0; j < letterGuesses.length(); j++) // iterate through Player's guesses
            {
                if (secretWord[i] == letterGuesses[j]) // player guessed the letter
                {
                    letterGuessed = true;
                    guessOutput.push_back(letterGuesses[j]);
                    guessOutput.push_back(' ');
                    break;
                }
            }
            if (!letterGuessed) // if the player hasnt guessed the letter
            {
                guessOutput.push_back('_');
                guessOutput.push_back(' ');
            }
        }
    }

    guessOutput.pop_back(); // strip the last space
    return guessOutput;
}

bool start_game()
{
    while (true) // get input
    {
        std::string input;

        std::cout << "Start Game? (Y/N) ";
        std::getline(std::cin, input);

        for (int i = 0; i < input.size(); i++) // convert input to lower
        {
            input[i] = std::tolower(input[i]);
        }

        if (input == "n" || input == "no")
        {
            return false;
        }
        else if (input == "y" || input == "yes")
        {
            return true;
        }
        else
        {
            std::cout << "\n\ninvalid input (Y/N), try again\n\n";
        }
    }
}

std::string get_guess(const std::string letterGuesses, const std::string guessOutput, const int strikes)
{
    std::string guess;
    bool invalidInput = false;

    while (true)
    {
        std::cout << "strikes: " << strikes << "   guesses: ";

        if (letterGuesses.length() > 0)
        {
            for (int i = 0; i < letterGuesses.length() - 1; i ++)
            {
                std::cout << letterGuesses[i] << ", ";
            }
            std::cout << letterGuesses.back();
        }
        else
        {
            std::cout << "N/A";
        }

        std::cout << "\n\n" << guessOutput << "\n\n" << "guess? ";
        std::getline(std::cin, guess);

        if (guess.length() <= 0) // check that they inputted something
        {
            std::cout << "\n\nmust input a letter or guess the whole phrase\n\n";
            continue;
        }

        if (guess.length() == 1) // if they inputted a single letter
        {
            if (!isalpha(guess[0]))
            {
                std::cout << "\n\nmust input a letter\n\n";
                continue;
            }

            for (int i = 0; i < letterGuesses.length(); i++)
            {
                if (guess[0] == letterGuesses[i]) // check that they hadnt already guessed the letter
                {
                    std::cout << "\n\nyou already guessed that lettter\n\n";
                    invalidInput = true;
                    break;
                }
            }
            if (invalidInput)
            {
                invalidInput = false;
                continue;
            }
            return guess;
        }

        else // they are guessing the whole phrase
        {
            for (int i = 0; i < guess.length(); i++)
            {
                if (!isalpha(guess[i]) && guess[i] != ' ') // check input is all letters
                {
                    std::cout << "\n\nletters only\n\n";
                    invalidInput = true;
                    break;
                }
            }
            if (invalidInput)
            {
                invalidInput = false;
                continue;
            }
            return guess;
        }
    }
}

