#include "PacString.h"
#include "String"

PacString::PacString()
{
	mpszData = "";
}

//Constructor
PacString::PacString(const char *pszString)
{
	int size = (int) strlen(pszString) + 1;

	mpszData = new char[size];

	//strcpy(mpszData, pszString);
	strcpy_s(mpszData, size, pszString);
}

//Copy Constructor
PacString::PacString(const PacString &rcData)
{
	int size = (int) strlen(rcData.mpszData);

	mpszData = new char[size];

	strcpy_s(mpszData, sizeof(char*), rcData.mpszData);
}

PacString::~PacString()
{
	delete mpszData;
}

PacString& PacString::operator=(PacString rcData)
{
	int size = (int) strlen(rcData.mpszData);

	mpszData = new char[size];

	//strcpy(mpszData, rcData.mpszData);
	strcpy_s(mpszData, sizeof(char*), rcData.mpszData);

	return rcData;
}


PacString & PacString::operator+=(const PacString & rcData)
{
	//NewString += oldString

	//int size = (int)strlen(rcData.mpszData) + (int)strlen(mpszData) + 1;

	//strcat_s(mpszData, size, rcData.mpszData);

	return *this;
}

PacString PacString::operator+(const PacString & rcData) const
{
	//NewString = oldString + olderString
	return PacString();
}

std::ostream& operator<<(std::ostream &out, const PacString &rcData)
{
	out << rcData.mpszData;

	return out;
}