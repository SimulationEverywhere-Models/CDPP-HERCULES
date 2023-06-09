/*******************************************************************
*
*  DESCRIPTION: Simulator::registerNewAtomics()
*
*  AUTHOR: Chris Smith 
*
*  EMAIL: spectre7@sympatico.ca
*
*  DATE: 22/10/2003
*
*******************************************************************/

#include "modeladm.h" 
#include "mainsimu.h"
#include "flight_data_generator.h"      // class Flight_Data_Generator
#include "recorder.h"			// class Recorder
#include "comparitor.h"			// class Comparitor
#include "queue.h"			// class Queue
#include "generat.h"			// class Generator
#include "cpu.h"			// class CPU
#include "transduc.h"			// class Transducer
#include "trafico.h"			// class Trafico


void MainSimulator::registerNewAtomics()
{
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Flight_Data_Generator>() , "Flight_Data_Generator" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Recorder>() , "Recorder" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Comparitor>() , "Comparitor" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Queue>() , "Queue" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Generator>() , "Generator" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<CPU>() , "CPU" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Transducer>() , "Transducer" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Trafico>() , "Trafico" ) ;
}

