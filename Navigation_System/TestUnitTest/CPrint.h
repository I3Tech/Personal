/*
 * CPrint.h
 *
 *  Created on: 18-Jan-2018
 *      Author: skand
 */

#ifndef CPRINT_H_
#define CPRINT_H_


#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>

#include "../myCode/CRoute.h"


class CPrint: public CppUnit::TestFixture{
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

	void testWpPoiPrint() {
		myStorage->setMediaName("DatabaseTest");
		myStorage->readData(*myWpDb, *myPoiDb, REPLACE);
		myRoute->connectToWpDatabase(myWpDb);
		myRoute->connectToPoiDatabase(myPoiDb);
		myRoute->addWaypoint("Amsterdam");
		myRoute->addPoi("H_DA","Amsterdam");
        myRoute->print();
		CPPUNIT_ASSERT(myRoute->getRoute().size() == 2);
	}

	static CppUnit::TestSuite* suite() {

		CppUnit::TestSuite* suite = new CppUnit::TestSuite("Get Distance");
		suite->addTest(new CppUnit::TestCaller<CPrint>
		("Get Distance with poi", &CPrint::testWpPoiPrint));

		return suite;
	}

};



#endif /* CPRINT_H_ */
