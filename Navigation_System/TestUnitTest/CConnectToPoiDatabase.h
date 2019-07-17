#ifndef CCONNECTTOPOIDATABASE_H_
#define CCONNECTTOPOIDATABASE_H_



#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>

#include "../myCode/CRoute.h"


class CConnectToPoiDatabase: public CppUnit::TestFixture{
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

	void testPoiDatabaseConnected() {
		myStorage->setMediaName("DatabaseTest");
		myStorage->readData(*myWpDb, *myPoiDb, REPLACE);
		myRoute->connectToWpDatabase(myWpDb);
		myRoute->connectToPoiDatabase(myPoiDb);
		myRoute->addWaypoint("Amsterdam");
		myRoute->addPoi("H_DA","Amsterdam");

		CPPUNIT_ASSERT(myRoute->getRoute().size() == 2);
	}

	void testPoiDatabaseNotConnected() {
		myRoute->connectToPoiDatabase(NULL);
		myRoute->addWaypoint("Amsterdam");
		myRoute->addPoi("H_DA","Amsterdam");
		CPPUNIT_ASSERT(myRoute->getRoute().size() == 0);
	}

	static CppUnit::TestSuite* suite() {

		CppUnit::TestSuite* suite = new CppUnit::TestSuite("Poi Database Tests");
		suite->addTest(new CppUnit::TestCaller<CConnectToPoiDatabase>
		("Poi Database Connection Test", &CConnectToPoiDatabase::testPoiDatabaseConnected));

		suite->addTest(new CppUnit::TestCaller<CConnectToPoiDatabase>
		("Poi Database Not Connected Test", &CConnectToPoiDatabase::testPoiDatabaseNotConnected));

		return suite;
	}

};

#endif /* CCONNECTTOWPDATABASE_H_ */
