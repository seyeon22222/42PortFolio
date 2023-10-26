#include "Harl.hpp"


int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "You don't have inputs" << std::endl;
        return (1);
    }

    Harl   temp;
    
    temp.complain(argv[1]);

    return (0);
}