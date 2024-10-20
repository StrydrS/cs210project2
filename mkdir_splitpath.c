#include "types.h"
#include <string.h>

extern struct NODE* root;
extern struct NODE* cwd;

void mkdir(char pathName[]) { 
        
    struct NODE* node = (struct NODE*)malloc(sizeof(struct NODE));
    strcpy(node->name, pathName);
    node->fileType = 'D';
    node->parentPtr = cwd;
    node->childPtr = NULL;
    node->siblingPtr = NULL;
    

    return;
}

//handles tokenizing and absolute/relative pathing options
struct NODE* splitPath(char* pathName, char* baseName, char* dirName){ 
    
    // iterates pathName and splits based on delimiter '/'. ends at
    // null terminator

    int i = 0;
    int lastIndex = 0; 
    int delimCount = 0; 

    while(pathName[i] != '\0') {
        if(pathName[i] == '/') { 
            lastIndex = i;
            delimCount += 1;
        }
        i++;
    }
    
    //occupies baseName and dirName pointers with their proper values
    // (return using function arguments)
    

    if(delimCount < 1) { 
        strcpy(baseName, pathName + lastIndex + 1);
        strncpy(dirName, pathName, lastIndex);
    } else if(delimCount == 0) {
        strcpy(baseName, pathName);
        strcpy(dirName, "");
    }
    
    
    
    return NULL;
}
