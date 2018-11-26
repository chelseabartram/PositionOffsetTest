#include <fstream>
#include <iostream>
#include <cmath>

int main(){

  std::ifstream numEventsPerBar;
  numEventsPerBar.open("myOutput8.txt");

  int APEXBarArray[25];
  APEXBarArray[19] = 0;
  APEXBarArray[20] = 1;
  APEXBarArray[21] = 2;
  APEXBarArray[22] = 3;
  APEXBarArray[23] = 4;
  APEXBarArray[24] = 5;
  APEXBarArray[1] = 6;
  APEXBarArray[2] = 7;
  APEXBarArray[3] = 8;
  APEXBarArray[9] = 9;
  APEXBarArray[10] = 10;
  APEXBarArray[11] = 11;
  APEXBarArray[12] = 12;
  APEXBarArray[13] = 13;
  APEXBarArray[14] = 14;
  APEXBarArray[15] = 15;
  APEXBarArray[16] = 16;
  APEXBarArray[4] = 17;
  APEXBarArray[5] = 18;
  APEXBarArray[6] = 19;
  APEXBarArray[7] = 20;
  APEXBarArray[8] = 21;
  APEXBarArray[17] = 22;
  APEXBarArray[18] = 23;
  
  int totalSumX = 0;
  int totalSumY = 0;
  int bar, numEvents;
  double totalForAllBars;
  double APEXRadius = 24.5;
  
  while ( !numEventsPerBar.eof() ){

    numEventsPerBar >> bar >> numEvents;
    if ( bar == 25 ){
      totalForAllBars = numEvents;
    }
    else{
      double angleFromXaxis = (((APEXBarArray[bar]*15+7.5)))*M_PI/180.0;
      double xposition = APEXRadius*cos(angleFromXaxis);
      double yposition = APEXRadius*sin(angleFromXaxis);

      totalSumX+=numEvents*xposition;
      totalSumY+=numEvents*yposition;
    }
  }

  double evaluatedXPos = totalSumX/totalForAllBars;
  double evaluatedYPos = totalSumY/totalForAllBars;
  std::cout << "X: " << evaluatedXPos << std::endl;
  std::cout << "Y: " << evaluatedYPos << std::endl;
  numEventsPerBar.close();
}
