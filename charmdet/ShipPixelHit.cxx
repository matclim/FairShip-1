#include "ShipPixelHit.h"
#include <iostream>

ShipPixelHit::ShipPixelHit(Int_t detID, Float_t digi) : ShipHit(detID, digi) {}

ShipPixelHit::Setpixelx(0,0.0225)
ShipPixelHit::Setpixelx(167, 0.0225)
ShipPixelHit::Setpixelx(168, 2.1875)
ShipPixelHit::Setpixelx(335, 4.285)
for(pixmod=0;pixmod <12;pixmod++){
for(int i=1;i<168;i++){
ShipPixelHit::Setpixelx(pixmod,i,0.045+(i-1)*0.025+0.0125);}


for(int i=1;i<168;i++){
ShipPixelHit::Setpixelx(pixmod,i,2.1875+(i-1)*0.025+0.0125);}

for(int i=1;i<161;i++){
ShipPixelHit::Setpixely(pixmod.i,(i-1)*0.005+0.0025;)
}
}


ClassImp(ShipPixelHit)
