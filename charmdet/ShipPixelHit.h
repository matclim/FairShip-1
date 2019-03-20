#ifndef PIXELHIT_H
#define PIXELHIT_H

#include "ShipHit.h"
#include "ShipOnlineDataFormat.h"

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
   void EndPoints(TVector3 &pixel, int detID);
   void Print();
   int32_t GetTimeOverThreshold() const {return ToT;}
   void SetPixelMapping();
   Float_t GetPixelCoor();
   Text_t Get PixelID;
private:

ShipPixelHit(const ShipPixelHit& other); 
ShipPixelHit operator=(const ShipPixelHit& other); 



   /** Copy constructor **/
   ShipPixelHit(const ShipPixelHit &other);
   ShipPixelHit operator=(const ShipPixelHit &other);

   int32_t detID;
   uint16_t tot;
   Float_t pixelx[12][336];
   Float_t pixely[12][160];
   Float_t pixelID[12][336][160];
   ClassDef(ShipPixelHit, 1);
};

#endif
