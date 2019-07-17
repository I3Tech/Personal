/*
 * CCopyConstructor.h
 *
 *  Created on: 18-Jan-2018
 *      Author: skand
 */

#ifndef CCOPYCONSTRUCTOR_H_
#define CCOPYCONSTRUCTOR_H_


#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>

#include "../myCode/CRoute.h"


class CCopyConstructor: public CppUnit::TestFixture{
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

	void testCopyConstructor() {
		myStorage->setMediaName("DatabaseTest");
		myStorage->readData(*myWpDb, *myPoiDb, REPLACE);
		myRoute->connectToWpDatabase(myWpDb);
		myRoute->addWaypoint("Amsterdam");
        CRoute TestRoute(*myRoute);

		CPPUNIT_ASSERT(TestRoute.getRoute().size() == 1);
	}


	static CppUnit::TestSuite* suite() {

		CppUnit::TestSuite* suite = new CppUnit::TestSuite("Wp Database Tests");
		suite->addTest(new CppUnit::TestCaller<CCopyConstructor>
		("Wp Database Connection Test", &CCopyConstructor::testCopyConstructor));

		return suite;
	}

};




#endif /* CCOPYCONSTRUCTOR_H_ */
