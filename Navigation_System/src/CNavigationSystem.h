
#ifndef CNAVIGATIONSYSTEM_H_
#define CNAVIGATIONSYSTEM_H_

// User libraries here
#include "CGPSSensor.h"
#include "CRoute.h"
#include "CPoiDatabase.h"

class CNavigationSystem
{
private:
	/*
	 * Current position
	 */
    /**
     * @link aggregationByValue
     * @clientCardinality 1
     * @supplierCardinality 1 
     */
	CGPSSensor m_GPSSensor;
	/*
	 * Current route
	 */
    /**
     * @link aggregationByValue
     * @clientCardinality 1
     * @supplierCardinality 1 
     */
	CRoute m_Route;
	/*
	 * POI database
	 */
    /**
     * @link aggregationByValue
     * @clientCardinality 1
     * @supplierCardinality 1 
     */
	CPoiDatabase m_PoiDataBase;

public:
	/*
	 * Constructor  --> CNavigationSystem()
	 * Description  --> Print welcome message
	 * @param input --> NONE
	 * @param output--> NONE
	 */
	CNavigationSystem();

	/*
	 * Function  --> run()
	 * Description  --> To run entire Navigation system: To enter and print route, To get Current location
	 *                  and to print the distance
	 * @param input --> NONE
	 * @param output--> NONE
	 */
	void run();

	/*
	 * Function  --> enterRoute()
	 * Description  --> 1)To input the route that includes waypoints and POIS
	 *                  2)To connect the POI database
	 * @param input --> NONE
	 * @param output--> NONE
	 */
	void enterRoute();

	/*
	 * Function  --> enterRoute()
	 * Description  --> To print all the waypoints and POIs in the route
	 * @param input --> NONE
	 * @param output--> NONE
	 */
	void printRoute();

	/*
	 * Function  --> printDistanceCurPosNextPoi()
	 * Description  --> To get Current location and to calculate the distance between '
	 *                  current location and the nearest poi
	 * @param input --> NONE
	 * @param output--> NONE
	 */
	void printDistanceCurPosNextPoi();
};

#endif /* CNAVIGATIONSYSTEM_H_ */
