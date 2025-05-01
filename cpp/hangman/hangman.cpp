#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cctype>


std::string select_word();
std::string generate_output(std::string letterGuesses, std::string secretWord);

int main()
{
    std::string wantToPlay;
    while (true) // get input
    {
        std::cout << "Start Game? (Y/N) ";
        std::cin >> wantToPlay;
        for (int i = 0; i < wantToPlay.size(); i++) // convert input to lower
        {
            wantToPlay[i] = std::tolower(wantToPlay[i]);
        }

        if (wantToPlay == "n" || wantToPlay == "no")
        {
            break;
        }
        else if (wantToPlay == "y" || wantToPlay == "yes")
        {
            break;
        }
        else
        {
            std::cout << '\n' << "invalid input, try again" << '\n';
        }
    }

    if (wantToPlay[0] == 'n') // they dont want to play
    {
        return 1;
    }
    else // they do want to play
    {
        std::string secretWord = select_word(); // get the random word
        std::string letterGuesses;
        int strikes = 0;
        bool playerWon = false;
        std::string guessOutput;
        std::string letterGuess;

        while (strikes < 6 && !playerWon) // if player wins or gets to mant strikes, game ends
        {
            guessOutput = generate_output(letterGuesses, secretWord);
            std::cout << "strikes: " << strikes << "   " << guessOutput << '\n' << "guess? ";
            std::cin >> letterGuess;
            if (!isalpha(letterGuess[0]))
            {
                std::cout << "must input a letter\n";
                continue;
            }
            if (letterGuess.length() == 1) // if they inputted a single letter
            {
                bool alreadyGuessed = false;

                for (int i = 0; i < letterGuesses.length() - 1; i++) // check if they already guessed the letter
                {
                    if (letterGuess[0] == letterGuesses[i])
                    {
                        alreadyGuessed = true;
                        std::cout << "you already guessed that lettter\n";
                        break;
                    }
                }
                if (!alreadyGuessed) // if they inputted a new letter
                {
                    bool guessIsRight = false;
                    letterGuesses.push_back(letterGuess[0]); // add letter to their guesses
                    for (int i = 0; i < secretWord.length(); i++) // check if the guess is right
                    {
                        if (secretWord[i] == ' ')
                        {
                            continue;
                        }
                        else if (letterGuess[0] == secretWord[i])
                        {
                            guessIsRight = true;
                            break;
                        }
                    }
                    if (!guessIsRight)
                    {
                        strikes++;
                    }
                    bool letterWasGuessed = false;
                    bool allLettersGuessed = true;
                    for (int i = 0; i < secretWord.length(); i++) // check if they have all of the letters
                    {
                        if (secretWord[i] == ' ')
                        {
                            continue;
                        }
                        for (int j = 0; j < letterGuesses.length(); j++)
                        {
                            if (letterGuesses[j] == secretWord[i])
                            {
                                letterWasGuessed = true;
                                break;
                            }
                        }
                        if (letterWasGuessed)
                        {
                            letterWasGuessed = false;
                        }
                        else // if there is a letter still unguessed
                        {
                            allLettersGuessed = false;
                            break;
                        }
                    }
                    if (allLettersGuessed)
                    {
                        playerWon = true;
                    }
                }
            }
            else
            {
                bool guessed = false;
                for (int i = 0; i < secretWord.length(); i++)
                {
                    if (secretWord[i] == ' ')
                    {
                        continue;
                    }
                    for (int j = 0; j < letterGuesses.length(); j++)
                    {
                        if (letterGuesses[j] == secretWord[i])
                        {
                            guessed = true;
                            break;
                        }
                    }
                    if (!guessed)
                    {
                        strikes++;
                        break;
                    }
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

std::string generate_output(std::string letterGuesses, std::string secretWord)
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

