
/*Include Standard Libraries here*/
#include<stdlib.h>
#include<iostream>
#include<string>
using namespace std;

/*Include User Libraries here*/
#include "CPOI.h"
#include "CPoiDatabase.h"
#include "CDatabase.h"

/*Macros here*/


/*
 * Constructor    --> CPoiDatabase
 * Description --> Initialize attributes of class CPoiDatabase
 * @param input : NONE
 * @param output: NONE
 */
CPoiDatabase::CPoiDatabase()
{

}

/*
 * Function --> addPoi(CPOI const& poi)
 * Description --> To Creat a database for POIs and store one POI every time
 * @param input : CPOI : poi
 * @param output: NONE
 */
void CPoiDatabase::addPoi(CPOI const& poi)
{
	// inserting POI to m_POI
	CDatabase::addData(poi);
}

/*
 * Function  --> getpointerToPoi(std::string name)
 * Description  --> To get POI from the database by name
 * @param input --> string  : name
 * @param output--> CPOI    : address of CPOI
 */
CPOI* CPoiDatabase::getpointerToPoi(std::string name)
{
	return CDatabase::getpointerToData(name);
}


/*
 * Function  --> printAllPoiDb()
 * Description  --> To print the waypoint in DB
 * @param input --> NONE
 * @param output--> NONE
 */
void CPoiDatabase::printAllPoiDb()
{
	CDatabase::PrintAllData();
}

/*
 * Function     --> printPoi(std::ostream& storage)
 * Description  --> To print all attributes to storage file
 * @param input --> Ostream : storage
 * @param output--> NONE
 */
void CPoiDatabase::printPoi(std::ostream& storage) const
{
	//TODO: Change this

}

/*
 * Function     --> emptyPoiContainer()
 * Description  --> To clear WP database
 * @param input --> NONE
 * @param output--> NONE
 */
void CPoiDatabase::emptyPoiContainer()
{
	CDatabase::emptyDataContainer();
}
