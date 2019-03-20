#ifndef PIXELHIT_H
#define PIXELHIT_H

#include "ShipHit.h"

class ShipPixelHit : public ShipHit {
public:
   ShipPixelHit() : ShipHit() {}
   ~ShipPixelHit() = default;
   ShipPixelHit(Int_t detID, Float_t digi);

Int_t Getpixelx(Int_t xcoor){
return pixelx[xcoor]i;
}

Int_t Getpixely(Int_t ycoor){
return pixely[ycoor]i;
}

void Setpixelx(Int_t pixelmodule,Int_t xcoor, Float_t dim){
if(xcoor <= sizeof(pixelx)/sizeof(*pixelx)){
pixelx[xcoor]=dim;}
}

void Setpixely(Int_t pixelmodule,Int_t ycoor, Float_t dim){
if(ycoor <= sizeof(pixely)/sizeof(*pixely)){
pixely[ycoor]=dim;}
}

private:

ShipPixelHit(const ShipPixelHit& other); 
ShipPixelHit operator=(const ShipPixelHit& other); 

Float_t pixelx[336];
Float_t pixely[160];
Int_t pixelmod[12];

ClassDef(ShipPixelHit, 1)

};

#endif
