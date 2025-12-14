#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

static std::vector<std::string> alfabeto = {"A", "B", "C", "D", "E", "F", "G", "H",
    "I", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V",
    "Z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
static const int key = 3;

std::string Cifra(std::string stringa)
{
    std::vector<std::string> result;
    std::transform(stringa.begin(), stringa.end(), stringa.begin(), toupper);
    
    for (int i = 0; i < stringa.length(); i++)
    {
        for (int j = 0; j < alfabeto.size(); j++)
        {
            if (stringa.c_str()[i] == *alfabeto[j].c_str())
            {
                int newIndex = (j + key) % alfabeto.size();
                result.push_back(alfabeto[newIndex]);
            }
        }
    }

    std:: string s;
    for (int i = 0; i < result.size(); i++)
    {
        s.append(result[i]);
    }
    return s;
}

std::string Decripta(std::string stringa)
{
    std::vector<std::string> result;
    std::transform(stringa.begin(), stringa.end(), stringa.begin(), toupper);
    
    for (int i = 0; i < stringa.length(); i++)
    {
        for (int j = 0; j < alfabeto.size(); j++)
        {
            if (stringa.c_str()[i] == *alfabeto[j].c_str())
            {
                int newIndex = (j - key) % alfabeto.size();
                result.push_back(alfabeto[newIndex]);
            }
        }
    }

    std:: string s;
    for (int i = 0; i < result.size(); i++)
    {
        s.append(result[i]);
    }
    return s;
}

int main(int argc, char* argv[])
{
    std::cout<<"|Benvenuto nel Cifrario di Cesare|\n";
    std::cout<<"|Vuoi cifrare (1) oppure decriptare (2) qualcosa?|\n";
    int r = 0;
    std::cin>>r;
    std::cin.ignore(1000, '\n');
    switch (r)
    {
    case 1:
        {
            std::cout<<"|Inserisci la frase che vuoi Cifrare|\n";
            std::string s;
            std::getline(std::cin, s);
            std::cout<<Cifra(s);
        }
        break;
    case 2:
        {
            std::cout<<"|Inserisci la frase che vuoi Decriptare|\n";
            std::string s;
            std::getline(std::cin, s);
            std::cout<<Decripta(s);
        }
        break;
    default:
        std::cout<<"Operazione non valida";
        break;
    }
    return 0;
}
