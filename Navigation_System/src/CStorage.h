
#ifndef CSTORAGE_H_
#define CSTORAGE_H_

//user libraries here
#include "CPersistentStorage.h"


/*
 * Function     --> getParameterCount(std::string Line, char delim)
 * Description  --> To get number of parameters in a given line seperated
 *                  by , or ;
 * @param input --> string : Line
 *                  char   : Deliminator
 * @param output --> int   : Number of parameters
 */

int getParameterCount(std::string Line, char delim);

/*
 * Function     --> commaToPoint(std::string param,int LineNumber,std::string fileName)
 * Description  --> Error handling: If comma is used instead of decimal point, replace the
 *                  comma with decimal point in latitude and longitude and display warning
 * @param input --> string : Parameter ( latitude/ longitude)
 *                  int    : Line number
 *                  string : File name
 * @param output --> string   : Rectified parameter (Latitude / Longitude)
 */
std::string commaToPoint(std::string param,int LineNumber,std::string fileName);

/*
 * Function     --> getDelim(std::string line, int max_delim)
 * Description  --> To get the deliminator (;/,)
 * @param input --> string : Line
 *                  int    : Maximum allowed deliminator
 * @param output --> char  : Deliminator
 */
char getDelim(std::string line, int max_delim);

/*
 * Function     --> getErrText(const std::string& param)
 * Description  --> To know if text is seen in the place of latitude and
 *                  longitude where numbers are expected.
 * @param input --> string : Parameter
 * @param output --> bool  : Error status
 */
bool getErrText(std::string& param);

class CStorage
{
private:
	std::string m_Wpstorage;
	std::string m_PoiStorage;

public:


	/*
	 * Constructor    --> CStorage
	 * Description --> Initialize attributes of class CStorage
	 * @param input : NONE
	 * @param output: NONE
	 */
	CStorage();

	/*
	 * Constructor    --> ~CStorage
	 * Description --> destroys dynamic arrays if any
	 * @param input : NONE
	 * @param output: NONE
	 */
	virtual ~CStorage();

	/**
	 * Set the name of the media to be used for persistent storage.
	 * The exact interpretation of the name depends on the implementation
	 * of the component.
	 *
	 * @param name the media to be used
	 */
	void setMediaName(std::string name);
	/**
	 * Write the data to the persistent storage.
	 *
	 * @param waypointDb the data base with way points
	 * @param poiDb the database with points of interest
	 * @return true if the data could be saved successfully
	 */
	bool writeData (const CWpDatabase& waypointDb,const CPoiDatabase& poiDb);

	/**
	 * Fill the databases with the data from persistent storage. If
	 * merge mode is MERGE, the content in the persistent storage
	 * will be merged with any content already existing in the data
	 * bases. If merge mode is REPLACE, already existing content
	 * will be removed before inserting the content from the persistent
	 * storage.
	 *
	 * @param waypointDb the the data base with way points
	 * @param poiDb the database with points of interest
	 * @param mode the merge mode
	 * @return true if the data could be read successfully
	 */
	bool readData (CWpDatabase& waypointDb, CPoiDatabase& poiDb,MergeMode mode);
};

#endif /* CSTORAGE_H_ */
