/*
 * COperatorPlusEquals.h
 *
 *  Created on: 18-Jan-2018
 *      Author: skand
 */

#ifndef COPERATORPLUSEQUALS_H_
#define COPERATORPLUSEQUALS_H_


#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>

#include "../myCode/CRoute.h"

class COperatorPlusEquals: public CppUnit::TestFixture{
private:
	CRoute* myRoute;
	CWpDatabase* myWpDb;
	CPoiDatabase* myPoiDb;
	CJsonPersistence* myStorage;


public :

	void setUp()
	{
		myRoute = new CRoute;
		myWpDb  = new CWpDatabase;
		myPoiDb = new CPoiDatabase;
		myStorage = new CJsonPersistence;
	}

	void tearDown()
	{
		delete myRoute;
		delete myWpDb;
		delete myPoiDb;
		delete myStorage;
	}

	void testwithNoPoiDb() {
		myWpDb = NULL;
		myPoiDb = NULL;
		myRoute->connectToWpDatabase(myWpDb);
		myRoute->connectToPoiDatabase(myPoiDb);
		*myRoute += "H_DA";
		CPPUNIT_ASSERT(myRoute->getRoute().size() == 0);
	}

	void testwithNoWpDb() {
		myStorage->setMediaName("DatabaseTest");
		myStorage->readData(*myWpDb, *myPoiDb, REPLACE);
		myWpDb = NULL;
		myRoute->connectToWpDatabase(myWpDb);
		myRoute->connectToPoiDatabase(myPoiDb);
		*myRoute += "H_DA";
		CPPUNIT_ASSERT(myRoute->getRoute().size() == 0);
	}

	void testAddPoi() {
		myStorage->setMediaName("DatabaseTest");
		myStorage->readData(*myWpDb, *myPoiDb, REPLACE);
		myRoute->connectToWpDatabase(myWpDb);
		myRoute->connectToPoiDatabase(myPoiDb);
		*myRoute += "H_DA";
		CPPUNIT_ASSERT(myRoute->getRoute().size() == 1);
	}

	void testAddWp() {
		myStorage->setMediaName("DatabaseTest");
		myStorage->readData(*myWpDb, *myPoiDb, REPLACE);
		myRoute->connectToWpDatabase(myWpDb);
		myRoute->connectToPoiDatabase(myPoiDb);
		*myRoute += "Amsterdam";
		CPPUNIT_ASSERT(myRoute->getRoute().size() == 1);
	}

	void testNoPoiWp() {
		myStorage->setMediaName("DatabaseTest");
		myStorage->readData(*myWpDb, *myPoiDb, REPLACE);
		myRoute->connectToWpDatabase(myWpDb);
		myRoute->connectToPoiDatabase(myPoiDb);
		*myRoute += "Error";
		CPPUNIT_ASSERT(myRoute->getRoute().size() == 0);
	}

	void testBothPoiWp() {
		myStorage->setMediaName("DatabaseTest");
		myStorage->readData(*myWpDb, *myPoiDb, REPLACE);
		myRoute->connectToWpDatabase(myWpDb);
		myRoute->connectToPoiDatabase(myPoiDb);
		*myRoute += "Darmstadt";
		CPPUNIT_ASSERT(myRoute->getRoute().size() == 2);
	}




	static CppUnit::TestSuite* suite() {

		CppUnit::TestSuite* suite = new CppUnit::TestSuite("Operator +=");

		suite->addTest(new CppUnit::TestCaller<COperatorPlusEquals>
		("Poi Db dont exist", &COperatorPlusEquals::testwithNoPoiDb));

		suite->addTest(new CppUnit::TestCaller<COperatorPlusEquals>
		("Wp Db dont exist", &COperatorPlusEquals::testwithNoWpDb));

		suite->addTest(new CppUnit::TestCaller<COperatorPlusEquals>
		("Test adding Poi", &COperatorPlusEquals::testAddPoi));

		suite->addTest(new CppUnit::TestCaller<COperatorPlusEquals>
		("Test adding Poi", &COperatorPlusEquals::testAddWp));

		suite->addTest(new CppUnit::TestCaller<COperatorPlusEquals>
		("Poi and Wp dont exist", &COperatorPlusEquals::testNoPoiWp));

		suite->addTest(new CppUnit::TestCaller<COperatorPlusEquals>
		("Poi and Wp both exist", &COperatorPlusEquals::testBothPoiWp));
		return suite;
	}

};



#endif /* COPERATORPLUSEQUALS_H_ */
