#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include "LinkedList.h"
#include <string>
using namespace std;

class FileManager
{
public:

    // Saves all laboratories from the Linked List into the text file.
    bool saveToFile(LinkedList& list, string filename);

    // Loads laboratories from the text file into the Linked List.
    bool loadFromFile(LinkedList& list, string filename);
    
};

#endif
