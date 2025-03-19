#include <iostream>
#include <fstream>
#include <iomanip>
#include "function.h"

int main()
{
	int count = 0;
	double Sum = 0.0;
	double Mean = 0.0;
	double n;
	
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

	while (input >> n)
	{
        count++;
        double N = map(n);
        Sum += N;
        Mean = Sum/count;
        output<<count<<"\t"<<std::setprecision(16)<<std::scientific<<Mean<<std::endl;
    }
    
    input.close();
    output.close();

    return 0;
}
