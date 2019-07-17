

//Standard libraries here
#include<iostream>
#include<string>
#include <limits>
#include <cstddef>
using namespace std;

//User  libraries here
#include "CRoute.h"
#include "CWaypoint.h"
#include "CPoiDatabase.h"
#include "CPOI.h"
#include "CWpDatabase.h"

// User definitions
#define ZERO 0


/*
 * Constructor  --> CRoute()
 * Description  --> To initialize all member variables of class CRoute
 * @param input --> NONE
 * @param output--> NONE
 */
CRoute::CRoute( )
{
	this->m_Route.clear();
	this->m_pPoiDatabase = NULL;
	this->m_pWpDatabase = NULL;

#if 0
	//Test Constructor
	cout<< m_pPoiDatabase << endl;
	cout<< m_pWpDatabase <<endl;
#endif
}

/*
 * Function     --> connectToPoiDatabase(CPoiDatabase* pPoiDB)
 * Description  --> To copy the address of POI Database
 * @param input --> CPoiDatabase : pointer to POI Database
 * @param output--> NONE
 */
void CRoute::connectToPoiDatabase(CPoiDatabase* pPoiDB)
{
	if(pPoiDB!= NULL)
	{
		cout << "POI DB connection established"<<endl;
		m_pPoiDatabase = pPoiDB;

		//To test
		//cout << "Address copied: "<< m_pPoiDatabase<<endl;
	}
	else
	{
		cout << "could not connect POI Database : No values found" << endl;
	}
}

/*
 * Function     --> connectToWpDatabase(CWpDatabase* pWpDB)
 * Description  --> To copy the address of Waypoint Database
 * @param input --> CWpDatabase : pointer to Waypoint DB
 * @param output--> NONE
 */
void CRoute::connectToWpDatabase(CWpDatabase* pWpDB)
{
	if(pWpDB!= NULL)
	{
		cout << "WP DB connection established"<<endl;
		m_pWpDatabase = pWpDB;

		//To test
		//cout << "Address copied: "<< m_pWpDatabase<<endl;
	}
	else
	{
		cout << "could not connect Waypoint Database : No values found" << endl;
	}
}

/*
 * Function     --> addWaypoint(std::string name)
 * Description  --> To add waypoint to the route
 * @param input --> string : name of the waypoint
 * @param output--> NONE
 */
void CRoute::addWaypoint(std::string name)
{
	// database pointing to null
	if(m_pWpDatabase == NULL)
	{
		cout << " Error...!! WP Database not connected"<<endl;
	}
	else
	{
		//Requested name exists in Waypoint database
		if(m_pWpDatabase->getpointerTowaypoint(name) != NULL)
		{
			m_Route.push_back(m_pWpDatabase->getpointerTowaypoint(name));

			//To test
			/*vector<CWaypoint*>::iterator tst;
			tst = m_Route.begin();
			(*tst)->print(2);
			 */
		}
		else
		{
			cout << "WP by name " << name <<" is not in the pool. Waypoint not added" << endl;
		}
	}
}


/*
 * Function     --> addPoi(std::string namePoi, std::string afterWp)
 * Description  --> To add waypoint to the route
 * @param input --> string     : name of the POI
 *                  string     : name of the Waypoint
 * @param output--> NONE
 */
void CRoute::addPoi(std::string namePoi, std::string afterWp)
{
	list<CWaypoint*>::iterator lv_index,temp_index;
	bool lb_Err = false;

	// database pointing to null
	if(m_pPoiDatabase == NULL)
	{
		cout << " Error...!! POI Database not connected"<<endl;
	}

	else{
		//Requested name exists in Waypoint database
		if(m_pPoiDatabase->getpointerToPoi(namePoi) != NULL)
		{
			for(lv_index = m_Route.begin();lv_index != m_Route.end();lv_index++)
			{
				//If Waypoint exists
				if(afterWp == (*lv_index)->getName())
				{
					temp_index = lv_index;
					temp_index++;
					lb_Err = true;
				}
			}
			// display error if name not found in Waypoint DB
			if(lb_Err)
			{
				m_Route.insert(temp_index,m_pPoiDatabase->getpointerToPoi(namePoi));
				lb_Err = false;
				//cout << "Congrats....!!" << endl;
			}
			else
			{
				cout << "Waypoint with name: " << afterWp << " does not exist in DB. POI not added"<<endl;
			}
		}
		else
		{
			cout << "POI with name: "<< namePoi << " does not exist in DB. POI not added" << endl;
		}
	}

}

/*
 * Function  --> getDistanceNextPoi(CWaypoint const& wp, CPOI& poi)
 * Description  --> To Calculate distance between waypoint and next immediate point of interest
 * @param input --> CWaypoint  : waypoint
 *                  CPOI       : poi
 * @param output--> double     : Distance
 */
double CRoute::getDistanceNextPoi(CWaypoint const& wp, CPOI& poi)
{

	// NOT TO BE IMPLEMENTED IN THIS ASSIGNMENT
	list<CWaypoint* >::iterator dist;
	double ld_distance  = 0;
	double ld_temp_dist = std::numeric_limits<double>::max();

	for (dist = m_Route.begin(); dist!=m_Route.end(); dist++)
	{
		CPOI* pPoi = dynamic_cast <CPOI*> (*dist);
		if( pPoi != NULL)
		{
			ld_distance = pPoi->calculateDistance(wp);
			if(ld_temp_dist>ld_distance)
			{
				ld_temp_dist=ld_distance;
				poi = *pPoi;
			}
		}
	}
	return ld_temp_dist;
}

/*
 * Function  --> print()
 * Description  --> To print all the waypoints and POI in the route
 * @param input --> NONE
 * @param output--> NONE
 */
void CRoute::print()
{
	list<CWaypoint* >::iterator route;

	cout <<endl<< "Waypoints and POIs in the route are"<<endl << endl;

	for (route = m_Route.begin(); route!=m_Route.end(); route++)
	{
		//to check if element is POI or Waypoint
		CPOI* pPoi = dynamic_cast <CPOI*> (*route);

		//CWaypoint print
		if (pPoi == NULL)
		{
			/*route is an iterator i.e pointer to element of type CWaypoint*
			dereferencing it twice will be of type CWaypoint which is
			printed using << overloaded operator*/
			cout << (**route) << endl;
		}
		//CPOI print
		else
		{
			cout << (*pPoi) << endl<<endl;
		}
	}

}

/*
 * Function  --> ~CRoute()
 * Description  --> To clear any dynamic array created
 * @param input --> NONE
 * @param output--> NONE
 */
CRoute::~CRoute()
{

}

/**
 * operator +=
 * Description --> Search Waypoint and/or POI with name and add to "this" Route
 *                 If POI and Waypoint exists with same name add Waypoint first
 *                 and then add POI
 * @param input --> string : name
 * @param output--> NONE
 */
void CRoute::operator +=(string name)
																																		{
	CPOI* pPoi     = m_pPoiDatabase->getpointerToPoi(name);
	CWaypoint* pWp = m_pWpDatabase->getpointerTowaypoint(name);

	//Display error if any of the DB not exists
	if(pPoi==NULL) // use pPoi to compare
	{
		cout << "POI Database not connected" << endl <<endl;
	}
	else if(pWp==NULL) // use pWp to compare
	{
		cout << "WP Database not connected" << endl <<endl;
	}
	else
	{
		//Name exists in both Waypoint and POI DB
		if((pPoi != NULL) && (pWp != NULL))
		{
			m_Route.push_back(pWp);
			m_Route.push_back(pPoi);
		}
		// waypoint name
		else if((pPoi == NULL) && (pWp != NULL))
		{
			m_Route.push_back(pWp);
		}
		//POI name
		else if((pPoi != NULL) && (pWp == NULL))
		{
			m_Route.push_back(pPoi);
		}
		//name not found
		else if((pPoi == NULL) && (pWp == NULL))
		{
			cout<<endl<<"No POI or Waypoint of name: "<<name<<" exists"<<endl;
		}

		else
		{
			//do nothing
		}
	}
																																		}

/**
 * operator +
 * Description --> concatenates contents of Route with this if
 *                 both Route and 'this' are connected to same databases
 * @param input --> CRoute : Route
 * @param output--> CRoute : concatenated Route
 */
CRoute CRoute::operator+(const CRoute& Route)
{
	//if both DBs are connected to same DBs
	if((Route.m_pPoiDatabase == this->m_pPoiDatabase)&&(Route.m_pWpDatabase == this->m_pWpDatabase))
	{
		list<CWaypoint*>::const_iterator i;
		// contents of 'this' route

		for(i = Route.m_Route.begin(); i != Route.m_Route.end(); i++)
		{
			this->m_Route.push_back(*i);
		}


		return *this;
	}
	return *this;
}

/*
 * Copy Constructor  --> CRoute(CRoute const& origin)
 * Description  --> To copy the "origin" of type CRoute to "this" object with a deep copy
 * @param input --> CRoute  : origin
 * @param output--> NONE
 */
CRoute::CRoute(CRoute const& origin)
{
	list<CWaypoint*>::const_iterator i;
	//To clear existing container
	this->m_Route.clear();
	//copy all elements of m_CRoute to this
	for(i = origin.m_Route.begin(); i != origin.m_Route.end(); i++)
	{
		this->m_Route.push_back(*i);
	}
	// copy also the POI and Waypoint addresses
	this->m_pWpDatabase  = origin.m_pWpDatabase;
	this->m_pPoiDatabase = origin.m_pPoiDatabase;

}


/**
 * operator =
 * Description --> Assigns all the attributes of input Route to 'this' and return
 *                 'this' Route
 * @param input --> CRoute : Route
 * @param output--> CRoute : Duplicate of Route
 */
CRoute CRoute::operator=(const CRoute& m_CRoute)
{
	list<CWaypoint*>::const_iterator i;
	//To clear existing container
	this->m_Route.clear();
	//copy all elements of m_CRoute to this
	for(i = m_CRoute.m_Route.begin(); i != m_CRoute.m_Route.end(); i++)
	{
		this->m_Route.push_back(*i);
	}
	// copy also the POI and Waypoint addresses
	this->m_pWpDatabase  = m_CRoute.m_pWpDatabase;
	this->m_pPoiDatabase = m_CRoute.m_pPoiDatabase;
	return *this;
}

/**
 * function --->  getRoute()
 * Description --> To read the list of the route
 * @param input --> NONE
 * @param output--> list : My route
 */
const vector<const CWaypoint*> CRoute::getRoute()
{
   vector<const CWaypoint*> Route(this->m_Route.begin(),this->m_Route.end());
   return Route;
}
