/*Include Standard Libraries here*/
#include<iostream>
#include <string.h>
using namespace std;

/*Include Standard Libraries here*/
#include "CGPSSensor.h"
#include "CWaypoint.h"



/*
 * Constructor    --> CGPSSensor
 * Description --> No parameters to initialize. Do nothing
 * @param input : NONE
 * @param output: NONE
 */
CGPSSensor::CGPSSensor()
{

}

/*
 * Function    --> getCurrentPosition()
 * Description --> To get the current position ( latitude and longitude) of a place
 *                 by the user
 * @param input : NONE
 * @param output: CWaypoint -> Current Position
 */
CWaypoint CGPSSensor::getCurrentPosition()
{

    double lat =0;double longi=0;
    string name="My_position";

	cout<<"Please Enter the latitude of current position:"<<endl;
	cin >> lat;

	cout<<"Please Enter the longitude of current position:"<<endl;
	cin >> longi;

	cout << "Current Location is on Latitude: "<<lat << " and Longitude: "<<longi<<endl;
	return CWaypoint(name,lat,longi);
}
