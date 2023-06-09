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

/** include files **/

#include "comparitor.h"  // class Comparitor
#include "message.h"     // class ExternalMessage, InternalMessage
#include "mainsimu.h"    // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: Comparitor
* Description: 
********************************************************************/
Comparitor::Comparitor( const string &name )
: Atomic( name )
, new_data( addInputPort( "new_data" ) )
, start_stop( addInputPort( "start_stop" ) )
, data_out( addOutputPort( "data_out" ) )
, preparationTime( 0, 0, 1, 0 )
{
	string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;

	if( time != "" )
		preparationTime = time ;
}

/*******************************************************************
* Function Name: initFunction
* Description: Resetea la lista
* Precondition: El tiempo del proximo evento interno es Infinito
********************************************************************/
Model &Comparitor::initFunction()
{
  threshold = 1;
  received_data = -1;
  old_data = -1;
  WOW = 0;

  return *this ;
 }

/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model &Comparitor::externalFunction( const ExternalMessage &msg )
{
	if(( msg.port() == new_data ) && WOW)	// receiving data and in air
	{
	  received_data = msg.value();
	  if(( received_data == old_data + threshold)
		|| ( received_data == old_data)	// new data same as old data
		      || ( received_data == old_data - threshold))
          {
	      passivate();			// go to sleep
	  }
	  else
	  {
	      old_data = msg.value();			// new data is different
	      holdIn( active, preparationTime );	// wait one sec for processing
	  }
	} // if(( msg.port() == new_data ) && WOW )

	
	if( msg.port() == start_stop )
	{
		if( msg.value() == 1 )	// can start processing
		{
			WOW = 1;			// aircraft is flying
			passivate();		// go to sleep
		}
		else
		{
			WOW = 0;			// aircraft is on ground
			passivate();		// go to sleep
		}
	} // if( msg.port() == start_stop )

	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description: 
********************************************************************/
Model &Comparitor::internalFunction( const InternalMessage & )
{
	passivate();		// go to sleep
	return *this ;
}

/*******************************************************************
* Function Name: outputFunction
* Description: 
********************************************************************/
Model &Comparitor::outputFunction( const InternalMessage &msg )
{
	if(WOW)
	{
		sendOutput( msg.time(), data_out, received_data ) ;
		// send data and time to out port
	}
	return *this ;
}

