
#include <string>
#include "CJsonScanner.h"

using namespace std;

namespace APT {

CJsonScanner::CJsonScanner(std::istream& input) : jsonFlexLexer(&input) {
	token = 0;
}

CJsonScanner::~CJsonScanner() {
	if (token != 0) {
		delete token;
	}
}

CJsonToken* CJsonScanner::nextToken()
{
	if (token != 0) {
		delete token;
		token = 0;
	}


	int scanResult = yylex();
	if (scanResult == -1)
	{
		string illegalChar(YYText());
		// Found illegal character, currently ignored.
		throw -1;
	}
	return token;
}

int CJsonScanner::scannedLine() {
	return yylineno;
}

} /* namespace APT */

int yyFlexLexer::yywrap() {
	return 1;
}

