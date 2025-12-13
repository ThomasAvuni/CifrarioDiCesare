#include <iostream>
#include <vector>
#include<string>

int main(int argc, char* argv[])
{
    std::vector<std::string> alfabeto = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "Z"};
    std::vector<std::string> nome = {"C", "I", "A", "O"};
    const int key = 3;
    std::vector<std::string> result;

    for (int i = 0; i < nome.size(); i++)
    {
        for (int j = 0; j < alfabeto.size(); j++)
        {
            if (nome[i] == alfabeto[j])
            {
                int newIndex = (j + key) % alfabeto.size();
                result.push_back(alfabeto[newIndex]);
            }
        }
    }
    
    std::cout<<key<< "\n";
    for (std::string s : result)
        std::cout<<s<<", ";
    
    return 0;
}
