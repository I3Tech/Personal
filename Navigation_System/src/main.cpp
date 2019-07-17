/*Include Standard Libraries here*/
#include <iostream>
#include <stdlib.h>
using namespace std;

/*Include user Libraries here*/
#include "CWaypoint.h"
#include "CGPSSensor.h"
#include "CPOI.h"
#include "CPoiDatabase.h"
#include "CRoute.h"
#include "CNavigationsystem.h"
#include "CWpDatabase.h"
#include "CPersistentStorage.h"
#include "CStorage.h"
#include "CDatabase.h"
#include "CJsonPersistence.h"

/*Macro definitions*/

int main (void)
{
#if 0
	//CWaypoint constructor test
	CWaypoint amsterdam("Amsterdam",52.379189,4.899431);
	CWaypoint darmstadt("Darmstadt",49.878708,8.646927);
	CWaypoint berlin("Berlin",52.520008,13.404954);
	CWaypoint tokio("Tokio",35.652832,139.839478);
	CWaypoint newWaypoint;
#endif

#if 0
	// Test f
	berlin.print(DEGREE);
	berlin.print(MMSS);
#endif

#if 0
	//Test g
	double LAT = berlin.getLatitude();
	double LONG = berlin.getLongitude();
	std::string N = berlin.getName();
	cout<< "Latitude:"<<LAT<<" "<<"Longitude:"<<LONG<<" "<<"Name:"<<N<<" "<<endl;
#endif

#if 0
	//Test h
	/*
	 * Test this with verbose mode ON in CWaypoint. Local variables name, latitude,longitude will have
	 * different addresses compared to parameters of class CWaypoint(m_name, m_latitude,m_longitude) but
	 * will have same data.
	 */
	std::string name ="name";
	double latitude = 0;
	double longitude = 0;
	CWaypoint tokio("Tokio",35.652832,139.839478);
	tokio.getAllDataByReference(name,latitude,longitude);
	cout<< "Latitude:"<<latitude<<" "<<"Longitude:"<<longitude<<" "<<"Name:"<<name<<" "<<endl;
	cout<< "Addresses"<<" "<< "latitude:"<<" "<<&latitude<<" "<< "longitude:"<<" "<<&longitude<<" "<< "name:"<<" "<<&name<<endl;

#endif

#if 0
	//Test i
	CWaypoint amsterdam("Amsterdam",52.379189,4.899431);
	CWaypoint berlin("Berlin",52.520008,13.404954);
	CWaypoint tokio("Tokio",35.652832,139.839478);

	double distance_1 = amsterdam.calculateDistance(berlin);
	cout<< distance_1<<endl;

	double distance_2 = berlin.calculateDistance(tokio);
	cout<< distance_2<<endl;
#endif

	/*----------CPIO CLASS--------------*/

#if 0
	std::string  name;double lat;double longi; t_poi type;std::string description;
	//Test CPIO constructor
	CPOI myPoi1;
	CPOI myPoi2(RESTAURANT,"Mensa","Nice Pommes",52.6666,8.23232);
#endif

#if 0
	//Test getAllDataByReference
	myPoi2.getAllDataByReference(name,lat,longi,type,description);
	cout << name<<": "<<type<<": "<< description << ": at  " << lat <<" lat "<< longi << " long" << endl;
#endif

#if 0
	//Test print
	myPoi2.print();
#endif

	/*----------CGPSSensor CLASS-----------*/

#if 0
	CGPSSensor TestSensor;
	CWaypoint TestData;
	TestData= TestSensor.getCurrentPosition();
	TestData.print(MMSS);
#endif

	/*----------CPoiDatabase----------------*/
#if 0
	//Test Constructor
	CPoiDatabase poiDatabase;


	//Test addPoi
	poiDatabase.addPoi(RESTAURANT, "Mylari", "Best Masala Dosa", 72.8888, 46.8765);
	poiDatabase.addPoi(RESTAURANT, "MP", "Best Masala Dosa", 72.8888, 46.8765);
	poiDatabase.addPoi(RESTAURANT, "SS", "Best Masala Dosa", 72.8888, 46.8765);
	//	poiDatabase.addPoi(RESTAURANT, "Mylari", "Best Masala Dosa", 72.8888, 46.8765);
	poiDatabase.addPoi(RESTAURANT, "KK", "Best Masala Dosa", 72.8888, 46.8765);
	poiDatabase.addPoi(RESTAURANT, "SST", "Best Masala Dosa", 72.8888, 46.8765);
	poiDatabase.addPoi(RESTAURANT, "BH", "Best Masala Dosa", 72.8888, 46.8765);
	poiDatabase.addPoi(RESTAURANT, "HB", "Best Masala Dosa", 72.8888, 46.8765);
	poiDatabase.addPoi(RESTAURANT, "KAK", "Best Masala Dosa", 72.8888, 46.8765);
	poiDatabase.addPoi(RESTAURANT, "HH", "Best Masala Dosa", 72.8888, 46.8765);
	poiDatabase.addPoi(RESTAURANT, "POIH", "Best Masala Dosa", 72.8888, 46.8765);

	//Test getPoi
	CPOI* pMyPoi;
	pMyPoi = poiDatabase.getpointerToPoi("Hanmanthu Biriyani");
	if(pMyPoi!=NULL)
	{
		pMyPoi->print();
	}
	else
	{
		cout << "Cant print POI (NULL pointer is passed)";
	}
#endif

	/*------------CRoute---------------*/
#if 0
	//Create DB
	CPoiDatabase myDB;
	myDB.addPoi(TOURISTIC, "Berlin", "The History", 52.520008 ,13.404954);
	myDB.addPoi(TOURISTIC, "Tokyo","Car Racing",35.652832,139.839478);
	myDB.addPoi(UNIVERSITY, "SJCE","Can bunk a lot",70.123, 45.0987);

	//Waypoints
	CWaypoint amsterdam("Amsterdam",52.379189,4.899431);
	CWaypoint darmstadt("Darmstadt",49.878708,8.646927);

	CRoute myRoute(2,2);

	myRoute.addWaypoint(amsterdam);
	myRoute.addWaypoint(darmstadt);
	myRoute.connectToPoiDatabase(&myDB);
	myRoute.addPoi("Berlin");
	myRoute.addPoi("Tokyo");

	myRoute.print();

	double distance=0;
	CPOI TestPoi;

	distance = myRoute.getDistanceNextPoi(amsterdam,TestPoi);
	cout <<endl<< "Distance to next POI is: "<<distance<<endl;

	cout<<endl;
	amsterdam.print(MMSS);
	cout<<endl;
	TestPoi.print();
#endif

#if 0
	CNavigationSystem myNavigation;
	myNavigation.run();
#endif

	//------------------------ Second assignment ---------------------------------//

	// Test CPoiDatabase
#if 0
	CPOI Heid(TOURISTIC, "Heidelberg", "The History", 49.3988 ,8.6724);
	CPOI H_DA(UNIVERSITY, "H_DA","University of Applied Sciences in Darmstadt",49.8673,8.6382);
	CPoiDatabase Db;

	// Test Addpoi
	Db.addPoi(Heid);
	Db.addPoi(H_DA);

	// Test GetPointerToPoi
	CPOI* Test;
	Test = Db.getpointerToPoi("H_DA");
	cout << *Test;

	//Error Condition
	Test = Db.getpointerToPoi("Not in Pool");
	if(Test == NULL)
	{
		cout <<endl<< "NULL : Test Passed"<<endl;
	}
	else
	{
		cout << "Some Wrong Hack"<< endl;
	}
#endif

	// Test CWpDatabase
#if 0
	CWaypoint amsterdam("Amsterdam",52.379189,4.899431);
	CWaypoint darmstadt("Darmstadt",49.878708,8.646927);
	CWaypoint berlin("Berlin",52.520008,13.404954);
	CWaypoint tokio("Tokio",35.652832,139.839478);
	CWpDatabase Db;

	// Test Addpoi
	Db.addWaypoint(amsterdam);
	Db.addWaypoint(darmstadt);

	// Test GetPointerToPoi
	CWaypoint* Test;
	Test = Db.getpointerTowaypoint("Amsterdam");
	cout << *Test;

	//Error Condition
	Test = Db.getpointerTowaypoint("Not in Pool");
	if(Test == NULL)
	{
		cout <<endl<< "NULL : Test Passed"<<endl;
	}
	else
	{
		cout << "Some Wrong Hack"<< endl;
	}
#endif

#if 0
	CNavigationSystem myNavigation;
	myNavigation.run();
#endif

#if 0
	CRoute myRoute;
	CPoiDatabase poiDb;
	CWpDatabase wpDb;


	CPOI Heid(TOURISTIC, "Heidelberg", "The History", 49.3988 ,8.6724);
	CPOI H_DA(UNIVERSITY,/* "Amsterdam"*/"H_DA","University of Applied Sciences in Darmstadt",49.8673,8.6382);
	poiDb.addPoi(Heid);
	poiDb.addPoi(H_DA);

	CWaypoint amsterdam("Amsterdam",52.379189,4.899431);
	CWaypoint tokio("Tokio",35.652832,139.839478);
	wpDb.addWaypoint(amsterdam);
	wpDb.addWaypoint(tokio);

	//connectToPoiDatabase
	myRoute.connectToPoiDatabase(&poiDb);
	cout << "Sent address: "<< &poiDb << endl;

	//connectToWpDatabase
	myRoute.connectToWpDatabase(&wpDb);
	cout << "Sent address: "<< &wpDb << endl;

	//Empty WP database Test
	//wpDb.emptyWpContainer();
	//myRoute.addWaypoint("Test_1_WP");

	//Empty POI database Test
	// poiDb.emptyPoiContainer();
	// myRoute.addWaypoint("Test_1_POI");

	//addWaypoint
	myRoute.addWaypoint("Test_2_WP");
	myRoute.addWaypoint("Amsterdam");
	myRoute.addWaypoint("Tokio");

	//addWaypoint
	myRoute.addPoi("Heidelberg","Amsterdam");
	myRoute.addPoi("H_DA"/*"Test_2_POI"*/,"Amsterdam");
	myRoute.addPoi("H_DA"/*"Amsterdam"*/,"Tokio");


	// print CRoute
	myRoute.print();
#endif

#if 0
	CRoute myRoute;
	CRoute dummyRoute;
	CPoiDatabase poiDb;
	CWpDatabase wpDb;

	//Test << operator on CWaypoint
	CWaypoint amsterdam("Amsterdam",52.379189,4.899431);
	cout << amsterdam;

	//Test << operator on CPOI
	CPOI Heid(TOURISTIC, "Heidelberg", "The History", 49.3988 ,8.6724);
	CPOI amster(TOURISTIC, "Amsterdam", "Everything legal", 52.379189,4.899431);
	cout << Heid;

	//Test += operator
	poiDb.addPoi(Heid);
	poiDb.addPoi(amster);
	wpDb.addWaypoint(amsterdam);

	myRoute.connectToPoiDatabase(&poiDb);
	dummyRoute.connectToPoiDatabase(&poiDb);
	myRoute.connectToWpDatabase(&wpDb);
	dummyRoute.connectToWpDatabase(&wpDb);

	myRoute += "Amsterdam";
	myRoute += "Heidelberg";
	dummyRoute += "Amsterdam";
	dummyRoute += "Heidelberg";
	myRoute += "Test";
	myRoute.print();

	//Test + operator
	cout << endl << endl << endl << "Test of + operator begins here << " << endl << endl;
	myRoute = myRoute + dummyRoute;
	myRoute.print();

#endif

#if 0
	// Test Read Data from database
	CPoiDatabase poiDb;
	CWpDatabase wpDb;
	CStorage Storage;

	CWaypoint amsterdam("Amsterdam",52.379189,4.899431);
	CWaypoint tokio("Tokio",35.652832,139.839478);
	CPOI Heid(TOURISTIC, "Heidelberg", "The History", 49.3988 ,8.6724);
	CPOI H_DA(UNIVERSITY, "H_DA","University of Applied Sciences in Darmstadt",49.8673,8.6382);

	poiDb.addPoi(Heid);
	poiDb.addPoi(H_DA);
	wpDb.addWaypoint(amsterdam);
	wpDb.addWaypoint(tokio);

	Storage.setMediaName("WriteTest");
	Storage.writeData(wpDb,poiDb);
#endif

#if 0

	CPoiDatabase poiDb;
	CWpDatabase wpDb;
	CStorage Storage;

	CWaypoint amsterdam("Amsterdam",52.379189,4.899431);
	CWaypoint darmstadt("Darmstadt",49.878708,8.646927);
	CWaypoint berlin("Berlin",52.520008,13.404954);
	CWaypoint tokio("Tokio",35.652832,139.839478);
	CWaypoint newWaypoint;

	CPOI Heid(TOURISTIC, "Heidelberg", "The History", 49.3988 ,8.6724);
	CPOI H_DA(UNIVERSITY, "H_DA","University of Applied Sciences in Darmstadt",49.8673,8.6382);
	CPOI Mylari(RESTAURANT, "Mylari", "Best Masala Dosa", 72.8888, 46.8765);


	//wpDb.addWaypoint(amsterdam);
	//wpDb.addWaypoint(darmstadt);
	//wpDb.addWaypoint(berlin);
	//wpDb.addWaypoint(tokio);
	//wpDb.addWaypoint(newWaypoint);

	//poiDb.addPoi(Heid);
	//poiDb.addPoi(H_DA);
	//poiDb.addPoi(Mylari);


	Storage.setMediaName("Input");
	Storage.readData(wpDb, poiDb, REPLACE);   //Test with replace mode
	//Storage.readData(wpDb, poiDb, MERGE);   //Test with merge mode
	wpDb.printaAllWpinDb();
	poiDb.printAllPoiDb();

#endif

#if 0
	//Test the template class
	CPOI Heid(TOURISTIC, "Heidelberg", "The History", 49.3988 ,8.6724);
	CPOI H_DA(UNIVERSITY, "H_DA","University of Applied Sciences in Darmstadt",49.8673,8.6382);
	CPOI Mylari(RESTAURANT, "Mylari", "Best Masala Dosa", 72.8888, 46.8765);

	CWaypoint amsterdam("Amsterdam",52.379189,4.899431);
	CWaypoint darmstadt("Darmstadt",49.878708,8.646927);
	CWaypoint berlin("Berlin",52.520008,13.404954);

	CDatabase<string,CWaypoint> db;
	CPoiDatabase poiDb;
	CWpDatabase wpDb;

	db.addData(amsterdam);
	db.addData(darmstadt);
	db.addData(Mylari);

	poiDb.addData(Heid);
	poiDb.addData(H_DA);
	poiDb.addData(Mylari);

	wpDb.addData(amsterdam);
	wpDb.addData(darmstadt);

	map<string,CWaypoint> myDb = wpDb.getMap();
#endif

#if 1

	CJsonPersistence Test;

	CWaypoint amsterdam("Amsterdam",52.379189,4.899431);
	CWaypoint darmstadt("Darmstadt",49.878708,8.646927);
	CPOI Heid(TOURISTIC, "Heidelberg", "The History", 49.3988 ,8.6724);
	CPOI H_DA(UNIVERSITY, "H_DA","University of Applied Sciences in Darmstadt",49.8673,8.6382);


	CWpDatabase db;
	CPoiDatabase pb;

	db.addData(amsterdam);
	db.addData(darmstadt);

	pb.addData(Heid);
    pb.addData(H_DA);



	Test.setMediaName("Database");
	Test.readData(db,pb,REPLACE);
	//Test.writeData(db,pb);

	db.PrintAllData();
	pb.PrintAllData();


#endif
	return 0;
}

