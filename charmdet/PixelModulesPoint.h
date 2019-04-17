#ifndef PIXELMODULESPOINT_H
#define PIXELMODULESPOINT_H 1


#include "FairMCPoint.h"

#include "TObject.h"
#include "TVector3.h"
#include <vector>
using std::vector;

class PixelModulesPoint:public FairMCPoint
{

  public:

    /** Default constructor **/
    PixelModulesPoint();


    /** Constructor with arguments
     *@param trackID  Index of MCTrack
     *@param detID    Detector ID
     *@param pos      Ccoordinates at entrance to active volume [cm]
     *@param mom      Momentum of track at entrance [GeV]
     *@param tof      Time since event start [ns]
     *@param length   Track length since creation [cm]
     *@param eLoss    Energy deposit [GeV]
     **/
    

    PixelModulesPoint(Int_t trackID, Int_t detID, TVector3 pos, TVector3 mom,
                     Double_t tof, Double_t length, Double_t eLoss, Int_t pdgcode, std::vector<Double_t> stepEdep);


    /** Destructor **/
    virtual ~PixelModulesPoint();

    /** Output to screen **/
    virtual void Print(const Option_t* opt) const;
    Int_t PdgCode() const {return fPdgCode;}


  private:
    
    Int_t fPdgCode;
    
    /** Copy constructor **/
    
    PixelModulesPoint(const PixelModulesPoint& point);
    PixelModulesPoint operator=(const PixelModulesPoint& point);
    std::vector<Double_t> stepEdep;
    ClassDef(PixelModulesPoint,1)

};

#endif
