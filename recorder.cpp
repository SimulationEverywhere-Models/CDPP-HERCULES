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

/** include files **/

#include "Recorder.h"  // class Recorder
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

#include <cstdlib>		// library containing Random Number Generator

/** public functions **/

/*******************************************************************
* Function Name: Recorder
* Description: 
********************************************************************/
Recorder::Recorder( const string &name )
: Atomic( name )
, in( addInputPort ( "in" ) )
, data_out( addOutputPort( "data_out" ) )
, preparationTime( 0, 0, 0.5, 0 )
{
    string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;
    if( time != "" ) preparationTime = time ;
}

/*******************************************************************
* Function Name: initFunction
* Description: Resetea la lista
* Precondition: El tiempo del proximo evento interno es Infinito
********************************************************************/
Model &Recorder::initFunction()
{
  //cout << " *** I am in the init function *** " ;
  item = -1 ;
  return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model &Recorder::externalFunction( const ExternalMessage &msg )
{
  //cout << " *** I am in the external function *** " ;
  holdIn( active, preparationTime );
  // wait prep-time
  item = msg.value() ;
  // this is the item to output
  return *this;	
}

/*******************************************************************
* Function Name: internalFunction
* Description: 
********************************************************************/
Model &Recorder::internalFunction( const InternalMessage & )
{
  //cout << " *** I am in the internal function *** " ;
  passivate();
  // go to sleep
  return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description: 
********************************************************************/
Model &Recorder::outputFunction( const InternalMessage &msg )
{
  //cout << " *** I am in the output function *** " ;
  sendOutput(msg.time(), data_out, item );
  // send data and time to out port	
  return *this ;
}

