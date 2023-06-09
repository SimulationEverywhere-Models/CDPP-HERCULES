/*******************************************************************
*
*  DESCRIPTION: Atomic Model Flight_Data_Generator
*
*  AUTHOR: Chris Smith 
*
*  EMAIL: mailto://spectre7@sympatico.ca
*
*  DATE: 22/10/2003
*
*******************************************************************/

#ifndef __FLIGHT_DATA_GENERATOR_H
#define __FLIGHT_DATA_GENERATOR_H

#include <list>
#include "atomic.h"     // class Atomic

#include <cstdlib>		// library containing Random Number Generato

class Flight_Data_Generator : public Atomic
{
public:
	Flight_Data_Generator( const string &name = "Flight_Data_Generator" );	
	//Default constructor

	virtual string className() const ;

protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:	
	Port &out;		    // where data is sent out
	Time preparationTime ;      // time it takes to complete action

	int generated_number ;      // this is the random generated number

};	// class Flight_Data_Generator

// ** inline ** // 
inline
string Flight_Data_Generator::className() const
{
	return "Flight_Data_Generator" ;
}

#endif   //__FLIGHT_DATA_GENERATOR_H

