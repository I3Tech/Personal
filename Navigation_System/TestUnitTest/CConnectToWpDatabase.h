#ifndef CCONNECTTOWPDATABASE_H_
#define CCONNECTTOWPDATABASE_H_

#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>

#include "../myCode/CRoute.h"


class CConnectToWpDatabase: public CppUnit::TestFixture{
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

	void testDatabaseConnected() {
		myStorage->setMediaName("DatabaseTest");
		myStorage->readData(*myWpDb, *myPoiDb, REPLACE);
		myRoute->connectToWpDatabase(myWpDb);
		myRoute->addWaypoint("Amsterdam");

		CPPUNIT_ASSERT(myRoute->getRoute().size() == 1);
	}

	void testDatabaseNotConnected() {
		myRoute->connectToWpDatabase(NULL);
		myRoute->addWaypoint("Amsterdam");
		CPPUNIT_ASSERT(myRoute->getRoute().size() == 0);
	}

	static CppUnit::TestSuite* suite() {

		CppUnit::TestSuite* suite = new CppUnit::TestSuite("Wp Database Tests");
		suite->addTest(new CppUnit::TestCaller<CConnectToWpDatabase>
		("Wp Database Connection Test", &CConnectToWpDatabase::testDatabaseConnected));

		suite->addTest(new CppUnit::TestCaller<CConnectToWpDatabase>
		("Wp Database Not Connected Test", &CConnectToWpDatabase::testDatabaseNotConnected));

		return suite;
	}

};

#endif /* CCONNECTTOWPDATABASE_H_ */
