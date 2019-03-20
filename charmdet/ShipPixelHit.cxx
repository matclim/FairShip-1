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


ClassImp(ShipPixelHit)
