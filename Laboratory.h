// Laboratory.h
// This file describes what a Laboratory object contains
// and what operations can be performed on it.
#ifndef LABORATORY_H
#define LABORATORY_H
#include <string>
// We need string because several laboratory attributes are Strings
using namespace std;


class Laboratory
{
private:

    string id;
    string name;
    string type;
    string building;
    int capacity;
    string status;
    string condition;
public:

    Laboratory();
    // Default constructor.
    // Creates a laboratory with empty/default values.

    Laboratory(string id, string name, string type,
               string building, int capacity,
               string status, string condition);
    // Constructor that allows us to create a complete laboratory
    // by providing all seven attributes.

    string getId();
    // Returns the laboratory ID.

    string getName();
    // Returns the laboratory name.

    string getType();
    // Returns the laboratory type.

    string getBuilding();
    // Returns the laboratory building.

    int getCapacity();
    // Returns the laboratory capacity.

    string getStatus();
    // Returns the laboratory status.

    string getCondition();
    // Returns the laboratory condition.

    void setId(string id);
    // Changes the laboratory ID.

    void setName(string name);
    // Changes the laboratory name.

    void setType(string type);
    // Changes the laboratory type.

    void setBuilding(string building);
    // Changes the laboratory building.

    void setCapacity(int capacity);
    // Changes the laboratory capacity.

    void setStatus(string status);
    // Changes the laboratory status.

    void setCondition(string condition);
    // Changes the laboratory condition.
};

#endif
// Ends the Laboratory header file.
