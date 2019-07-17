
#ifndef CWAYPOINT_H
#define CWAYPOINT_H

#define DEGREE 1
#define MMSS 2


class CWaypoint
{
	/**
	 * operator <<
	 * Description --> prints CWaypoint to the output
	 * @param input --> ostream   : output container
	 *                  CWaypoint : pWp
	 * @param output--> ostream   : output
	 */
	friend std::ostream& operator<<(std::ostream& output, const CWaypoint& pWp) ;

private:
	/*
	 * longitude of the CWaypoint object
	 */
	double m_longitude;
	/*
	 *  latitude of the CWaypoint object
	 */
	double m_latitude;
	/*
	 *  Name of the CWaypoint object
	 */
	std::string m_name;

public:
	/*
	 * Constructor    --> CWaypoint(string name, double latitude, double longitude)
	 * Description --> Set Values for all the attributes of class CWaypoint
	 * @param input --> string : name
	 *                  double : latitude
	 *                  double : longitude
	 */
	CWaypoint(std::string name = "default", double latitude = 0, double longitude = 0);

	/*
	 * Destructor    --> ~CWaypoint()
	 * Description   --> To destroy all dynamic arrays( virtual: To create polymorphic
	 *                   design and use dynamic castings)
	 * @param input  --> NONE
	 */
	virtual ~CWaypoint();
	/*
	 * Function    --> set(string name, double latitude, double longitude)
	 * Description --> Set Values for attributes Name, Longitude, Latitude and Set
	 *                 default values in case of invalid attributes
	 * @param input --> string : name
	 *                  double : latitude
	 *                  double : longitude
	 * @param output --> NONE
	 */
	void set(std::string name, double latitude, double longitude) ;

	/*
	 * Function    --> getName()
	 * Description --> To return the name of the object
	 * @param input --> NONE
	 * @param output --> string : name
	 */
	std::string getName() const;

	/*
	 * Function    --> getLatitude()
	 * Description --> To return the latitude of the object
	 * @param input --> NONE
	 * @param output --> double: latitude
	 */
	double getLatitude() const;

	/*
	 * Function    --> getLongitude()
	 * Description --> To return the longitude of the object
	 * @param input --> NONE
	 * @param output --> double: longitude
	 */
	double getLongitude() const;

	/*
	 * Function    --> getAllDataByReference(string& name, int latitude, int longitude)
	 * Description --> Returns the name, latitude and longitude of the object
	 * @param input --> string : name
	 *                  int    : latitude
	 *                  int    : longitude
	 * @param output --> NONE
	 */
	void getAllDataByReference(std::string& name, double& latitude, double& longitude) const;

	/*
	 * Function    --> calculateDistance(const CWaypoint& wp)
	 * Description --> calculates the distance between two places
	 * @param input --> CWaypoint : Destination
	 * @param output --> double : Distance
	 */
	double calculateDistance(const CWaypoint& wp) ;

	/*
	 * Function    --> print(std::ostream& output,int format)
	 * Description --> Updates the latitude, longitude and name to output based on the
	 *                 given format either MMSS or DEGREE
	 * @param input --> int     : format
	 *                  ostream : output
	 * @param output --> NONE
	 */
	void print(std::ostream& output,int format) const;



private:
	/*
	 * Function    --> transformLongitude2degmmss(int &deg, int &mm, int &ss)
	 * Description --> Converts Decimal value of longitude to degree, minutes and seconds format
	 * @param input --> int : degree
	 *                  int : minutes
	 *                  int : seconds
	 * @param output --> NONE
	 */
	void transformLongitude2degmmss(int &deg, int &mm, int &ss) const;

	/*
	 * Function    --> transformLatitude2degmmss(int &deg, int &mm, int &ss)
	 * Description --> Converts Decimal value of latitude to degree, minutes and seconds format
	 * @param input --> int : degree
	 *                  int : minutes
	 *                  int : seconds
	 * @param output --> NONE
	 */
	void transformLatitude2degmmss(int &deg, int &mm, int &ss) const;

};
/********************
 **  CLASS END
 *********************/
#endif /* CWAYPOINT_H */
