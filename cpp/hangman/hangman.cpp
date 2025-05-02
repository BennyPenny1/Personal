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
        std::cout << "fine i didnt want to play either\n";
        return 1;
    }
    else // they do want to play
    {
        std::string secretWord = select_word(); // get the random word
        std::string letterGuesses; // list of the letters they have guessed
        int strikes = 0;
        bool playerWon = false;
        std::string guessOutput;
        std::string letterGuess;

        while (strikes < 6 && !playerWon) // if player wins or gets to many strikes, game ends
        {
            guessOutput = generate_output(letterGuesses, secretWord);
            std::string guess = get_guess(letterGuesses, guessOutput, strikes);

            if (guess.length() == 1)
            {
                for (int i = 0; i < secretWord.length(); i++)
                {
                    // left off
                }
            }

        }
    }
}
std::string select_word()
{
    std::vector<std::string> words = { // list of all possible words
        "hangman",
        "benjamin",
        "cool guy"
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
        "sleepy volcano",
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
        std::cin >> input;

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
            std::cout << '\n' << "invalid input (Y/N), try again\n";
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
        for (int i = 0; i < letterGuesses.length() - 1; i ++)
        {
            std::cout << letterGuesses[i] << ", ";
        }
        std::cout << letterGuesses.back() << "\n" << guessOutput << '\n' << "guess? ";
        std::cin >> guess;

        if (guess.length() <= 0) // check that they inputted something
        {
            std::cout << "must input a letter or guess the whole phrase\n\n";
            continue;
        }

        if (guess.length() == 1) // if they inputted a single letter
        {
            if (!isalpha(guess[0]))
            {
                std::cout << "must input a letter\n\n";
                continue;
            }

            for (int i = 0; i < letterGuesses.length() - 1; i++)
            {
                if (guess[0] == letterGuesses[i]) // check that they hadnt already guessed the letter
                {
                    std::cout << "you already guessed that lettter\n\n";
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
                    std::cout << "letters only\n\n";
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
