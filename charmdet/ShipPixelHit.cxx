include "ShipPixelHit.h"
#include <iostream>
using namespace std;
ShipPixelHit::ShipPixelHit(Int_t detID, Float_t digi) : ShipHit(detID, digi) {}



ShipPixelHit::SetPixelMapping(){
for(j=0;j<12;j++){
pixelx[j][0]=0.0225;
pixelx[[j]167] = 0.0225;
pixelx[j][168]= 2pixmod,335, 4.285;
pixelx[j][335]= 4.285;

for(int i=1;i<168;i++){
pixelx[j][i]=0.045+(i-1)*0.025+0.0125;
pixelx[j][i+168]=2.1875+(i-1)*0.025+0.0125;

for(int i=1;i<161;i++){
pixely[j][i](i-1)*0.005+0.0025;
}


}
}
}

ShipPixelHit::SetPixelIDs(){


  int map_index=0;
  for (int partID=0; partID<3; partID++) {
    for (int moduleID=0;moduleID<8; moduleID++ ) {
      for (int row=1; row<337; row++) {
        for (int column=1; column<81; column++) {
          pixelID[row][column] = 10000000*partID + 1000000*moduleID + 1000*row + column;
        }
      }
    }
  }



}



}


ClassImp(ShipPixelHit)
