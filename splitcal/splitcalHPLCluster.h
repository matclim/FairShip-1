#ifndef SPLITCALHPLCLUSTER_H
#define SPLITCALHPLCLUSTER_H 1

#include "TObject.h"              //  
#include <iostream>
#include "splitcalHPLHit.h"
#include <vector> 
//#include <boost/python.hpp>

// ROOT headers
/* #include <TLorentzVector.h> */
#include <TVector3.h>

struct HPLregression
{

  double slope;
  double slopeError;
  double intercept;
  double interceptError;

};


class splitcalHPLCluster : public TObject
{
  public:

    /** Constructors **/
    splitcalHPLCluster();
    //splitcalCluster(boost::python::list& l);
    splitcalHPLCluster(splitcalHPLHit* h,Bool_t XCl=kFALSE);
    Int_t GetClusterSize(){return _vectorOfHits.size();};
    /** Destructor **/
    virtual ~splitcalHPLCluster();

    /** Methods **/
    virtual void Print() const;

    //void SetVectorOfHits(std::vector<splitcalHit* >& v) {_vectorOfHits = v;}
    void AddHit(splitcalHPLHit* h) {_vectorOfHits.push_back(h);}
    Bool_t IsinXCluster(splitcalHPLHit* h);
    Bool_t IsinYCluster(splitcalHPLHit* h);
    Bool_t GetIsXClus(){return XC;};
/*  splitcalHPLCluster operator+(const splitcalHPLCluster& h){
	if(_vectorOfYHits.size()==0){
		this->_vectorOfYHits.insert(std::end(_vectorOfYHits),std::begin(h),std::end(h));
	}
	else if(_vectorOfXHits.size()==0)
		this->_vectorOfXHits.insert(std::end(_vectorOfXHits),std::begin(h),std::end(h));
	}
	return *this;
  }  
*/
  private:
    /** Copy constructor **/
    //splitcalCluster(const splitcalCluster& cluster);
    //splitcalCluster operator=(const splitcalCluster& cluster);
    std::vector<splitcalHPLHit*>_vectorOfHits;
    Bool_t XC=kFALSE;
    ClassDef(splitcalHPLCluster,1);
     
};

#endif
