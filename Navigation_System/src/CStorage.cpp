
//user libraries
#include "CStorage.h"


using namespace std;

#define WP_PARAM 3
#define POI_PARAM 5
#define INVALID_DELIM 'I'

/*
 * Constructor    --> CStorage
 * Description --> Initialize attributes of class CStorage
 * @param input : NONE
 * @param output: NONE
 */
CStorage::CStorage()
{


}

/*
 * Constructor    --> ~CStorage
 * Description --> destroys dynamic arrays if any
 * @param input : NONE
 * @param output: NONE
 */
CStorage::~CStorage()
{

}

/**
 * Set the name of the media to be used for persistent storage.
 * The exact interpretation of the name depends on the implementation
 * of the component.
 *
 * @param name the media to be used
 */
void CStorage::setMediaName(std::string name)
{

	m_Wpstorage = name + "_wp.txt";
	m_PoiStorage = name + "_poi.txt";
}

/**
 * Write the data to the persistent storage.
 *
 * @param waypointDb the data base with way points
 * @param poiDb the database with points of interest
 * @return true if the data could be saved successfully
 */
bool CStorage::writeData (const CWpDatabase& waypointDb,const CPoiDatabase& poiDb)
{

	ofstream lo_Storage;
	bool Err_flag = false;
	map<string,CWaypoint>::const_iterator i;

	lo_Storage.open(this->m_Wpstorage.data());  //to open the WP storage
	lo_Storage.seekp(0);                        //starting point of file

	if(lo_Storage.is_open())
	{   //if file is open write WP
		waypointDb.printWaypoint(lo_Storage);
		lo_Storage.close();   //close the file
		Err_flag = true;
	}

	else //error message
	{
		cout << endl << endl<< "Waypoint file is not open" << endl << endl;
	}


	lo_Storage.open(this->m_PoiStorage.data()); //to open the POI storage
	lo_Storage.seekp(0);                        //starting point of file

	if(lo_Storage.is_open())
	{   //if file is open write POI
		poiDb.printPoi(lo_Storage);
		lo_Storage.close(); //close the file
		Err_flag = (Err_flag & true);
	}

	else
	{
		cout << endl << endl<< "POI file is not open" << endl << endl;
	}

	return Err_flag;
}

bool CStorage::readData(CWpDatabase& waypointDb, CPoiDatabase& poiDb,MergeMode mode)
{
	ifstream myStorage;
	string line;
	bool Err_flag = false;

	//parameters of POI and WP
	double latitude=0; string lat;
	double longitude=0; string lon;
	string name ="default name";
	t_poi type = DEFAULT;
	string description = "default description";

	int wp_count = 0;
	int poi_count = 0;
	int Line_number = 0;

	char delim = ';';
	string param ;


	//clear the DBs if mode is Replace
	if(mode == REPLACE)
	{
		waypointDb.emptyWpContainer();   //clear WP database
		poiDb.emptyPoiContainer();       //clear POI database
	}

	// Waypoint Database
	myStorage.open(this->m_Wpstorage.data());                        //open file data

	if(myStorage.is_open())                                          //if file is open
	{
		while(getline(myStorage, line) && !line.empty())             // get the line if its not empty
		{
			Line_number++;
			delim = getDelim(line, WP_PARAM-1);                      //delim = ;/,

			if(delim != INVALID_DELIM)
			{
				stringstream linestream(line);                       //to get line stream
				if(getParameterCount(line,delim) == WP_PARAM)
				{
					while(getline(linestream,param,delim))           // to get parameters
					{
						if(wp_count < WP_PARAM)                      // to check count that counts number of parameters in Waypoint
						{
							switch(wp_count)
							{
							case 0: name = param;break;
							case 1: lat = commaToPoint(param,Line_number,this->m_Wpstorage);break;
							case 2: lon = commaToPoint(param,Line_number,this->m_Wpstorage);break;
							default: cout << "Invalid Waypoint entry" << endl;
							}
						}
						wp_count++;
					}
					wp_count = 0;                                         //for the next WP
					if(getErrText(lat)&&getErrText(lon))
					{
						latitude = atof(lat.c_str());                     // convert to double
						longitude = atof(lon.c_str());
						waypointDb.addWaypoint(*(new CWaypoint(name,latitude,longitude)));

					}
					else
					{
						cout << "Error: "<< this->m_Wpstorage <<" <Number is expected for latitude and longitude> in line <" <<Line_number <<">"   << endl;
					}
				}
			}
			else
			{
				cout<< "Error: "<< this->m_Wpstorage <<" <Too less or more fields than expected(Three)> in line <" <<Line_number<<">" << endl;
			}
		}
		Err_flag = true;
		myStorage.close();                 //close file after reading
		Line_number = 0;
	}

	else
	{
		cout << endl<<  "Waypoint Database file cant be opened" << endl;
	}


	// POI Database
	myStorage.open(this->m_PoiStorage.data()); //open file data

	if(myStorage.is_open())                   //if file is open
	{
		while(getline(myStorage, line) && !line.empty())        // get the line if its not empty
		{
			Line_number++;
			delim = getDelim(line, POI_PARAM-1);           //delim = ;/,

			if(delim != INVALID_DELIM)
			{
				stringstream linestream(line);    //to get line stream
				if(getParameterCount(line,delim) == POI_PARAM)
				{
					while(getline(linestream,param,delim))  // to get parameters
					{
						if(poi_count < POI_PARAM)           // to check count that counts number of parameters in POI
						{
							switch(poi_count)
							{
							case 0:
								if      (param == "RESTAURANT") {type = RESTAURANT;break;}   //type
								else if (param == "GASSTATION") {type = GASSTATION;break;}
								else if (param == "UNIVERSITY") {type = UNIVERSITY;break;}
								else if (param == "TOURISTIC")  {type = TOURISTIC;break;}
								break;
							case 1: name        = param;break;                                  //name
							case 2: description = param;break;                                  //description
							case 3: lat = commaToPoint(param,Line_number,this->m_PoiStorage);   //latitude
							break;
							case 4: lon = commaToPoint(param,Line_number,this->m_PoiStorage);
							break;  //longitude
							default: cout << "Invalid POI entry" << endl;
							}

						}

						poi_count++;
					}
					poi_count = 0;                   //for the next WP
					if(getErrText(lat)&& getErrText(lon))
					{
						latitude = atof(lat.c_str());   // convert to double
						longitude = atof(lon.c_str());
						poiDb.addPoi(*(new CPOI(type,name,description,latitude,longitude)));
					}
					else
					{
						cout << "Error: "<< this->m_PoiStorage <<" <Number is expected for latitude and longitude> in line <" <<Line_number <<"> "   << endl;
					}
				}

			}
			else
			{
				cout<< "Error: "<< this->m_PoiStorage <<" <Too less or more fields than expected (Five)> in line <" <<Line_number<<">" << endl;
			}
		}

		Err_flag = Err_flag & true;
		myStorage.close();                 //close file after reading
		Line_number = 0;
	}
	else
	{
		cout << endl<<  "POI Database file cant be opened" << endl;
	}

	return Err_flag;
}

/*
 * Function     --> getParameterCount(std::string Line, char delim)
 * Description  --> To get number of parameters in a given line seperated
 *                  by , or ;
 * @param input --> string : Line
 *                  char   : Deliminator
 * @param output --> int   : Number of parameters
 */
int getParameterCount(string Line, char delim)
{
	string li_Param;
	stringstream myLine(Line);
	int li_param_count=0;
	//Run until end of line
	while(getline(myLine,li_Param,delim))
	{
		li_param_count++;
	}
	return li_param_count;
}

/*
 * Function     --> commaToPoint(std::string param,int LineNumber,std::string fileName)
 * Description  --> Error handling: If comma is used instead of decimal point, replace the
 *                  comma with decimal point in latitude and longitude and display warning
 * @param input --> string : Parameter ( latitude/ longitude)
 *                  int    : Line number
 *                  string : File name
 * @param output --> string   : Rectified parameter (Latitude / Longitude)
 */
string commaToPoint(string param, int LineNumber, string fileName)
{
	//Search for the comma in the parameter
	size_t Found = param.find(',',0);
	size_t Char_Length = 1;

	//change comma to decimal point if comma is found
	if(Found != string::npos)
	{
		//replace , with . at position Found
		cout << "Warning: "<<fileName<<"< Comma is used in place of decimal point> line number <" << LineNumber << "> Parameter <" <<param <<">" << endl;
		param.replace(Found,Char_Length,".");
	}
	return param;

}


/*
 * Function     --> getDelim(std::string line, int max_delim)
 * Description  --> To get the deliminator (;/,)
 * @param input --> string : Line
 *                  int    : Maximum allowed deliminator
 * @param output --> char  : Deliminator
 */
char getDelim(string line, int max_delim)
{
	size_t Comma, Colon;
	int Comma_count=0;int Colon_count=0;

	Comma = line.find(',');
	while(Comma != string::npos)
	{
		Comma_count++;
		Comma = line.find(',',Comma+1);
	}

	Colon = line.find(';');
	while(Colon != string::npos)
	{
		Colon_count++;
		Colon = line.find(';',Colon+1);
	}

	if (Colon_count == max_delim) return ';';
	else if(Comma_count == max_delim) return ',';
	else return INVALID_DELIM;
}

/*
 * Function     --> getErrText(const std::string& param)
 * Description  --> To know if text is seen in the place of latitude and
 *                  longitude where numbers are expected.
 * @param input --> string : Parameter
 * @param output --> bool  : Error status
 */
bool getErrText(string& param)
{
	string::const_iterator i;
	bool Err_flag = true;
    size_t find_space = 0;

    find_space = param.find(" ");
    while(find_space != string::npos)
    {
        param.replace(find_space,1,"");
        find_space = param.find(" ",find_space+1);
    }

	for(i = param.begin(); i != param.end(); i++)
	{
		if(isdigit(*i)||(*i == '.'))	Err_flag &= true;
		else Err_flag = false;
	}
	return Err_flag;
}


