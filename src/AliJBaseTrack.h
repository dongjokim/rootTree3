// $Id: AliJBaseTrack.h,v 1.5 2008/05/08 15:19:52 djkim Exp $

///////////////////////////////////////////////////
/*
   \file AliJBaseTrack.h
   \brief
   \author D.J.Kim(University of Jyvaskyla)
   \email: djkim@jyu.fi
   \version $Revision: 1.5 $
   \date $Date: 2008/05/08 15:19:52 $
   */
///////////////////////////////////////////////////

#ifndef ALIJBASETRACK_H
#define ALIJBASETRACK_H

#ifndef ROOT_TObject
#include <TObject.h>
#endif

#include <iostream>
#include <TLorentzVector.h>

using namespace std;

class AliJBaseTrack : public TLorentzVector {
    public:
        AliJBaseTrack();
        AliJBaseTrack(float px,float py, float pz, float e, Int_t id, Short_t ptype, Char_t charge); // constructor
        AliJBaseTrack(const AliJBaseTrack& a);
        AliJBaseTrack(const TLorentzVector & a);
        virtual ~AliJBaseTrack(){;}    //destructor

        TLorentzVector GetLorentzVector(){ return TLorentzVector(Px(), Py(), Pz(), E());}

        Int_t         GetID()           const { return fID;}
        Int_t         GetLabel()        const { return fLabel; }
        Short_t       GetParticleType() const { return fParticleType;}
        ULong_t       GetStatus()       const { return fStatus; }
        Short_t       GetCharge()       const { return fCharge; } 

        void SetID      (const int id){fID=id;}
        void SetLabel   (const Int_t label ){ fLabel=label; }
        void SetParticleType(const Short_t ptype){ fParticleType=ptype; }
        void SetStatus  (const ULong_t status){ fStatus=status; }
        void SetCharge  (const Char_t charge){ fCharge=charge; }

        virtual void Print(Option_t *option="") const;

        // Operators
        AliJBaseTrack& operator=(const AliJBaseTrack& trk);

    protected:
        Int_t         fID;            // Unique track ID
        Int_t         fLabel;         // Unique track label for MC-Data relation
        Short_t       fParticleType;  // ParticleType 
        Char_t        fCharge;        // track charge for real data
        ULong_t       fStatus;        // reconstruction status flags or MC status 

        ClassDef(AliJBaseTrack,1)
};

#endif

