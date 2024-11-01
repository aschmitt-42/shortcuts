#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>  // Pour std::transform
#include <cctype>
#include <filesystem> // Pour std::filesystem

namespace fs = std::filesystem;

int main(int argc, char **argv)
{
    if (argc == 1)
        return 1;
    
    // Check and create directories if they do not exist

    if (!fs::exists("src")) {
        fs::create_directory("src");
    }
    if (!fs::exists("inc")) {
        fs::create_directory("inc");
    }

    for (int i = 1; i < argc; i++)
    {
        std::string name = argv[i];
        std::string nameCPP = "src/" + name + ".cpp";
        std::string nameHPP = "inc/" + name + ".hpp";
        std::string Define = name ;
        std::string IncName = name + ".hpp";
        
        if (fs::exists(nameCPP))
            continue;
        if (fs::exists(nameHPP))
            continue;

        std::transform(Define.begin(), Define.end(), Define.begin(), 
                   [](unsigned char c) { return std::toupper(c); });
        Define += "_HPP";
        
        std::ofstream fichierHPP(nameHPP);

        if (fichierHPP.is_open()) 
        {
            fichierHPP << "#ifndef " << Define << std::endl
            << "# define " << Define << std::endl << std::endl
            << "# include <iostream>" << std::endl << std::endl
            << "class " << name << std::endl
            << "{ " << std::endl << "    private :" << std::endl << std::endl
            << "    public :\n"
            << "        " << name << "();\n"
            << "        ~" << name << "();\n"
            << "        " << name << "(const " << name << " &other);\n"
            << "        " << name << "& operator=(const " << name << " &other);" << std::endl
            << "};\n\n"
            << "// std::ostream& operator<<(std::ostream& os, const " << name << "& other);\n" << std::endl;
            fichierHPP << "#endif " << std::endl;

            fichierHPP.close();
        } 
        else
            std::cout << "Erreur : Impossible d'ouvrir le fichier " << nameHPP << ".\n";

        std::ofstream fichierCPP(nameCPP);
        if (fichierCPP.is_open())
        {
            fichierCPP << "#include \"" << IncName << "\"\n\n"
            << name << "::" << name << "()\n{\n\tstd::cout << \"Default constructor called\" << std::endl;\n}\n"
            << name << "::~" << name << "()\n{\n\tstd::cout << \"Destructor called\" << std::endl;\n}\n"
            << name << "::" << name << "(const " << name << "&other)\n{\n\tstd::cout << \"Recopy constructor called\" << std::endl;\n}\n"
            << name << "& " << name << "::operator=(const " << name << " &other)\n{\n\tstd::cout << \"Assignment operator called\" << std::endl;\n}\n";
            fichierCPP.close();
        }
        else
            std::cout << "Erreur : Impossible d'ouvrir le fichier " << nameCPP << ".\n";
    }

    return 0;
}
