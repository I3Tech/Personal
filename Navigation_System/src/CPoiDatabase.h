
#ifndef CPOIDATABASE_H_
#define CPOIDATABASE_H_

/*standard libraries*/
#include <map>

/*Include User Libraries here*/
#include "CPOI.h"
#include "CDatabase.h"


//TODO: why virtual public inheritance is used?

class CPoiDatabase: public CDatabase<std::string, CPOI>
{
private:
	/**
	 * @link aggregationByValue
	 * @clientCardinality 1
	 * @supplierCardinality 0..*
	 */
	//std::map<std::string,CPOI> m_POI;



public:

	/*
	 * Constructor    --> CPoiDatabase
	 * Description --> Initialize attributes of class CPoiDatabase
	 * @param input : NONE
	 * @param output: NONE
	 */
	CPoiDatabase();

	/*
	 * Function --> addPoi(CPOI const& poi)
	 * Description --> To Creat a database for POIs and store one POI every time
	 * @param input : CPOI : poi
	 * @param output: NONE
	 */
	void addPoi(CPOI const& poi);

	/*
	 * Function  --> getpointerToPoi(std::string name)
	 * Description  --> To get POI from the database by name
	 * @param input --> string  : name
	 * @param output--> CPOI    : address of CPOI
	 */
	CPOI* getpointerToPoi(std::string name);

	/*
	 * Function  --> printAllPoiDb()
	 * Description  --> To print the waypoint in DB
	 * @param input --> NONE
	 * @param output--> NONE
	 */
	void printAllPoiDb();

	/*
	 * Function     --> printPoi(std::ostream& storage)
	 * Description  --> To print all attributes to storage file
	 * @param input --> Ostream : storage
	 * @param output--> NONE
	 */
	void printPoi(std::ostream& storage) const;

	/*
	 * Function     --> emptyPoiContainer()
	 * Description  --> To clear WP database
	 * @param input --> NONE
	 * @param output--> NONE
	 */
	void emptyPoiContainer();
};

#endif /* CPOIDATABASE_H_ */
