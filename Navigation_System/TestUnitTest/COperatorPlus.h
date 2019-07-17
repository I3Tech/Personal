/*
 * COperatorPlus.h
 *
 *  Created on: 18-Jan-2018
 *      Author: skand
 */

#ifndef COPERATORPLUS_H_
#define COPERATORPLUS_H_

#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>

#include "../myCode/CRoute.h"

class COperatorPlus: public CppUnit::TestFixture{
private:
	CRoute* myRoute;
	CRoute* TestRoute;
	CWpDatabase* myWpDb;
	CPoiDatabase* myPoiDb;
	CJsonPersistence* myStorage;


public :

	void setUp()
	{
		myRoute = new CRoute;
		TestRoute = new CRoute;
		myWpDb  = new CWpDatabase;
		myPoiDb = new CPoiDatabase;
		myStorage = new CJsonPersistence;
	}

	void tearDown()
	{
		delete myRoute;
		delete TestRoute;
		delete myWpDb;
		delete myPoiDb;
		delete myStorage;
	}

	void testConnectSameDb() {
		myStorage->setMediaName("DatabaseTest");
		myStorage->readData(*myWpDb, *myPoiDb, REPLACE);

		myRoute->connectToWpDatabase(myWpDb);
		myRoute->connectToPoiDatabase(myPoiDb);
		TestRoute->connectToWpDatabase(myWpDb);
		TestRoute->connectToPoiDatabase(myPoiDb);

		myRoute->addWaypoint("Amsterdam");

		*TestRoute = *TestRoute + *myRoute;
		CPPUNIT_ASSERT(TestRoute->getRoute().size() == 1);
	}

	void testConnectDifferentDb() {
		myStorage->setMediaName("DatabaseTest");
		myStorage->readData(*myWpDb, *myPoiDb, REPLACE);

		myRoute->connectToWpDatabase(myWpDb);
		myRoute->connectToPoiDatabase(myPoiDb);


		TestRoute->connectToWpDatabase(NULL);
		TestRoute->connectToPoiDatabase(NULL);

		myRoute->addWaypoint("Amsterdam");

		*TestRoute = *TestRoute + *myRoute;
		CPPUNIT_ASSERT(TestRoute->getRoute().size() == 0);
	}

	static CppUnit::TestSuite* suite() {

		CppUnit::TestSuite* suite = new CppUnit::TestSuite("Operator +");

		suite->addTest(new CppUnit::TestCaller<COperatorPlus>
		("Both Routes Connected to same Db", &COperatorPlus::testConnectSameDb));

		suite->addTest(new CppUnit::TestCaller<COperatorPlus>
		("Routes are connected to different Db", &COperatorPlus::testConnectDifferentDb));


		return suite;
	}

};





#endif /* COPERATORPLUS_H_ */
