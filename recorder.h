/*******************************************************************
*
*  DESCRIPTION: Atomic Model Recorder
*
*  AUTHOR: Chris Smith 
*
*  EMAIL: mailto://spectre7@sympatico.ca
*
*  DATE: 22/10/2003
*
*******************************************************************/

#ifndef __RECORDER_H
#define __RECORDER_H

#include <list>
#include "atomic.h"     // class Atomic

class Recorder : public Atomic
{
public:
	Recorder( const string &name = "Recorder" );
	//Default constructor

	virtual string className() const ;

protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &in ;	    		
	Port &data_out ;	  // where data is sent out

	Time preparationTime ;

	int item ;

};	// class Recorder

// ** inline ** // 
inline
string Recorder::className() const
{
	return "Recorder" ;
}

#endif   //__RECORDER_H

