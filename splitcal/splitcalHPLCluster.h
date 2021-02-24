#ifndef SPLITCALHPLCLUSTER_H
#define SPLITCALHPLCLUSTER_H 1

#include "TObject.h"              //  

#include "splitcalHit.h"
#include <vector> 
//#include <boost/python.hpp>

// ROOT headers
/* #include <TLorentzVector.h> */
#include <TVector3.h>


class splitcalHPLCluster : public TObject
{
  public:

    /** Constructors **/
    splitcalHPLCluster();
    //splitcalHPLCluster(boost::python::list& l);
    splitcalHPLCluster(splitcalHit* h);

    /** Destructor **/
    virtual ~splitcalHPLCluster();

    /** Methods **/
    virtual void Print() const;

    void SetEtaPhiE(double& eta, double& phi, double& e) {_eta = eta; _phi = phi; _energy = e;}
    void SetEta(double& eta) {_eta = eta;}
    void SetPhi(double& phi) {_phi = phi;}
    void SetEnergy(double& e) {_energy = e;}
    void SetIndex(int i) {_index = i;}
    void SetStartPoint(const double& x, const double& y, const double& z) {_start.SetXYZ(x,y,z); }
    void SetStartPoint(splitcalHit*& h);
    void SetEndPoint(const double& x, const double& y, const double& z) {_end.SetXYZ(x,y,z);}
    void SetEndPoint(splitcalHit*& h);
    void SetVectorOfHits(std::vector<splitcalHit* >& v) {_vectorOfHits = v;}
    void AddHit(splitcalHit* h) {_vectorOfHits.push_back(h);}
    int GetIndex() {return _index;}
    double GetEta() {return _eta;}
    double GetPhi() {return _phi;}
    double GetEnergy() {return _energy;}
    double GetPx() {return _energy*sin(_eta)*cos(_phi);}
    double GetPy() {return _energy*sin(_eta)*sin(_phi);}
    double GetPz() {return _energy*cos(_eta);}
    double GetEx() {return GetPx();}
    double GetEy() {return GetPy();}
    double GetEz() {return GetPz();}
    void Clusterize();
    TVector3 GetStartPoint() {return _start; }
    TVector3 GetEndPoint() {return _end; }
    std::vector<splitcalHit* >& GetVectorOfHits() {return _vectorOfHits;}
    //regression LinearRegression(std::vector<double >& x, std::vector<double >& y);
    void ComputeEtaPhiE();
    
    // temporary for test
    double GetSlopeZX() {return _mZX;}
    double GetInterceptZX() {return _qZX;}
    double GetSlopeZY() {return _mZY;}
    double GetInterceptZY() {return _qZY;}
    double GetX(int i=0);
  private:
    /** Copy constructor **/
    splitcalHPLCluster(const splitcalHPLCluster& cluster);
    splitcalHPLCluster operator=(const splitcalHPLCluster& cluster);

    int _index;
    double _eta, _phi, _energy;
    TVector3 _start;
    TVector3 _end;
    std::vector<splitcalHit* > _vectorOfHits;
    std::vector<std::vector<splitcalHit*>*> vectorOfClusters;
    // temporary for test
    double _mZX, _qZX;
    double _mZY, _qZY;

    ClassDef(splitcalHPLCluster,1);
    
};

#endif
