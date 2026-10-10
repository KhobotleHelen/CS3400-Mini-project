// This file contains the actual implementation of the laboratory class
#include "Laboratory.h"
// We include the header because this file implements Laboratory.

Laboratory::Laboratory()
{
    id = "";
    // The initial ID starts empty.

    name = "";
    // The initial name starts empty.

    type = "";
    // The initial type starts empty.

    building = "";
    // The initial building starts empty.

    capacity = 0;
    // The initial capacity is zero.

    status = "";
    // The initial status starts empty.

    condition = "";
    // The initial condition starts empty.
}

Laboratory::Laboratory(string id, string name, string type,
                       string building, int capacity,
                       string status, string condition)
{
    this->id = id;
    // Store the supplied ID inside the object.

    this->name = name;
    // Store the supplied name.

    this->type = type;
    // Store the supplied type.

    this->building = building;
    // Store the supplied building.

    this->capacity = capacity;
    // Store the supplied capacity.

    this->status = status;
    // Store the supplied status.

    this->condition = condition;
    // Store the supplied condition.
}
string Laboratory::getId()
{
    return id;
    // Give the caller the laboratory ID.
}
string Laboratory::getName()
{
    return name;
    // Give the caller the laboratory name.
}
string Laboratory::getType()
{
    return type;
    // Give the caller the laboratory type.
}
string Laboratory::getBuilding()
{
    return building;
    // Give the caller the building.
}
int Laboratory::getCapacity()
{
    return capacity;
    // Give the caller the capacity.
}
string Laboratory::getStatus()
{
    return status;
    // Give the caller the status.
}
string Laboratory::getCondition()
{
    return condition;
    // Give the caller the condition.
}

void Laboratory::setId(string id)
{
    this->id = id;
    // Change the laboratory ID.
}

void Laboratory::setName(string name)
{
    this->name = name;
    // Change the laboratory name.
}

void Laboratory::setType(string type)
{
    this->type = type;
    // Change the laboratory type.
}

void Laboratory::setBuilding(string building)
{
    this->building = building;
    // Change the laboratory building.
}

void Laboratory::setCapacity(int capacity)
{
    this->capacity = capacity;
    // Change the laboratory capacity.
}

void Laboratory::setStatus(string status)
{
    this->status = status;
    // Change the laboratory status.
}

void Laboratory::setCondition(string condition)
{
    this->condition = condition;
    // Change the laboratory condition.
}
