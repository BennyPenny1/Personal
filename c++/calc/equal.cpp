#include <vector>
#include <iostream>

int main()
{
    std::string equation = "12+3+";
    else if (equation[equation.size() - 1] == '+'|| equation[equation.size() - 1] == '-' || equation[equation.size() - 1] == '*' || equation[equation.size() - 1] == '/')
    {
        return 0;
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
            else if (equation[equation.size() - 1] == '+'|| equation[equation.size() - 1] == '*' || equation[equation.size() - 1] == '/')
            {
                numbers.push_back(std::stod(chunk));
                operators.push_back(equation[i]);
                chunk.clear();
            }
            else
            {
                chunk += equation[i];
            }
        }

        for (int i = 0; i < operators.size(); i++)
        {
            if (operators[i] == '/')
            {
                double temp_num = numbers[i] / numbers[i+1];
                numbers.erase(numbers.begin() + i);
                numbers.erase(numbers.begin() + i);
                numbers.insert(numbers.begin() + i, temp_num);
            }
            else if (operators[i] == '*')
            {
                double temp_num = numbers[i] * numbers[i+1];
                numbers.erase(numbers.begin() + i);
                numbers.erase(numbers.begin() + i);
                numbers.insert(numbers.begin() + i, temp_num);
            }
        }

        for (int i = 0; i < operators.size(); i++)
        {
            if (operators[i] == '+')
            {
                double temp_num = numbers[0] + numbers[1];
                numbers.erase(numbers.begin());
                numbers.erase(numbers.begin());
                numbers.insert(numbers.begin(), temp_num);
            }
            else if (operators[i] == '-')
            {
                double temp_num = numbers[0] - numbers[1];
                numbers.erase(numbers.begin());
                numbers.erase(numbers.begin());
                numbers.insert(numbers.begin(), temp_num);
            }
        }
        cout << temp_num << "\n";
    }
}
