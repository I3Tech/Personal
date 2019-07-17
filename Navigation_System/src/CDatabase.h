
#ifndef CDATABASE_H_
#define CDATABASE_H_

//standard libraries here
#include <iostream>
#include <stdlib.h>
#include <map>

//user libraries here
#include "CPOI.h"


template <typename K, typename D>
class CDatabase {

protected:
	/*
	 * To store all data from POI database and Waypoint database
	 */
	std::map<K,D> m_DB;



public:
	/*
	 * Constructor    --> CCombinedDatabase
	 * Description --> Initialize attributes of class CCombinedDatabase
	 * @param input : NONE
	 * @param output: NONE
	 */
	CDatabase();

	/*
	 * Function --> addPoi(CPOI const& poi)
	 * Description --> To Creat a database for POIs and store one POI every time
	 * @param input : CPOI/CWaypoint : data
	 * @param output: NONE
	 */
	void addData(D const& data);

	/*
	 * Function  --> getpointerToPoi(std::string name)
	 * Description  --> To get POI from the database by name
	 * @param input --> string  : name
	 * @param output--> CPOI    : address of CPOI
	 */
	D* getpointerToData(K name);

	/*
	 * Function     --> emptyDataContainer()
	 * Description  --> To clear database
	 * @param input --> NONE
	 * @param output--> NONE
	 */
	void emptyDataContainer();

	/*
	 * Function     --> PrintAllData()
	 * Description  --> To Print database
	 * @param input --> NONE
	 * @param output--> NONE
	 */
	void PrintAllData();

	/*
	 * Function     --> getMap()
	 * Description  --> To get the map of the database
	 * @param input --> NONE
	 * @param output--> map -> Database container
	 */
	std::map<K,D> getMap() const;

	/*
	 * Destructor    --> CCombinedDatabase
	 * Description --> clears CCombinedDatabase
	 * @param input : NONE
	 * @param output: NONE
	 */
	~CDatabase();

};

/*
 * Constructor    --> CCombinedDatabase
 * Description --> Initialize attributes of class CCombinedDatabase
 * @param input : NONE
 * @param output: NONE
 */
template <typename K, typename D>
CDatabase<K,D>::CDatabase()
{
	//do nothing
}

/*
 * Function --> addPoi(CPOI const& poi)
 * Description --> To Creat a database for POIs and store one POI every time
 * @param input : CPOI/CWaypoint : data
 * @param output: NONE
 */
template<typename K, typename D>
void CDatabase<K, D>::addData(D const& data){
	//adding object to container
	m_DB.insert(std::pair<K,D>(data.getName(), data));
}

/*
 * Function  --> getpointerToPoi(std::string name)
 * Description  --> To get POI from the database by name
 * @param input --> string  : name
 * @param output--> CPOI    : address of CPOI
 */
template<typename K, typename D>
D* CDatabase<K,D>::getpointerToData(K name)
{
	D* pData=0;
	typename std::map<K, D>::iterator i;

	for (i = m_DB.begin(); i != m_DB.end(); i++)
	{
		// if key matches return POI
		if(i->first == name)
		{
			pData = &(i->second);
			return pData;
		}
	}
	return pData;
}

/*
 * Function     --> emptyDataContainer()
 * Description  --> To clear database
 * @param input --> NONE
 * @param output--> NONE
 */
template <typename K, typename D>
void CDatabase<K,D>::emptyDataContainer(){
	m_DB.clear();
}

/*
 * Function     --> PrintAllData()
 * Description  --> To Print database
 * @param input --> NONE
 * @param output--> NONE
 */
template <typename K, typename D>
void CDatabase<K,D>::PrintAllData(){
	typename std::map<K, D>::iterator it;
	for(it= m_DB.begin();it!=m_DB.end();it++)
	{
		std::cout << it->second <<  std::endl;
	}
}

/*
 * Function     --> getMap()
 * Description  --> To get the map of the database
 * @param input --> NONE
 * @param output--> map -> Database container
 */
template <typename K, typename D>
typename std::map<K,D> CDatabase<K,D>::getMap() const
{
	return m_DB;
}

/*
 * Destructor    --> CCombinedDatabase
 * Description --> clears CCombinedDatabase
 * @param input : NONE
 * @param output: NONE
 */
template <typename K, typename D>
CDatabase<K,D>::~CDatabase()
{
}





#endif /* CDATABASE_H_ */
