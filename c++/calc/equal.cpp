#include <vector>
#include <iostream>

int main()
{
    std::string equation = "1.5555/2+";
    if (equation[equation.size() - 1] == '+'|| equation[equation.size() - 1] == '-' || equation[equation.size() - 1] == '*' || equation[equation.size() - 1] == '/')
    {
        equation += answer
    }
    else
    {
        std::string chunk;
        std::vector<double> numbers;
        std::vector<char> operators;
        for (int i = 0; i < equation.size(); i++)
        {
            if (equation[i] == '-')
            {
                if (chunk.size() == 0)
                {
                    chunk += equation[i];
                }
                else
                {
                    numbers.push_back(std::stod(chunk));
                    operators.push_back('-');
                    chunk.clear();
                }
            }
            else if (equation[i] == '+'|| equation[i] == '*' || equation[i] == '/')
            {
                numbers.push_back(std::stod(chunk));
                operators.push_back(equation[i]);
                /*std::cout << equation[i] << "\n";
                std::cout << chunk << "\n";*/
                chunk.clear();
            }
            else
            {
                chunk += equation[i];
            }
        }
        numbers.push_back(std::stod(chunk));

        /*std::cout << "numbers list: ";
        for (int i = 0; i < numbers.size(); i++){
            std::cout << i << ": " << numbers[i] << ", ";
        }
        std::cout << "\n";*/

        int it_adjst = 0; // iterator adjustment: when replacing numbers, throughs off iterator
        for (int i = 0; i < operators.size(); i++)
        {
            if (operators[i] == '/')
            {
                std::cout << numbers[i] << operators[i] << numbers[i+1] << "= ";
                double temp_num = numbers[i - it_adjst] / numbers[i+1 - it_adjst];
                std::cout << temp_num <<"\n";
                numbers.erase(numbers.begin() + i - it_adjst);
                numbers.erase(numbers.begin() + i - it_adjst);
                numbers.insert(numbers.begin() + i - it_adjst, temp_num);
                it_adjst++;
            }
            else if (operators[i] == '*')
            {
                std::cout << numbers[i] << operators[i] << numbers[i+1] << "= ";
                double temp_num = numbers[i - it_adjst] * numbers[i+1 - it_adjst];
                std::cout << temp_num <<"\n";
                numbers.erase(numbers.begin() + i - it_adjst);
                numbers.erase(numbers.begin() + i - it_adjst);
                numbers.insert(numbers.begin() + i - it_adjst, temp_num);
                it_adjst++;
            }
        }

        /*std::cout << "numbers after mult/div: ";
        for (int i = 0; i < numbers.size(); i++){
            std::cout << i << ": " << numbers[i] << ", ";
        }
        std::cout << "\n";*/

        for (int i = 0; i < operators.size(); i++)
        {
            if (operators[i] == '+')
            {
                std::cout << numbers[0] << operators[i] << numbers[1] << "\n";
                double temp_num = numbers[0] + numbers[1];
                numbers.erase(numbers.begin());
                numbers.erase(numbers.begin());
                numbers.insert(numbers.begin(), temp_num);
            }
            else if (operators[i] == '-')
            {
                std::cout << numbers[0] << operators[i] << numbers[1] << "\n";
                double temp_num = numbers[0] - numbers[1];
                numbers.erase(numbers.begin());
                numbers.erase(numbers.begin());
                numbers.insert(numbers.begin(), temp_num);
            }
        }
        std::cout << "answer: " << numbers[0] << "\n";
    }
}
