
//System Include Files
#include<iostream>
#include <string.h>
using namespace std;

//Own Include Files
#include "CNavigationSystem.h"
#include "CGPSSensor.h"
#include "CPoiDatabase.h"
#include "CRoute.h"


//Method Implementations

/*
 * Constructor  --> CNavigationSystem()
 * Description  --> Print welcome message
 * @param input --> NONE
 * @param output--> NONE
 */
CNavigationSystem::CNavigationSystem()
{
	cout << "Welcome to Navigation System" << endl;


}

/*
 * Function  --> run()
 * Description  --> To run entire Navigation system: To enter and print route, To get Current location
 *                  and to print the distance
 * @param input --> NONE
 * @param output--> NONE
 */
void CNavigationSystem::run()
{
	enterRoute();
	printRoute();
	printDistanceCurPosNextPoi();
}

/*
 * Function  --> enterRoute()
 * Description  --> 1)To input the route that includes waypoints and POIS
 *                  2)To connect the POI database
 * @param input --> NONE
 * @param output--> NONE
 */
void CNavigationSystem::enterRoute()
{
	/*
	CPOI Heid(TOURISTIC, "Heidelberg", "The History", 49.3988 ,8.6724);
	CPOI H_DA(UNIVERSITY, "H_DA","University of Applied Sciences in Darmstadt",49.8673,8.6382);
	CPOI Sar(RESTAURANT, "Saravana Bhavan","South Indian style restaurant in Frankfurt ",50.11552, 8.68417);
	CPOI Frank(TOURISTIC, "Frankenstein Burg", "Frankenstein: The dead man...!! ", 49.4384 ,7.9788);
	CPOI TUD(UNIVERSITY, "TUD","Technical University Darmstadt",49.8748,8.6561);
	CPOI Lah(RESTAURANT, "Lahore Palace","Tasty Biriyani...!",49.8656, 8.6457);

	//To create database of POIs
	m_PoiDataBase.addPoi(Heid);
	m_PoiDataBase.addPoi(H_DA);
	m_PoiDataBase.addPoi(Sar);
	m_PoiDataBase.addPoi(Frank);
	m_PoiDataBase.addPoi(TUD);
	m_PoiDataBase.addPoi(Lah);


	//Waypoints
	CWaypoint Mysore("Mysore",12.311827,76.652985);
	CWaypoint Banglore("Banglore",13.006752,77.561737);
	CWaypoint Manglore("Manglore",12.9141,74.8560);
	CWaypoint Chikmaglore("Chikmaglore",13.3153,75.7754);

	//To connect database
	m_Route.connectToPoiDatabase(&m_PoiDataBase);

	//To add waypoints
	m_Route.addWaypoint(Mysore);
	m_Route.addWaypoint(Banglore);
	m_Route.addWaypoint(Manglore);
	//m_Route.addWaypoint(Chikmaglore); To test Max value

	//To add POIs
	m_Route.addPoi("Heidelberg");
	m_Route.addPoi("H_DA");
	m_Route.addPoi("Saravana Bhavan");
	//m_Route.addPoi("Radisson Blu"); To test max value
	 *
	 */

}

/*
 * Function  --> enterRoute()
 * Description  --> To print all the waypoints and POIs in the route
 * @param input --> NONE
 * @param output--> NONE
 */
void CNavigationSystem::printRoute()
{

	//cout << endl<<"Our route has: 3 Waypoints and 3 Point of Interests " << endl;
	//m_Route.print();

}

/*
 * Function  --> printDistanceCurPosNextPoi()
 * Description  --> To get Current location and to calculate the distance between '
 *                  current location and the nearest poi
 * @param input --> NONE
 * @param output--> NONE
 */
void CNavigationSystem::printDistanceCurPosNextPoi()
{
	/*
	CWaypoint myWp;
	CPOI Nearest_Poi;
	double distance=0;

	//To get current location
	myWp     = m_GPSSensor.getCurrentPosition();
	distance = m_Route.getDistanceNextPoi(myWp,Nearest_Poi);

	cout <<endl<< "Nearest Point of Interest is at: " << distance << " km"<<endl;
	cout << endl<<"Point of Interest is: "<< endl << endl;
	Nearest_Poi.print();
	*/
}

