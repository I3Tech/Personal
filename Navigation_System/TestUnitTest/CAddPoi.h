/*
 * CAddPoi.h
 *
 *  Created on: 18-Jan-2018
 *      Author: skand
 */

#ifndef CADDPOI_H_
#define CADDPOI_H_


#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>

#include "../myCode/CRoute.h"


class CAddPoi: public CppUnit::TestFixture{
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

	void testInvalidWp() {
		myStorage->setMediaName("DatabaseTest");
		myStorage->readData(*myWpDb, *myPoiDb, REPLACE);
		myRoute->connectToWpDatabase(myWpDb);
		myRoute->connectToPoiDatabase(myPoiDb);
		myRoute->addPoi("H_DA","Amsterdam");

		CPPUNIT_ASSERT(myRoute->getRoute().size() == 0);
	}

	void testInvalidPoi() {
		myStorage->setMediaName("DatabaseTest");
		myStorage->readData(*myWpDb, *myPoiDb, REPLACE);
		myRoute->connectToWpDatabase(myWpDb);
		myRoute->connectToPoiDatabase(myPoiDb);
		myRoute->addWaypoint("Amsterdam");
		myRoute->addPoi("ErrorPoi", "Amsterdam");
		CPPUNIT_ASSERT(myRoute->getRoute().size() == 1);
	}


	static CppUnit::TestSuite* suite() {

		CppUnit::TestSuite* suite = new CppUnit::TestSuite("Add Poi test");
		suite->addTest(new CppUnit::TestCaller<CAddPoi>
		("Waypoint Not Present", &CAddPoi::testInvalidWp));

		suite->addTest(new CppUnit::TestCaller<CAddPoi>
		("Poi Not Present", &CAddPoi::testInvalidPoi));


		return suite;
	}

};




#endif /* CADDPOI_H_ */
