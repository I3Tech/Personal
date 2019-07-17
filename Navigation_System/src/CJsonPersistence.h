#ifndef CJSONPERSISTENCE_H
#define CJSONPERSISTENCE_H

//User libraries here
#include "CPersistentStorage.h"

class CJsonPersistence: public CPersistentStorage
{

private:

	/* Name of the file to be operated on*/
	std::string m_fileName;

	/* output file stream*/
	std::ofstream m_myFile;

	/* input file stream*/
	std::ifstream m_iFile;


	/*
	 * Function --> writeWp(const CWaypoint Wp)
	 * Description --> write name, latitude and longitude of waypoint
	 *                 in Json format
	 * @param input : NONE
	 * @param output: CWaypoint -> waypoint
	 */
	void writeData(const CWaypoint& Wp);

	/*
	 * Function --> writePoi(const CPOI Poi)
	 * Description --> write name, latitude, longitude, type and description
	 *                 of poi in Json format
	 * @param input : NONE
	 * @param output: CPOI -> POI
	 */
	void writeData(const CPOI& Poi);

	/*
	 * Function --> writeJason(const std::map<T,U>& DbMap)
	 * Description --> manages WP and POI write to file in Json format
	 * @param input : map  -> POI/Waypoint container
	 * @param output: bool -> file write status
	 */
	template<typename T, typename U>
	bool writeJason(const std::map<T,U>& DbMap);


public:

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
/********************
 **  CLASS END
 *********************/
#endif /* CJSONPERSISTENCE_H */
