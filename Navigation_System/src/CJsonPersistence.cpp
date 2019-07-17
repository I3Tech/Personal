//System Include Files
#include<map>

//Own Include Files
#include "CJsonPersistence.h"
#include "CJsonToken.h"
#include "CJsonScanner.h"
#include "CMyStateMachine.h"

using namespace std;
using namespace APT;

#define SPACE ' '
#define DQ    '"'
#define DELIM ','


void CJsonPersistence::setMediaName(std::string name)
{
	this->m_fileName = name + ".txt";
}


bool CJsonPersistence::writeData(const CWpDatabase& waypointDb,const CPoiDatabase& poiDb)
{
	bool fileStatus = false;
	this->m_myFile.open(this->m_fileName.data());
	this->m_myFile.seekp(0);

	if(this->m_myFile.is_open())
	{
		this->m_myFile << '{' << endl << SPACE << DQ << "waypoints" << DQ <<":" << SPACE << "[" << endl;
		this->writeJason(waypointDb.getMap());
		this->m_myFile << SPACE  << "]," << endl << SPACE << DQ << "pois" << DQ <<":" << SPACE << "[" << endl;
		this->writeJason(poiDb.getMap());
		this->m_myFile << SPACE  << "]" << endl << '}';
		fileStatus = true;
	}

	this->m_myFile.close();

	return fileStatus;
}

template<typename T, typename U>
bool CJsonPersistence::writeJason(const std::map<T,U>& DbMap)
{
	unsigned int lastElementCounter=0;
	typename map<T,U>::const_iterator i;

	if(DbMap.size())
	{
		for(i= DbMap.begin(); i!= DbMap.end(); i++)
		{
			lastElementCounter++;
			this->m_myFile << SPACE << SPACE << "{" << endl;
			this->writeData(i->second);
			if(lastElementCounter == DbMap.size()) this->m_myFile << endl<< SPACE << SPACE << "}" <<endl;
			else                                   this->m_myFile << endl<< SPACE << SPACE << "},"<<endl;
		}
	}
	return true;
}


void CJsonPersistence::writeData(const CWaypoint& Wp)
{
	this->m_myFile << SPACE << SPACE << SPACE << DQ << "name"      <<DQ << ":" << SPACE << DQ << Wp.getName() << DQ  << DELIM << endl;
	this->m_myFile << SPACE << SPACE << SPACE << DQ << "latitude"  <<DQ << ":" << SPACE << Wp.getLatitude()<< DELIM << endl;
	this->m_myFile << SPACE << SPACE << SPACE << DQ << "longitude" <<DQ << ":" << SPACE << Wp.getLongitude();
}

void CJsonPersistence::writeData(const CPOI& Poi)
{
	this->m_myFile << SPACE << SPACE << SPACE << DQ << "name"      <<DQ << ":" << SPACE << DQ << Poi.getName() << DQ  << DELIM << endl;
	this->m_myFile << SPACE << SPACE << SPACE << DQ << "latitude"  <<DQ << ":" << SPACE << Poi.getLatitude() << DELIM << endl;
	this->m_myFile << SPACE << SPACE << SPACE << DQ << "longitude" <<DQ << ":" << SPACE << Poi.getLongitude()<< DELIM << endl;
	this->m_myFile << SPACE << SPACE << SPACE << DQ << "type"      <<DQ << ":" << SPACE << DQ << Poi.getType() << DQ << DELIM << endl;
	this->m_myFile << SPACE << SPACE << SPACE << DQ << "description" <<DQ << ":" << SPACE << DQ << Poi.getDescription() << DQ;
}




bool CJsonPersistence::readData(CWpDatabase& waypointDb, CPoiDatabase& poiDb,MergeMode mode)
{
	bool fileStatus = false;

	double latitude, longitude;
	string name, description, strType, DbName, AttrName;
	t_poi type;
	bool wpFlag  = false; bool poiFlag = false; bool ErrFlag = false;

	if (mode == REPLACE) {
		waypointDb.emptyDataContainer();
		poiDb.emptyDataContainer();}

	this->m_iFile.open(this->m_fileName.data());

	if(m_iFile.is_open()){
		CJsonScanner CJsonScanner(m_iFile);
		CJsonToken* pNxtToken;
		CMyStateMachine StateMachine;
		fileStatus = true;
		while(m_iFile.is_open())
		{
			try
			{
				pNxtToken = CJsonScanner.nextToken();

				CJsonStringToken* pStringToken;
				CJsonNumberToken* pNumberToken;

				switch(StateMachine.getState()){

				case ISIDLE :{
					switch(pNxtToken->getType()){
					case CJsonToken::BEGIN_OBJECT:
						StateMachine.setState(ISWAITING_DB_NAME);
						break;
					case CJsonToken::JSON_NULL: break;
					default:
						cerr << "ERROR : format error in line " << CJsonScanner.scannedLine()<< endl;
						m_iFile.close();
						break;
					}
					break;
				}

				case ISWAITING_DB_NAME:{
					switch(pNxtToken->getType()){
					case CJsonToken::STRING:
						pStringToken = dynamic_cast<CJsonStringToken*>(pNxtToken);
						DbName       = pStringToken->getValue();

						if(DbName == "waypoints"){wpFlag = true; poiFlag = false;}
						else if(DbName == "pois")  {wpFlag = false;poiFlag = true;}
						else cerr<< "ERROR: Wrong database name in Line"<< CJsonScanner.scannedLine() << endl;
						DbName = "";

						StateMachine.setState(ISWAITING_DB_BEGIN);
						break;

					default:
						cerr << "ERROR : format error in line " << CJsonScanner.scannedLine()<< endl;
						m_iFile.close();
						break;
					}
				}
				break;

				case ISWAITING_DB_BEGIN:
				{
					switch(pNxtToken->getType())
					{
					case CJsonToken::NAME_SEPARATOR:
					case CJsonToken::BEGIN_ARRAY:
					case CJsonToken::BEGIN_OBJECT:
						break;
					case CJsonToken::STRING:
						pStringToken = dynamic_cast<CJsonStringToken*>(pNxtToken);
						AttrName     = pStringToken->getValue();
						StateMachine.setState(ISWAITING_ATTR_NAME);
						break;

					default:
						cerr << "ERROR : format error in line " << CJsonScanner.scannedLine()<< endl;
						m_iFile.close();
						break;
					}
				}
				break;

				case ISWAITING_ATTR_NAME:
				{
					switch(pNxtToken->getType())
					{
					case CJsonToken::NAME_SEPARATOR:
						StateMachine.setState(ISWAITING_NAME_SEP);
						break;
					default:
						break;
					}
				}
				break;

				case ISWAITING_NAME_SEP:
				{
					switch(pNxtToken->getType())
					{
					case CJsonToken::STRING:
					{
						pStringToken = dynamic_cast<CJsonStringToken*>(pNxtToken);
						if(pStringToken != NULL)
						{
							if      (AttrName == "name")        name = pStringToken->getValue();
							else if (AttrName == "description") description = pStringToken->getValue();
							else if (AttrName == "type")
							{
								strType = pStringToken->getValue();
								if      (strType == "RESTAURANT")  type = RESTAURANT;
								else if (strType == "TOURISTIC")   type = TOURISTIC;
								else if (strType == "GASSTATION")  type = GASSTATION;
								else if (strType == "UNIVERSITY")  type = UNIVERSITY;
								else
								{
									cerr<< "ERROR: Wrong attribute in Line"<< CJsonScanner.scannedLine() << endl;
									type = DEFAULT;
								}
							}
							else
							{
								cerr<< "ERROR: Wrong attribute in Line"<< CJsonScanner.scannedLine() << endl;
								ErrFlag = true;
							}
						}
						else
						{
							cerr<< "ERROR: Wrong Value in Line"<< CJsonScanner.scannedLine() << endl;
							ErrFlag = true;
						}
						StateMachine.setState(ISWAITING_VALUE);
						break;
					}
					case CJsonToken::NUMBER:
						pNumberToken = dynamic_cast<CJsonNumberToken*>(pNxtToken);
						if(pNumberToken != NULL)
						{
							if     (AttrName == "latitude") latitude   = pNumberToken->getValue();
							else if(AttrName == "longitude") longitude = pNumberToken->getValue();
							else
							{
								cerr<< "ERROR: Wrong attribute in Line"<< CJsonScanner.scannedLine() << endl;
								ErrFlag = true;
							}
						}
						else
						{
							cerr<< "ERROR: Wrong Value in Line"<< CJsonScanner.scannedLine() << endl;
							ErrFlag = true;
						}
						StateMachine.setState(ISWAITING_VALUE);
						break;

					default:
						cerr << "ERROR : format error in line " << CJsonScanner.scannedLine()<< endl;
						m_iFile.close();
						break;

					}
				}
				break;

				case ISWAITING_VALUE:
				{
					switch(pNxtToken->getType())
					{
					case CJsonToken::VALUE_SEPARATOR:
						StateMachine.setState(ISWAITING_DB_BEGIN);//ISWAITING_ATTR_NAME);
						break;
					case CJsonToken::END_OBJECT:
						if((wpFlag)&&(!ErrFlag))
						{
							waypointDb.addData(CWaypoint(name,latitude,longitude));
						}
						else if((poiFlag)&&(!ErrFlag))
						{
							poiDb.addData(CPOI(type,name,description,latitude,longitude));
						}
						ErrFlag = false;
						StateMachine.setState(IS_WAITING_END);
						break;

					default:
						cerr << "ERROR : format error in line " << CJsonScanner.scannedLine()<< endl;
						m_iFile.close();
						break;
					}
				}
				break;

				case IS_WAITING_END:
				{
					switch(pNxtToken->getType())
					{
					case CJsonToken::VALUE_SEPARATOR:
					case CJsonToken::END_ARRAY:
						break;
					case CJsonToken::BEGIN_OBJECT:
						StateMachine.setState(ISWAITING_DB_BEGIN);
						break;
					case CJsonToken::STRING:
						pStringToken = dynamic_cast<CJsonStringToken*>(pNxtToken);
						DbName       = pStringToken->getValue();

						if(DbName == "waypoints"){wpFlag = true; poiFlag = false;}
						else if(DbName == "pois")  {wpFlag = false;poiFlag = true;}
						else cerr<< "ERROR: Wrong database name in Line"<< CJsonScanner.scannedLine() << endl;
						DbName = "";
						StateMachine.setState(ISWAITING_DB_BEGIN);
						break;
					case CJsonToken::END_OBJECT:
						m_iFile.close();
						break;

					default:
						cerr << "ERROR : format error in line " << CJsonScanner.scannedLine()<< endl;
						m_iFile.close();
						break;
					}
					break;
				}

				default:
					break;
				}
			}catch(int exception)
			{
				cerr << "ERROR: Invalid Character in line" << CJsonScanner.scannedLine() << endl;
			}
		}
	}
	return fileStatus;
}
