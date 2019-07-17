

#ifndef CPERSISTENTSTORAGE_H
#define CPERSISTENTSTORAGE_H

//standard libraries
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>


//user libraries
#include "CWpDatabase.h"
#include "CPoiDatabase.h"

/**
 * The mode to be used when reading the data bases (see readData).
 */
enum MergeMode { MERGE, REPLACE };

class CPersistentStorage
{
	public:
		/**
		 * Set the name of the media to be used for persistent storage.
		 * The exact interpretation of the name depends on the implementation
		 * of the component.
		 *
		 * @param name the media to be used
		 */
		virtual void setMediaName(std::string name) = 0;
		/**
		 * Write the data to the persistent storage.
		 *
		 * @param waypointDb the data base with way points
		 * @param poiDb the database with points of interest
		 * @return true if the data could be saved successfully
		 */
		virtual bool writeData (const CWpDatabase& waypointDb,const CPoiDatabase& poiDb) = 0;

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
		virtual bool readData (CWpDatabase& waypointDb, CPoiDatabase& poiDb,
				MergeMode mode) = 0;

		/**
		 * Destructor : ~CPersistentStorage()
		 * To avoid warning for using virtual functions
		 */
		virtual ~CPersistentStorage(){}
};
/********************
 **  CLASS END
 *********************/
#endif /* CPERSISTENTSTORAGE_H */
