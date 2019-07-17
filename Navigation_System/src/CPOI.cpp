
/*Include Standard Libraries here*/
#include<iostream>
#include<string>
using namespace std;

/*Include user Libraries here*/
#include "CPOI.h"
#include "CWaypoint.h"

/*
 * Constructor  --> CPOI(t_poi type, std::string name, std::string description, double latitude, double longitude)
 * Description  --> Set Values for all the attributes of class CPOI
 * @param input --> t_poi  : type of destination
 *                  string : name
 *                  string : Description of the place
 *                  double : latitude
 *                  double : longitude
 */
CPOI::CPOI(t_poi type, std::string name, std::string description, double latitude, double longitude)
{
	m_type           = type;
	m_description    = description;
	set(name,latitude,longitude);

	// To test the Constructor
	//cout << name<<": "<<m_type<<": "<< m_description << ": at  " << latitude <<" lat "<< longitude << " long" << endl;
}

/*
 * Function  --> print()
 * Description  --> To print name, description,type, latitude and longitude of point of interest
 * @param input --> NONE
 * @param output --> NONE
 */
void CPOI::print(ostream& output,int format) const
{
	CWaypoint::print(output,format);
	switch(m_type)
	{
	case DEFAULT:
		output<<"Default: "<<endl;
		break;
	case RESTAURANT:
		output<<"Restaurant: "<<endl;
		break;
	case TOURISTIC:
		output<<"Tourist: "<<endl;
		break;
	case GASSTATION:
		output<<"Gas station: "<<endl;
		break;
	case UNIVERSITY:
		output<<"University: "<<endl;
		break;
	default:
		output<<"Invlaid type"<<endl;
	}
	output<<m_description;
}

/**
 * operator <<
 * Description --> prints CPOI to the output
 * @param input --> ostream   : output container
 *                  CWaypoint : pPoi
 * @param output--> ostream   : output
 */
ostream& operator<<(ostream& output, const CPOI& pPoi)
{
	pPoi.print(output,MMSS);
	return output;
}

/*
 * Constructor  --> getAllDataByReference(std::string& name, double & latitude, double & longitude, t_poi& type, int description)
 * Description  --> To get the name, latitude, longitude, POI type , description
 *                  of the point of interest.
 * @param input --> t_poi  : type of destination
 *                  string : name
 *                  string : Description of the place
 *                  double : latitude
 *                  double : longitude
 * @param output --> NONE
 */
void CPOI::getAllDataByReference(std::string& name, double & latitude, double & longitude, t_poi& type, std::string& description)
{

	name         = CWaypoint::getName();          //To get name
	latitude     = CWaypoint::getLatitude();      //To get Latitude
	longitude    = CWaypoint::getLongitude();     //To get Longitude
	type         = m_type;
	description  = m_description;

	// To test getAllDataByReference
	/*CWaypoint::print(DEGREE);
	cout<<type<<": "<<description<<endl;*/

}

/*
 * Function     --> getType()
 * Description  --> To get type of POI
 * @param input --> NONE
 * @param output --> NONE
 */
string CPOI::getType() const
{
	switch(m_type)
		{
		case RESTAURANT: return  "RESTAURANT"; break;
		case TOURISTIC:  return "TOURISTIC"; break;
		case GASSTATION:  return "GASSTATION"; break;
		case UNIVERSITY:  return "UNIVERSITY"; break;
		default: return "default";
		}
}

/*
 * Function     --> getDescription()
 * Description  --> To get description of POI
 * @param input --> NONE
 * @param output --> NONE
 */
string CPOI::getDescription() const
{
   return this->m_description;
}

