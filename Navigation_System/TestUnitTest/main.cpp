/*Include Standard Libraries here*/


#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <cppunit/ui/text/TestRunner.h>

#include "CConnectToWpDatabase.h"
#include "CConnectToPoiDatabase.h"
#include "CAddWaypoint.h"
#include "CDistanceCalculator.h"
#include "COperatorPlusEquals.h"
#include "COperatorPlus.h"
#include "CPrint.h"
#include "CAddPoi.h"
#include "CCopyConstructor.h"

//
using namespace CppUnit;
/*Macro definitions*/

int main (int argc, char* argv[])
{

	TextUi::TestRunner runner;
	runner.addTest( CConnectToWpDatabase::suite() );
	runner.addTest( CConnectToPoiDatabase::suite() );
	runner.addTest( CAddWaypoint::suite() );
	runner.addTest( CDistanceCalculator::suite() );
	runner.addTest( COperatorPlusEquals::suite() );
	runner.addTest( COperatorPlus::suite() );
	runner.addTest( CPrint::suite() );
	runner.addTest( CAddPoi::suite() );
	runner.addTest( CCopyConstructor::suite() );


	runner.run();
	return 0;
}

