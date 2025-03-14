#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "function.h"

int main()
{
	int count = 0;
	double Mean = 0.0;
    std::ifstream input("data.txt");
    std::ofstream output("result.txt");
    
    if (!input) 
    {
        std::cerr << "Errore nell'apertura del file di input" << std::endl;
        return 1;
    }
    if (!output) 
    {
        std::cerr << "Errore nell'apertura del file di output" << std::endl;
        return 1;
    }
    output<<"#\tN Mean\n";

    std::string line;
    double n;
	while (input >> n)
	{
        count++;
        double N = map(n);
        Mean = (Mean * (count-1) + N)/(count);
        output<<count<<"\t"<<std::setprecision(16)<<std::scientific<<Mean<<std::endl;
    }

    return 0;
}
