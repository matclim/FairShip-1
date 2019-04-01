#include "ShipPixelHit.h"
// #include "PixelDetector.h"
#include "TVector3.h"
#include "TGeoBBox.h"
#include "TGeoNode.h"
#include "TGeoManager.h"
#include "TGeoShape.h"

#include <iostream>
#include <cmath>
#include <>
// -----   Standard constructor   ------------------------------------------
ShipPixelHit::ShipPixelHit(Int_t detID,  Float_t digi)
    : ShipHit(detID, digi) {}

/*
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

  pixelID.partitionID = partitionID; // DAQ partition, from 0-2
  pixelID.frontEndID = frontEndID; // Front end which was read out, from 0-7
  pixelID.moduleID = (8*partitionID + frontEndID)/2 ; // Id of actual DC module, from 0-11
  pixelID.row      = row; // row on front end / module
  pixelID.column   = column; // column on MODULE

  return pixelID;
}

int32_t ShipPixelHit::GetModule()
{
  HitID pixelID;
  pixelID = GetPixel();
  return pixelID.moduleID;
}

int32_t ShipPixelHit::GetDetectorID(){return fDetectorID; }
*/
void ShipPixelHit::EndPoints(TVector3 &pixel, int detID, std::unordered_map<int, TVector3> &positionMap) {

  int max_detID = 10000000*2 + 1000000*7 + 1000*336 + 80 ;
  if (detID%1000000 == 0) {
    return;
  }
  if (detID > max_detID) {
    std::cout << "PixelDetector::PixelDecode, detectorID out of range "<<detID<<std::endl;
    return;
  }
  TVector3 pixel_pos = positionMap[detID];
  pixel.SetX(pixel_pos.X());
  pixel.SetY(pixel_pos.Y());
  pixel.SetZ(pixel_pos.Z());
}

PixelHit::PixelHit(){
    hasXYZ = false; hasMCR = false; hasDetectorID = false;
};

PixelHit::~PixelHit(){
};

void PixelHit::SetXYZ(float x, float y, float z) {
    fX = x; fX = y; fX = z;
    hasXYZ = true;
};

void PixelHit::SetMCR(unsigned mod, unsigned col, unsigned row) {
    fRow = row; fMod = mod; fCol = col;
    hasMCR = true;
};

void PixelHit::SetDetectorID(long detID) {
    fDetectorID = detID;
    hasDetectorID = true;
};

void PixelHit::Convert() {
    if (!hasXYZ && !hasMCR && !hasDetectorID) exit(0);
    if (hasMCR) {
        fX = pixelX[fCol];
        fY = pixelY[fRow];
        fZ = pixelY[fMod];
        hasXYZ = true;
    }

    if (hasDetectorID) {
        fCol = fDetectorID%1000 - 1;
        fRow = (fDetectorID/1000)%1000 - 1;
        int fe = (fDetectorID/1000000)%10 + 8*(fDetectorID/10000000);
        fMod = fe/2;
        if ((fe%2)==1) fCol += 80;
        hasMCR = true;
    }

    if (hasMCR) {
        fX = pixelX[fCol];
        fY = pixelY[fRow];
        fZ = pixelY[fMod];
        hasXYZ = true;
    }
}

float PixelHit::GetX() {
    if (!hasXYZ) Convert();
    return fX;
}

float PixelHit::GetY() {
    if (!hasXYZ) Convert();
    return fY;
}

float PixelHit::GetZ() {
    if (!hasXYZ) Convert();
    return fZ;
}

int PixelHit::GetMod() {
    if (!hasMCR) Convert();
    return fMod;
}

int PixelHit::GetRow() {
    if (!hasMCR) Convert();
    return fRow;
}

int PixelHit::GetCol() {
    if (!hasMCR) Convert();
    return fCol;
}

void testit() {
    std::cout << "pixelX contains:" << std::endl;
    for (unsigned i=0; i<ncol; i++)
        std::cout << ' ' << PixelHit::pixelX[i];
    std::cout << std::endl << std::endl;
//
//    std::cout << "pixelY contains:" << std::endl;
//        for (unsigned i=0; i<nrow; i++)
//                std::cout << ' ' << PixelHit::pixelY[i];
//                    std::cout << std::endl << std::endl;
//                    //
//                        std::cout << "pixelZ contains:" << std::endl;
//                            for (unsigned i=0; i<nmod; i++)
//                                    std::cout << ' ' << PixelHit::pixelZ[i];
//                                        std::cout << std::endl << std::endl;
//                                        }
//


// -----   Destructor   ----------------------------------------------------
// ShipPixelHit::~ShipPixelHit() = default;
// -------------------------------------------------------------------------


// -----   Public method Print   -------------------------------------------
void ShipPixelHit::Print()
{
  std::cout << "-I- PixelHit: Pixel hit " << " in module " << GetModule() << std::endl;
  std::cout << "  ToT " << fdigi*25 << " ns" << std::endl; //Time over threshold in nanoseconds
}
// -------------------------------------------------------------------------


 ClassImp(ShipPixelHit)
