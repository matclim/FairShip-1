#include "ShipPixelHit.h"
// #include "PixelDetector.h"
#include "TVector3.h"
#include "TGeoBBox.h"
#include "TGeoNode.h"
#include "TGeoManager.h"
#include "TGeoShape.h"

#include <iostream>
#include <cmath>

// -----   Standard constructor   ------------------------------------------
ShipPixelHit::ShipPixelHit(Int_t detID,  Float_t digi)
    : ShipHit(detID, digi), detectorID(detID), ToT(digi*25){}


HitID ShipPixelHit::GetPixel()
{
  int32_t partitionID, frontEndID, row, column;
  HitID pixelID;
  partitionID = fDetectorID/10000000;
  frontEndID = (fDetectorID - partitionID*10000000)/1000000;
  row = (fDetectorID - partitionID*10000000 - frontEndID*1000000)/1000;
  column = (fDetectorID - partitionID*10000000 - frontEndID*1000000 - row*1000);
  // stitch together 2 Front ends to one module
  if ((frontEndID%2)==0) column += 80;

  pixelID.partitionID = partitionID;
  pixelID.frontEndID = frontEndID;
  pixelID.moduleID = (partitionID*frontEndID)/2;
  pixelID.row      = row;
  pixelID.column   = column;

  return pixelID;
}

int32_t ShipPixelHit::GetModule()
{
  HitID pixelID;
  pixelID = GetPixel();
  return pixelID.moduleID;
}

int32_t ShipPixelHit::GetDetectorID(){return fDetectorID; }

<<<<<<< HEAD
ShipPixelHit::Setpixelx(0, 0.0225)
ShipPixelHit::Setpixelx(167, 0.0225)
ShipPixelHit::Setpixelx(168, 0.0225)
ShipPixelHit::Setpixelx(335, 0.0225)

for(int i=1;i<=335;i++){
if(i!=167 || i!=168){
ShipPixelHit::Setpixelx(i,0.0125);}
}


>>>>>>> parent of 98930e1... z position included


 ClassImp(ShipPixelHit)
