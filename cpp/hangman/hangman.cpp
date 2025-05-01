#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cctype>

int main()
{
    std::string wantToPlay;
    while (true) // get input
    {
        std::cout << "Start Game? (Y/N) ";
        std::cin >> wantToPlay;
        for (int i = 0; i < wantToPlay.size(); i++) // conert input to lower
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

    if (wantToPlay[0] == 'n')
    {
        return;
    }
    else
    {
        std::string secretWord = select_word(); // get the word
        std::string letterGuesses;
        int strikes = 0;
        bool playerWon;
        std::string guessOutput;

        while (strikes < 6 && !playerWon)
        {
            guessOutput = generate_output(letterGuesses, secretWord);

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
    int randomIndex = rand() % (words.size() - 1); // get the random index
    return words[randomIndex];
}

std::string generate_output(std::string letterGuesses, std::string secretWord)
{
    std::string guessOutput;
    for (int i = 0; i < secretWord.length() - 1; i++)
    {
        if (secretWord[i] == ' ') // if space
        {
            guessOutput.push_back(' ');
            guessOutput.push_back(' ');
        }
        else // if letter
        {
            bool letterGuessed = false;

            for (int j = 0; j < letterGuesses.length() - 1; j++) // iterate through Player's guesses
            {
                if (secretWord[i] == letterGuesses[j]) // player guessed the letter
                {
                    letterGuessed = true;
                    guessOutput += letterGuesses[j];
                    guessOutput += ' ';
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
}

