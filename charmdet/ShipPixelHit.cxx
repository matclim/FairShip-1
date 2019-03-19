#include "ShipPixelHit.h"
#include <iostream>

ShipPixelHit::ShipPixelHit(Int_t detID, Float_t digi) : ShipHit(detID, digi) {}

ShipPixelHit::Setpixelx(0, 0.0225)
ShipPixelHit::Setpixelx(167, 0.0225)
ShipPixelHit::Setpixelx(168, 0.0225)
ShipPixelHit::Setpixelx(335, 0.0225)

for(int i=1;i<=335;i++){
if(i!=167 || i!=168){
ShipPixelHit::Setpixelx(i,0.0125);}
}




ClassImp(ShipPixelHit)
