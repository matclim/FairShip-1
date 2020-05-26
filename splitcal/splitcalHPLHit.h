#ifndef SPLITCALHPLHIT_H
#define SPLITCALHPLHIT_H 1

#include <vector>
#include "ShipHit.h"
#include "splitcalPoint.h"
#include "TObject.h"
#include "TVector3.h"


class splitcalHPLHit : public ShipHit
{
  public:

    /** Default constructor **/
    splitcalHPLHit();

    /** Constructor with arguments
     *@param detID    Detector ID
     *@param digi      digitized/measured TDC 
     *@param flag      True/False, false if there is another hit with smaller tdc 
     **/
    splitcalHPLHit(Int_t detID, Float_t tdc);
    splitcalHPLHit(splitcalPoint* p, Int_t evtnum, Double_t t0);
    /** Destructor **/
    virtual ~splitcalHPLHit();
    /** Copy constructor **/
    splitcalHPLHit(const splitcalHPLHit& point);
    splitcalHPLHit operator=(const splitcalHPLHit& point);
    /** Output to screen **/
    virtual void Print() const;
    Float_t GetTDC() const {return fdigi;}
    void setInvalid() {flag = false;}
    bool isValid() const {return flag;}
    /** Accessors **/
    Double_t GetX(){return recoX;};
    Double_t GetY(){return recoY;};
    Double_t GetZ(){return recoZ;};
    Int_t GetLayer(){return Layer;};
    /** Modifiers **/
    void SetDetectorID(Int_t detid){fDetID=detid;};
    void SetStripSizes(Float_t nssX,Float_t nssY){stripsizeX=nssX;stripsizeY=nssY;};
    void SetTruths(Float_t X,Float_t Y,Float_t Z,Float_t T,Float_t E,Int_t detid){fX=X;fY=Y;fZ=Z;fTime=T;fELoss=E;fDetID=detid;};
    void SetLayerNb(Int_t lay){Layer=lay;};
    /**Reconstruction functions**/
    void GenerateStripPositions();
    void Reconstruct();
    Bool_t AddPoint(splitcalPoint *p);
    void DetermineLayerNb();
  private:

    Float_t flag;
    std::vector<Float_t> *XGrid; //maybe move to static arrays
    std::vector<Float_t> *YGrid;
    Float_t fX,fY,fZ,recoX,recoY,recoZ,fTime,fELoss;
    Int_t recoTime,eventnum,fDetID;
    Float_t stripsizeX=0.000002174;
    Float_t stripsizeY=0.000002174;
    Double_t fdigi; 
    Int_t Layer;

    ClassDef(splitcalHPLHit,1);
    
};

#endif
