#include <TMath.h>
#include <TFile.h>
#include <fstream>
#include <sstream>
#include <TH1D.h>
#include <iostream>

int main()
{
  TFile* f1 = new TFile("frontWeek8_200.root");

  std::ofstream outputFile;
  outputFile.open("myOutput.txt");
  
  std::stringstream histogramString;
  
  int numBars = 24;
  int numTotalPts = 0;
  
  for ( int i = 1 ; i < numBars+1 ; i++ ){
    
    histogramString << "hRealESpec" << i;
    std::cout << histogramString.str() << std::endl;
    TH1D* EnergySpectrum = (TH1D*)f1->Get(histogramString.str().c_str());
    histogramString.str(std::string());
    int numPts = EnergySpectrum->Integral(141,180);
    numTotalPts+=numPts;
    outputFile << i << " " << numPts << std::endl;
    
    }
  outputFile << 25 << " " << numTotalPts << std::endl;
  outputFile.close();
}
