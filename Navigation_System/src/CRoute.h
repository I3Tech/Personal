
#ifndef CROUTE_H_
#define CROUTE_H_

//standard libraries
#include <list>
#include <memory>
#include <vector>

//User libraries
#include "CPOI.h"
#include "CPoiDatabase.h"
#include "CWpDatabase.h"
#include "CJsonPersistence.h"

class CWaypoint;

class CRoute {
private:
	 std::list<CWaypoint*> m_Route;
	/**
	 * @link aggregation
	 * @clientCardinality 1
	 * Address to the collection of all Waypoints
	 * @supplierCardinality 1
	 */

	CPoiDatabase* m_pPoiDatabase;
	/**
	 * @link aggregation
	 * @clientCardinality 1
	 * Address to the collection of all POIs
	 * @supplierCardinality 1
	 */
	CWpDatabase* m_pWpDatabase;

public:
	/*
	 * Constructor  --> CRoute()
	 * Description  --> To initialize all member variables of class CRoute
	 * @param input --> NONE
	 * @param output--> NONE
	 */
	CRoute();

	/*
	 * Function  --> ~CRoute()
	 * Description  --> To clear any dynamic array created
	 * @param input --> NONE
	 * @param output--> NONE
	 */
	~CRoute();

	/*
	 * Copy Constructor  --> CRoute(CRoute const& origin)
	 * Description  --> To copy the "origin" of type CRoute to "this" object with a deep copy
	 * @param input --> CRoute  : origin
	 * @param output--> NONE
	 */
	CRoute(CRoute const& origin);

	/*
	 * Function  --> getDistanceNextPoi(CWaypoint const& wp, CPOI& poi)
	 * Description  --> To Calculate distance between waypoint and next immediate point of interest
	 * @param input --> CWaypoint  : waypoint
	 *                  CPOI       : poi
	 * @param output--> double     : Distance
	 */
	double getDistanceNextPoi(CWaypoint const& wp, CPOI& poi);

	/*
	 * Function     --> connectToPoiDatabase(CPoiDatabase* pPoiDB)
	 * Description  --> To copy the address of POI Database
	 * @param input --> CPoiDatabase : pointer to POI Database
	 * @param output--> NONE
	 */
	void connectToPoiDatabase(CPoiDatabase* pPoiDB);

	/*
	 * Function     --> connectToWpDatabase(CWpDatabase* pWpDB)
	 * Description  --> To copy the address of Waypoint Database
	 * @param input --> CWpDatabase : pointer to Waypoint DB
	 * @param output--> NONE
	 */
	void connectToWpDatabase(CWpDatabase* pWpDB);

	/*
	 * Function     --> addWaypoint(std::string name)
	 * Description  --> To add waypoint to the route
	 * @param input --> string : name of the waypoint
	 * @param output--> NONE
	 */
	void addWaypoint(std::string name);

	/*
	 * Function     --> addPoi(std::string namePoi, std::string afterWp)
	 * Description  --> To add waypoint to the route
	 * @param input --> string     : name of the POI
	 *                  string     : name of the Waypoint
	 * @param output--> NONE
	 */
	void addPoi(std::string namePoi, std::string afterWp );

	/*
	 * Function  --> print()
	 * Description  --> To print all the waypoints and POI in the route
	 * @param input --> NONE
	 * @param output--> NONE
	 */
	void print();

	/**
	 * operator +=
	 * Description --> Search Waypoint and/or POI with name and add to "this" Route
	 *                 If POI and Waypoint exists with same name add Waypoint first
	 *                 and then add POI
	 * @param input --> string : name
	 * @param output--> NONE
	 */
	void operator+=(std::string name);

	/**
	 * operator +
	 * Description --> concatenates contents of Route with this if
	 *                 both Route and 'this' are connected to same databases
	 * @param input --> CRoute : Route
	 * @param output--> CRoute : concatenated Route
	 */
	CRoute operator+(const CRoute& Route) ;

	/**
	 * operator =
	 * Description --> Assigns all the attributes of input Route to 'this' and return
	 *                 'this' Route
	 * @param input --> CRoute : Route
	 * @param output--> CRoute : Duplicate of Route
	 */
	CRoute operator=(const CRoute& m_CRoute) ;

	/**
	 * function --->  getRoute()
	 * Description --> To read the list of the route
	 * @param input --> NONE
	 * @param output--> list : My route
	 */
	const std::vector<const CWaypoint*> getRoute() ;
};

#endif /* CROUTE_H_ */
