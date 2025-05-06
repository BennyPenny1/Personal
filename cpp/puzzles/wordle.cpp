#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <string>
#include <unordered_set>
#include <fstream>

bool load_set(std::unordered_set<std::string>& wordSet);
std::string select_word(std::unordered_set<std::string>& wordSet);
std::string generate_output(const std::vector<std::string> guesses, const std::string secretWord);
bool start_game();
std::string get_guess(const std::vector<std::string> guesses, const std::string guessOutput, std::unordered_set<std::string> wordSet);

int main()
{
    bool wantToPlay = start_game();

    if (!wantToPlay) // they dont want to play
    {
        std::cout << "\nfine i didnt want to play either\n\n";
        return 1;
    }
    // else start game

    std::unordered_set<std::string> wordSet;
    bool loaded = load_set(wordSet);
    if (!loaded)
    {
        std::cerr << "set was unsuccesfully loaded\n";
        return 2;
    }
    std::string secretWord = select_word(wordSet); // get the random word
    std::cout << secretWord << '\n';
    std::vector<std::string> guesses; // list of the guesses
    int strikes = 0;
    bool playerWon = false;
    std::string guessOutput;

    std::cout << "Rules:\n1. if there is an X below the letter, that letter isnt in the word\n"
    "2. if there is a Y (Yellow), that letter is in the word, but not in that spot\n"
    "3. if there is a G (Green), that letter is in the right place\n\n";

    while (strikes < 6 && !playerWon) // if player wins or gets to many strikes, game ends
    {
        guessOutput = generate_output(guesses, secretWord);
        std::cout << guessOutput;
        /*std::string guess = get_guess(guesses, guessOutput, wordSet);

        bool guessWasNotRight = false;
        for (int i = 0; i < secretWord.length(); i++) // check if they got it right
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
            std::cout << '\n';
        }
        else // guess was right
        {
            playerWon = true;
        }

    }
    if (playerWon)
    {
        std::cout << "\nCongratulations!! You Won!\nthe word was " << secretWord << '\n';
    }
    else // if person got too many strikes
    {
        std::cout << "\nSowwy, looks like you lost :(\nthe word was " << secretWord << '\n';
    */}

}
bool load_set(std::unordered_set<std::string>& wordSet)
{
    std::ifstream file("word_list.txt");

    if (!file)
    {
        std::cerr << "failed to open file\n";
        return false;
    }

    std::string buffer;

    while(std::getline(file, buffer))
    {
        wordSet.insert(buffer);
    }

    file.close();
    return true;
}

std::string select_word(std::unordered_set<std::string>& wordSet)
{
    std::vector<std::string> wordVec(wordSet.begin(), wordSet.end()); // convert unordered set to vector

    std::srand(std::time(nullptr)); // seed random generator
    int randomIndex = rand() % (wordVec.size()); // get the random index
    return wordVec[randomIndex];
}

std::string generate_output(const std::vector<std::string> guesses, const std::string secretWord)
{
    std::string guessOutput;
    std::cout << "output called\n";

    for (int i = 0; i < guesses.size(); i++)
    {
        std::cout << "shouldnt be called";
        std::string hintOutput;
        for (int j = 0; j < guesses[i].length(); i++)
        {
            guessOutput.push_back(guesses[i][j]);
            guessOutput.push_back(' ');

            if (guesses[i][j] == secretWord[j]) // if letter is in the right spot
            {
                hintOutput.push_back('G');
                hintOutput.push_back(' ');
                continue;
            }
            bool letterInWord = false;
            for (int k = 0; k < guesses[i].length(); k++)
            {
                if (guesses[i][j] == secretWord[k]) // check if letter is in the word at all
                {
                    hintOutput.push_back('Y');
                    hintOutput.push_back(' ');
                    letterInWord = true;
                }
                if (letterInWord)
                {
                    break;
                }
            }
            if (letterInWord) // leter isnt in word
            {
                continue;
            }
            hintOutput.push_back('X');
            hintOutput.push_back(' ');
        }
        guessOutput.back() = '\n'; // lst space = \n
        hintOutput.pop_back(); // get rid of last space
        hintOutput += "\n\n";
        guessOutput += hintOutput; // guess \n hint \n\n
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

std::string get_guess(const std::vector<std::string> guesses, const std::string guessOutput, std::unordered_set<std::string> wordSet)
{
    std::string guess;
    bool invalidInput = false;

    while (true)
    {

        std::cout << "\n\n" << guessOutput << '\n';
        std::getline(std::cin, guess);

        if (guess.length() != guess.length()) // check that they inputted 6 letter word
        {
            std::cout << "\n\ninput must be a 6 letter word\n\n";
            continue;
        }
        bool invalidInput = false;
        for (int i = 0; i < guess.length(); i++)
        {
            if (!isalpha(guess[i])) // check that they only inputted letters
            {
                std::cout << "\n\ninput must be a 6 LETTER word\n\n";
                invalidInput = true;
                break;
            }
            else
            {
                guess[i] = tolower(guess[i]);
            }
        }
        if (invalidInput)
        {
            continue;
        }

        invalidInput = false;
        for (int i = 0; i < guesses.size(); i++) // check that they havent guessed the word already
        {
            for (int j = 0; j < guesses[i].length(); j++)
            {
                if (guesses[i][j] != guess[j])
                {
                    break;
                }
            }
            if (invalidInput) // if they have guessed the word already
            {
                break;
            }
        }
        if (invalidInput)
        {
            std::cout << "\n\nyou already guessed that word\n\n";
            continue;
        }
        if (!wordSet.count(guess)) // query the word list
        {
            std::cout << "\n\nThat guess is not in the accepted word list\n\n";
            continue;
        }
        return guess;
    }
}

