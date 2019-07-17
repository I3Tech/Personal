/*
 * CaddWaypoint.h
 *
 *  Created on: 18-Jan-2018
 *      Author: skand
 */

#ifndef CADDWAYPOINT_H_
#define CADDWAYPOINT_H_


#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>

#include "../myCode/CRoute.h"


class CAddWaypoint: public CppUnit::TestFixture{
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

	void testEmptyWpDb() {
		myStorage->setMediaName("DatabaseTest");
		myStorage->readData(*myWpDb, *myPoiDb, REPLACE);
		myWpDb->emptyDataContainer();
		myRoute->connectToWpDatabase(myWpDb);
		myRoute->addWaypoint("Amsterdam");

		CPPUNIT_ASSERT(myRoute->getRoute().size() == 0);
	}

	void testNameExistinWpDb() {
		myStorage->setMediaName("DatabaseTest");
		myStorage->readData(*myWpDb, *myPoiDb, REPLACE);
		myRoute->connectToWpDatabase(myWpDb);
		myRoute->addWaypoint("Amsterdam");
		CPPUNIT_ASSERT(myRoute->getRoute().size() == 1);
	}

	void testNameNotExistinWpDb() {
		myStorage->setMediaName("DatabaseTest");
		myStorage->readData(*myWpDb, *myPoiDb, REPLACE);
		myRoute->connectToWpDatabase(myWpDb);
		myRoute->addWaypoint("ErrorName");
		CPPUNIT_ASSERT(myRoute->getRoute().size() == 0);
	}

	static CppUnit::TestSuite* suite() {

		CppUnit::TestSuite* suite = new CppUnit::TestSuite("Add waypoint test");
		suite->addTest(new CppUnit::TestCaller<CAddWaypoint>
		("Wp Database Empty Test", &CAddWaypoint::testEmptyWpDb));

		suite->addTest(new CppUnit::TestCaller<CAddWaypoint>
		("Wp Exist is Database", &CAddWaypoint::testNameExistinWpDb));

		suite->addTest(new CppUnit::TestCaller<CAddWaypoint>
		("Wp Not exist in Database", &CAddWaypoint::testNameNotExistinWpDb));

		return suite;
	}

};


#endif /* CADDWAYPOINT_H_ */
