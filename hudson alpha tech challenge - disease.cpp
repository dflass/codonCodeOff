#include <string>
#include <stdio.h>


using namespace std;
class Disease
{
      string diseaseNameA;
      string snpsA;
      char riskAlleleA;
      
      public:
      Disease(string disease, string snps, char riskAllele)
      {
            diseaseNameA = disease;
            snpsA = snps;
            riskAlleleA = riskAllele;
      }
 	     
      bool determineIfAtRisk()
      {
      	if(riskAllele == patientAllele)
      	{
      		return true;
		}
		else
		{
			return false;
		}
	  }
};

int main()
{
    return 0;
}
