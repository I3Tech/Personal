
#ifndef CDISTANCECALCULATOR_H_
#define  CDISTANCECALCULATOR_H_


#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>

#include "../myCode/CRoute.h"


class CDistanceCalculator: public CppUnit::TestFixture{
private:
	CRoute* myRoute;
	CWpDatabase* myWpDb;
	CPoiDatabase* myPoiDb;
	CJsonPersistence* myStorage;
	CPOI* myPoi;

public :

	void setUp()
	{
		myPoi = new CPOI;
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
		delete myPoi;
	}

	void testwithPoi() {
		myStorage->setMediaName("DatabaseTest");
		myStorage->readData(*myWpDb, *myPoiDb, REPLACE);
		myRoute->connectToWpDatabase(myWpDb);
		myRoute->connectToPoiDatabase(myPoiDb);
		myRoute->addWaypoint("Amsterdam");
		myRoute->addPoi("H_DA","Amsterdam");
		double dist = myRoute->getDistanceNextPoi(*myWpDb->getpointerToData("Amsterdam"), *myPoi);

		CPPUNIT_ASSERT(dist != 999999);
	}

	void testwitoutPoi() {
		myStorage->setMediaName("DatabaseTest");
		myStorage->readData(*myWpDb, *myPoiDb, REPLACE);
		myRoute->connectToWpDatabase(myWpDb);
		myRoute->connectToPoiDatabase(myPoiDb);
		myRoute->addWaypoint("Amsterdam");
		double dist = myRoute->getDistanceNextPoi(*myWpDb->getpointerToData("Amsterdam"),*myPoi);
		CPPUNIT_ASSERT(dist == 999999);
	}


	static CppUnit::TestSuite* suite() {

		CppUnit::TestSuite* suite = new CppUnit::TestSuite("Get Distance");
		suite->addTest(new CppUnit::TestCaller<CDistanceCalculator>
		("Get Distance with poi", &CDistanceCalculator::testwithPoi));

		suite->addTest(new CppUnit::TestCaller<CDistanceCalculator>
		("Get Distance without poi", &CDistanceCalculator::testwitoutPoi));

		return suite;
	}

};


#endif /* CDistanceCalculator */
