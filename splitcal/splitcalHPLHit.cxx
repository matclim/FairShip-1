#include "splitcalHPLHit.h"
#include "splitcal.h"
#include "splitcalPoint.h"
#include "TVector3.h"
#include "FairRun.h"
#include "FairRunSim.h"
#include "TMath.h"
#include "TRandom1.h"
#include "TRandom3.h"
#include "TGeoManager.h"
#include "TGeoNode.h"
#include "TGeoMatrix.h"
#include "TGeoVolume.h"
#include "TGeoNavigator.h"
#include "TGeoShape.h"
#include "TGeoBBox.h"

#include <iostream>
#include <math.h>
#include <algorithm>
using std::cout;
using std::endl;

//Double_t speedOfLight = TMath::C() *100./1000000000.0 ; // from m/sec to cm/ns
// -----   Default constructor   -------------------------------------------
splitcalHPLHit::splitcalHPLHit()
  : ShipHit()
{
 flag = true;
}
// -----   Standard constructor   ------------------------------------------
splitcalHPLHit::splitcalHPLHit(Int_t detID, Float_t tdc)
  : ShipHit(detID,tdc)
{
 flag = true;
}
// -----   constructor from splitcalPoint   ------------------------------------------
splitcalHPLHit::splitcalHPLHit(splitcalPoint* p, Int_t evtnum, Double_t t0)
  : ShipHit()
{
 
  flag = true;

  double pointX =  p->GetX();
  double pointY =  p->GetY();
  double pointZ =  p->GetZ();
  double pointT =  p->GetTime();
  double pointE =  p->GetEnergyLoss();
  int detID =  p->GetDetectorID();
  eventnum = evtnum;

  if(pointE>0.00001){
  
  //fdigi = t0 + t; 
  fdigi = t0 ;
  // SetDigi(SetTimeRes(fdigi));
  SetTruths(pointX,pointY,pointZ,pointT,pointE,detID);
  DetermineLayerNb();
  XGrid = new std::vector<Float_t>;
  YGrid = new std::vector<Float_t>;
  GenerateStripPositions();
  Reconstruct();}
  else this->~splitcalHPLHit();
}




void splitcalHPLHit::DetermineLayerNb(){
	
	switch(fDetID){
		case 101400000: SetLayerNb(0); break;
		case 100700000: SetLayerNb(1); break;
		case 101100000: SetLayerNb(2); break;
	}

}

void splitcalHPLHit::GenerateStripPositions(){

	for(Int_t i=-2760000;i<2760000;++i){
		YGrid->push_back(i*stripsizeY);	
	}

	for(Int_t i=-1380000;i<1380000;++i){
		XGrid->push_back(i*stripsizeX);
	}
}


void splitcalHPLHit::Reconstruct(){

	Float_t tempX;
	Float_t tempY;

        tempX = XGrid->at(std::lower_bound(XGrid->begin(),XGrid->end(),fX)-XGrid->begin());
        tempY = YGrid->at(std::lower_bound(YGrid->begin(),YGrid->end(),fY)-YGrid->begin());

	recoX=tempX-stripsizeX/2;
	recoY=tempY-stripsizeY/2;
	recoZ=fZ;        
	recoTime=(Int_t)fTime%25+eventnum*40000000;
}

Bool_t splitcalHPLHit::AddPoint(splitcalPoint *p){

	if(TMath::Abs(p->GetX()-recoX)<stripsizeX/2 && TMath::Abs(p->GetY()-recoY)<stripsizeY/2){
		// There are probably other things to do here

		return kTRUE;
	}
	else return kFALSE;


}


// -------------------------------------------------------------------------

// -----   Destructor   ----------------------------------------------------
splitcalHPLHit::~splitcalHPLHit() {delete XGrid; delete YGrid;}
// -------------------------------------------------------------------------


ClassImp(splitcalHPLHit)

