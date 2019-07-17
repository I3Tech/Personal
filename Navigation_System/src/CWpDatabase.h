

#ifndef CWPDATABASE_H
#define CWPDATABASE_H

//standard libraries
#include <map>

//User Libraries
#include "CWaypoint.h"
#include "CDatabase.h"


class CWpDatabase : public CDatabase<std::string, CWaypoint>
{
private:
	/**
	 * @link aggregation
	 * @clientCardinality 1
	 * @supplierCardinality 0..*
	 */
	//std::map<std::string,CWaypoint> m_WP;

public:


	/*
	 * Constructor    --> CWpDatabase
	 * Description --> Initialize attributes of class CWpDatabase
	 * @param input : NONE
	 * @param output: NONE
	 */
	CWpDatabase();

	/*
	 * Function --> addWaypoint(CWaypoint const& wp)
	 * Description --> To Creat a database for Waypoints and store one Waypoint every time
	 * @param input : CWaypoint : wp
	 * @param output: NONE
	 */
	void addWaypoint(CWaypoint const & wp);

	/*
	 * Function  --> getpointerToWaypoint(std::string name)
	 * Description  --> To get Waypoint from the database by name
	 * @param input --> string  : name
	 * @param output--> CWaypoint    : address of Waypoint
	 */
	CWaypoint* getpointerTowaypoint(std::string name);

	/*
	 * Function  --> printaAllWpinDb()
	 * Description  --> To print the waypoint in DB
	 * @param input --> NONE
	 * @param output--> NONE
	 */
	void printaAllWpinDb();

	/*
	 * Function     --> printWaypoint(std::ostream& storage)
	 * Description  --> To print all attributes to storage file
	 * @param input --> Ostream : storage
	 * @param output--> NONE
	 */
	void printWaypoint(std::ostream& storage) const;

	/*
	 * Function     --> emptyWpContainer()
	 * Description  --> To clear WP database
	 * @param input --> NONE
	 * @param output--> NONE
	 */
	void emptyWpContainer() ;
};
/********************
 **  CLASS END
 *********************/
#endif /* CWPDATABASE_H */
