
#ifndef CPOI_H_
#define CPOI_H_

/*Include user Libraries here*/
#include "CWaypoint.h"

typedef enum{DEFAULT,RESTAURANT,TOURISTIC,GASSTATION,UNIVERSITY}t_poi;

class CPOI: virtual public CWaypoint
{
	/**
	 * operator <<
	 * Description --> prints CPOI to the output
	 * @param input --> ostream   : output container
	 *                  CWaypoint : pPoi
	 * @param output--> ostream   : output
	 */
	friend std::ostream& operator<<(std::ostream& output, const CPOI& pPoi);
private:
	/*
	 * Type of point of interest
	 */
	t_poi m_type;
	/*
	 * description to point of interest
	 */
	std::string m_description;

public:

	/*
	 * Constructor  --> CPOI(t_poi type, std::string name, std::string description, double latitude, double longitude)
	 * Description  --> Set Values for all the attributes of class CPOI
	 * @param input --> t_poi  : type of destination
	 *                  string : name
	 *                  string : Description of the place
	 *                  double : latitude
	 *                  double : longitude
	 */
	CPOI(t_poi type=DEFAULT, std::string name="default", std::string description="Initial Description", double latitude=DEFAULT, double longitude=DEFAULT);

	/*
	 * Function    --> print(std::ostream& output,int format)
	 * Description --> Updates the latitude, longitude, name to output based
	 *                 on the given format either MMSS or DEGREE type and description
	 * @param input --> int     : format
	 *                  ostream : output
	 * @param output --> NONE
	 */
	void print(std::ostream& output,int format) const;

	/*
	 * Function  --> getAllDataByReference(std::string& name, double & latitude, double & longitude, t_poi& type, int description)
	 * Description  --> To get the name, latitude, longitude, POI type , description
	 *                  of the point of interest.
	 * @param input --> t_poi  : type of destination
	 *                  string : name
	 *                  string : Description of the place
	 *                  double : latitude
	 *                  double : longitude
	 * @param output --> NONE
	 */
	void getAllDataByReference(std::string& name, double & latitude, double & longitude, t_poi& type, std::string& description) ;

	/*
	 * Function     --> getType()
	 * Description  --> To get type of POI
	 * @param input --> NONE
	 * @param output --> string : type
	 */
	std::string getType() const;

	/*
	 * Function     --> getDescription()
	 * Description  --> To get description of POI
	 * @param input --> NONE
	 * @param output --> string : description
	 */
	std::string getDescription() const;



};

#endif /* CPOI_H_ */
