
/*Include Standard Libraries here*/
#include <iostream>
#include <math.h>
#include <string>
using namespace std;


/*Include User Libraries here*/
#include "CWaypoint.h"

/*macro definitions*/
#define LATITUDE_MAX_DEG 90
#define LATITUDE_MIN_DEG -90
#define LONGITUDE_MAX_DEG 180
#define LONGITUDE_MIN_DEG -180
#define EARTH_RADIUS 6378.17
#define DEFAULT_VALUE 0
#define MIN_SEC_SCALE 60
#define DEG_TO_RAD 57.3248  //Value for 180/Pi


//#define SHOWADDRESS

/*
 * Constructor    --> CWaypoint(string name, double latitude, double longitude)
 * Description --> Set Values for all the attributes of class CWaypoint
 * @param input --> string : name
 *                  double : latitude
 *                  double : longitude
 */
CWaypoint::CWaypoint(string name, double latitude, double longitude)
{
	set(name,latitude,longitude);

#ifdef SHOWADDRESS
	//To print address of the object
	cout << "Address of the object"<<" "<<name<<" "<<"created is"<<" "<<this<<endl;

	//To print address and value of latitude
	cout << "Address of Longitude is" <<" "<<&m_longitude <<" "<<"and it's value is"<<" "<<m_longitude<< ". Size: "<<sizeof(m_longitude)<<endl;

	//To print address and value of longitude
	cout << "Address of Latitude is" <<" "<<&m_latitude <<" "<<"and it's value is"<<" "<<m_latitude<<". Size: "<<sizeof(m_latitude)<<endl;

	//To print address and value of name
	cout << "Address of Name is" <<" "<<&m_name <<" "<<"and it's value is"<<" "<<m_name<<". Size: "<<sizeof(m_name)<<endl;

	//To display total memory occupied by each object
	cout<< "Total memory occupied by this object is"<<" "<< sizeof(m_latitude)+sizeof(m_longitude)+sizeof(m_name)<< endl;
#endif
#ifndef SHOWADDRESS
	//do nothing
#endif

}

/*
 * Destructor    --> ~CWaypoint()
 * Description   --> To destroy all dynamic arrays( virtual: To create polymorphic
 *                   design and use dynamic castings)
 * @param input  --> NONE
 */
CWaypoint::~CWaypoint()
{

}


/*
 * Function    --> set(string name, double latitude, double longitude)
 * Description --> Set Values for attributes Name, Longitude, Latitude and Set
 *                 default values in case of invalid attributes
 * @param input --> string : name
 *                  double : latitude
 *                  double : longitude
 * @param output --> NONE
 */
void CWaypoint::set(string name, double latitude, double longitude)
{
	/* Set default values to latitude and longitude if invalid values are given*/
	if((latitude>=LATITUDE_MAX_DEG)||(latitude<=LATITUDE_MIN_DEG)||(longitude<=LONGITUDE_MIN_DEG)||(longitude>=LONGITUDE_MAX_DEG))
	{
		cout << "Invalid Latitude or Longitude value" << endl << endl ;
		name      = "Default";
		latitude  = DEFAULT_VALUE;
		longitude = DEFAULT_VALUE;
	}
	else
	{
		//do nothing
	}
	//Assign good values to name,latitude and longitude
	m_name = name;
	m_latitude = latitude;
	m_longitude = longitude;
}

/*
 * Function    --> getName()
 * Description --> To return the name of the object
 * @param input --> NONE
 * @param output --> string : name
 */

string CWaypoint::getName() const
{
	return m_name;
}

/*
 * Function    --> getLatitude()
 * Description --> To return the latitude of the object
 * @param input --> NONE
 * @param output --> double: latitude
 */
double CWaypoint::getLatitude() const
{
	return m_latitude;
}

/*
 * Function    --> getLongitude()
 * Description --> To return the longitude of the object
 * @param input --> NONE
 * @param output --> double: longitude
 */
double CWaypoint::getLongitude() const
{
	return m_longitude;
}

/*
 * Function    --> getAllDataByReference(string& name, int latitude, int longitude)
 * Description --> Returns the name, latitude and longitude of the calling object
 * @param input --> string : name
 *                  int    : latitude
 *                  int    : longitude
 * @param output --> NONE
 */
void CWaypoint::getAllDataByReference(string& name, double& latitude, double& longitude) const
{
	name = m_name;
	latitude = m_latitude;
	longitude = m_longitude;
}

/*
 * Function    --> calculateDistance(const CWaypoint& wp)
 * Description --> calculates the distance between two places
 * @param input --> CWaypoint : Destination
 * @param output --> double : Distance
 */
double CWaypoint::calculateDistance(const CWaypoint& wp)
{
	double ld_distance=DEFAULT_VALUE;
	//to calculate distance
	ld_distance= EARTH_RADIUS*(acos((sin(m_latitude/DEG_TO_RAD)*sin(wp.m_latitude/DEG_TO_RAD))
			+(cos(m_latitude/DEG_TO_RAD)*cos(wp.m_latitude/DEG_TO_RAD)*cos((wp.m_longitude-m_longitude)/DEG_TO_RAD))));
	//cout<< "Distance between"<<" "<<m_name<<" "<<"and"<<" "<<wp.m_name<<" "<<"is"<<" ";
	return ld_distance;
}

/*
 * Function    --> print(std::ostream& output,int format)
 * Description --> Updates the latitude, longitude and name to output based on the
 *                 given format either MMSS or DEGREE
 * @param input --> int     : format
 *                  ostream : output
 * @param output --> NONE
 */
void CWaypoint::print(ostream& output,int format) const
{
	int li_deg_lat=DEFAULT_VALUE,li_min_lat=DEFAULT_VALUE,li_sec_lat=DEFAULT_VALUE;
	int li_deg_long=DEFAULT_VALUE,li_min_long=DEFAULT_VALUE,li_sec_long=DEFAULT_VALUE;

	//Print decimal values of latitude and longitude
	if(format == DEGREE)
	{
		output<< m_name << " "<< "latitude:"<<" " <<m_latitude<<" "<< "longitude:"<<" "<<m_longitude<<endl;
	}
	//print deg min sec values of latitude and longitude
	else if(format == MMSS)
	{
		transformLatitude2degmmss(li_deg_lat,li_min_lat,li_sec_lat);
		transformLongitude2degmmss(li_deg_long,li_min_long,li_sec_long);
		output<< m_name << " " << "latitude:" << " "<< li_deg_lat <<"deg"<< " "<< li_min_lat << "min"<<" "<<li_sec_lat<<"sec"<<" ";
		output<< m_name << " " << "longitude:" << " "<< li_deg_long <<"deg"<< " "<< li_min_long << "min"<<" "<<li_sec_long<<"sec"<<endl;
	}
	else
	{
		output<< "Format is incorrect"<<endl;
	}
}

/**
 * operator <<
 * Description --> prints CWaypoint to the output
 * @param input --> ostream   : output container
 *                  CWaypoint : pWp
 * @param output--> ostream   : output
 */
ostream& operator<<(ostream& output, const CWaypoint& pWp)
{
	pWp.print(output, MMSS);
	return output;
}

/*
 * Function    --> transformLongitude2degmmss(int &deg, int &mm, int &ss)
 * Description --> Converts Decimal value of longitude to degree, minutes and seconds format
 * @param input --> int : degree
 *                  int : minutes
 *                  int : seconds
 * @param output --> NONE
 */
void CWaypoint::transformLongitude2degmmss(int &deg, int &mm, int &ss) const
{
	//convert decimal to degrees
	deg = int(m_longitude);
	//cout<<" " << deg << "deg" << endl;

	//convert decimal to minutes
	mm =  int((m_longitude - double(deg))*MIN_SEC_SCALE);

	//convert decimal to seconds
	ss = int((m_longitude - double(deg) - (double (mm))/MIN_SEC_SCALE)*MIN_SEC_SCALE*MIN_SEC_SCALE);
}

/*
 * Function    --> transformLatitude2degmmss(int &deg, int &mm, int &ss)
 * Description --> Converts Decimal value of latitude to degree, minutes and seconds format
 * @param input --> int : degree
 *                  int : minutes
 *                  int : seconds
 * @param output --> NONE
 */
void CWaypoint::transformLatitude2degmmss(int &deg, int &mm, int &ss) const
{

	//convert decimal to degrees
	deg = int(m_latitude);
	//cout<<" " << deg << "deg" << endl;

	//convert decimal to minutes
	mm =  int((m_latitude - double(deg))*MIN_SEC_SCALE);

	//convert decimal to seconds
	ss = int((m_latitude - double(deg) - (double (mm))/MIN_SEC_SCALE)*MIN_SEC_SCALE*MIN_SEC_SCALE);
}

