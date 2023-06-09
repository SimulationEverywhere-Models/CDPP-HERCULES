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

/** include files **/

#include "Flight_Data_Generator.h"  // class Flight_Data_Generator
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

#include <cstdlib>		// library containing Random Number Generator

/** public functions **/

/*******************************************************************
* Function Name: Flight_Data_Generator
* Description: 
********************************************************************/
Flight_Data_Generator::Flight_Data_Generator( const string &name )
: Atomic( name )
, out( addOutputPort( "out" ) )
, preparationTime( 0, 0, 1, 0 )
{
  string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;

  if( time != "" ) preparationTime = time ;
}

/*******************************************************************
* Function Name: initFunction
* Description: Resetea la lista
* Precondition: El tiempo del proximo evento interno es Infinito
********************************************************************/
Model &Flight_Data_Generator::initFunction()
{
  //cout << " *** I am in the init function *** " ;
  holdIn( active, Time::Zero ) ;
  generated_number = -1 ;
  return *this;
}

/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model &Flight_Data_Generator::externalFunction( const ExternalMessage &msg )
{
     //cout << " *** I am in the external function *** " ;
     return *this ;
}

/*******************************************************************
* Function Name: internalFunction
* Description: 
********************************************************************/
Model &Flight_Data_Generator::internalFunction( const InternalMessage & )
{
     //cout << " *** I am in the internal function *** " ;
     holdIn( active, preparationTime  ) ;
     return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description: 
********************************************************************/
Model &Flight_Data_Generator::outputFunction( const InternalMessage &msg )
{
  //cout << " *** I am in the output function *** " ;
  generated_number = (1+rand() % 100) ;
  /* yields random numbers between 1 and 100 */
  sendOutput(msg.time(), out, generated_number );
  /* send data and time to out port */	
  return *this ;
}

