/*******************************************************************
*
*  DESCRIPTION: Atomic Model Comparitor
*
*  AUTHOR: Chris Smith 
*
*  EMAIL: mailto://spectre7@sympatico.ca
*
*  DATE: 22/10/2003
*
*******************************************************************/

#ifndef __COMPARITOR_H
#define __COMPARITOR_H

#include <list>
#include "atomic.h"     // class Atomic
#include "model.h"     // class Model

class Comparitor : public Atomic
{
public:
	Comparitor( const string &name = "Comparitor" );	
	//Default constructor

	virtual string className() const ;

protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
				   
	const Port &new_data;		        // where data comes in
	const Port &start_stop;		        // where WOW comes in
	Port &data_out;				// where data to record is sent out 

	Time preparationTime ;

	int threshold ;	                       // new data must be +/- threshold than last data 
	int received_data ;                    // data value just received
	int old_data ;			       // last data value received
	int WOW ;			       // aircraft is waiting on ground

};	// class Comparitor

// ** inline ** // 
inline
string Comparitor::className() const
{
	return "Comparitor" ;
}

#endif   //__COMPARITOR_H

