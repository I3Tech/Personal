
//System Include Files
#include<stdlib.h>
#include<iostream>
#include<string>
using namespace std;


//Own Include Files
#include "CWpDatabase.h"
#include "CWaypoint.h"


//Method Implementations
/*
 * Constructor    --> CWpDatabase
 * Description    --> Initialize attributes of class CWpDatabase
 * @param input : NONE
 * @param output: NONE
 */
CWpDatabase::CWpDatabase()
{

}

/*
 * Function --> addWaypoint(CWaypoint const& wp)
 * Description --> To Creat a database for Waaypoints and store one Waypoint every time
 * @param input : CWaypoint : Waypoint(wp)
 * @param output: NONE
 */
void CWpDatabase::addWaypoint(CWaypoint const & wp)
{
	// inserting CWaypoint to m_WP
	CDatabase::addData(wp);

}


/*
 * Function  --> getpointerToWaypoint(std::string name)
 * Description  --> To get Waypoint from the database by name
 * @param input --> string  : name
 * @param output--> CWaypoint    : address of Waypoint
 */
CWaypoint* CWpDatabase::getpointerTowaypoint(std::string name)
{
	return CDatabase::getpointerToData(name);
}

/*
 * Function  --> print()
 * Description  --> To print the waypoint
 * @param input --> NONE
 * @param output--> NONE
 */
void CWpDatabase::printaAllWpinDb()
{
	CDatabase::PrintAllData();
}

/*
 * Function     --> printWaypoint(std::ostream& storage)
 * Description  --> To print all attributes to storage file
 * @param input --> Ostream : storage
 * @param output--> NONE
 */
void CWpDatabase::printWaypoint(std::ostream& storage) const
{
	//TODO: Change this

}

/*
 * Function     --> emptyWpContainer()
 * Description  --> To clear WP database
 * @param input --> NONE
 * @param output--> NONE
 */
void CWpDatabase::emptyWpContainer()
{
	CDatabase::emptyDataContainer();
}
