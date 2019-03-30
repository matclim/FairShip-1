#ifndef PIXELHIT_H
#define PIXELHIT_H

#include "ShipHit.h"
#include "ShipOnlineDataFormat.h"
#include "unordered_map"

struct HitID {
   int32_t partitionID;
   int32_t frontEndID;
   int32_t moduleID;
   int32_t row;
   int32_t column;
};


class ShipPixelHit : public ShipHit {
public:
   /** Default constructor **/
   ShipPixelHit() = default;
   ~ShipPixelHit() = default;

   ShipPixelHit(Int_t detID, Float_t fdigi);
   HitID GetPixel();
   int32_t GetDetectorID();
   int32_t GetModule();
   void EndPoints(TVector3 &pixel, int detID, std::unordered_map<int, TVector3> &positionMap);
   void Print();
   int32_t GetTimeOverThreshold() const {return fdigi*25 ; }

   float GetX();
   float GetY();
   float GetZ();
   int GetRow();
   int GetCol();
   int GetMod();
   void SetXYZ(float x, float y, float z);
   void SetDetectorID(long detID);
   void SetMCR(unsigned mod, unsigned col, unsigned row);
   static std::array<float, ncol> pixelX;
   static std::array<float, nrow> pixelY;
   static std::array<float, nmod> pixelZ;
   void Convert();

	

private:
   /** Copy constructor **/
   ShipPixelHit(const ShipPixelHit &other);
   ShipPixelHit operator=(const ShipPixelHit &other);

   int32_t detID;
   uint16_t tot;


   const unsigned ncol = 160;
   const unsigned nrow = 336;
   const unsigned nmod = 12;
   const float shortpix = 250.e-4;
   const float longpix = 450.e-4;
   const float rowpitch = 50.e-4;
   float fX;
   float fY;
   float fZ;
   unsigned fRow;
   unsigned fCol;
   unsigned fMod;
   long fDetectorID;
   bool hasXYZ;
   bool hasMCR;
   bool hasDetectorID;
   std::array<float, ncol> PixelHit::pixelX;
   std::array<float, nrow> PixelHit::pixelY;
   std::array<float, nmod> PixelHit::pixelZ;

   ClassDef(ShipPixelHit, 1);
};

#endif
