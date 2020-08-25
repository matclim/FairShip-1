#include "splitcalHPLCluster.h"
#include "TMath.h"

#include <iostream>
#include <math.h>
#include <functional>   
#include <numeric>     


// -----   constructor from list/vector of splitcalHit   ------------------------------------------
// splitcalHPLCluster::splitcalHPLCluster(boost::python::list& l)
// {
//   std::vector<splitcalHit > v;
//   for(int i=0; i<boost::python::len(l); i++) { 
//     v.push_back(boost::python::extract<splitcalHit >(l[i]));
//   }
//   SetVectorOfHits(v);
// }

// -----   Default constructor   -------------------------------------------
splitcalHPLCluster::splitcalHPLCluster()
{
}
// -----   constructor from splitcalHit   ------------------------------------------
splitcalHPLCluster::splitcalHPLCluster(splitcalHPLHit* h,Bool_t XCl)
{
  _vectorOfHits.push_back(h);
  XC=XCl;
}

Bool_t splitcalHPLCluster::IsinXCluster(splitcalHPLHit *h){
	Bool_t temp=kFALSE;
	if(!_vectorOfHits.size()) temp=kTRUE;

	for(auto itr=_vectorOfHits.begin();itr<_vectorOfHits.end();itr++){
		if((*itr)->IsNeighbourX(h)) temp=kTRUE;
	}
	return temp;
}


Bool_t splitcalHPLCluster::IsinYCluster(splitcalHPLHit *h){
	Bool_t temp=kFALSE;
	for(auto itr=_vectorOfHits.begin();itr<_vectorOfHits.end();itr++){
		if((*itr)->IsNeighbourY(h)) temp=kTRUE;
	}
	return temp;
}


// -----   Destructor   ----------------------------------------------------
splitcalHPLCluster::~splitcalHPLCluster() { }
// -------------------------------------------------------------------------
void splitcalHPLCluster::Print() const
{

  std::cout<< "-I- splitcalHPLCluster: " <<std::endl;
/*  std::cout<< "    (eta,phi,energy) = " 
	   << _eta << " ,  "
	   << _phi << " ,  "
	   << _energy << std::endl;  
  std::cout<< "    start(x,y,z) = " 
	   << _start.X() << " ,  "
	   << _start.Y() << " ,  "
	   << _start.Z() << std::endl;  
  std::cout<< "    end(x,y,z) = " 
	   << _end.X() << " ,  "
	   << _end.Y() << " ,  "
	   << _end.Z() << std::endl;  
   std::cout<< "------- " <<std::endl;*/
}
// -------------------------------------------------------------------------

ClassImp(splitcalHPLCluster)

