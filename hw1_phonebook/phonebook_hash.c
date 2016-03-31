#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_hash.h"

/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastname[], entry *pHead)
{	
	int hashindex = hash(lastname);
    /* TODO: implement */
    while (pHead != NULL) {
        if (strcasecmp(lastname, pHead->lastName) == 0){
			//printf("find it %s \n",pHead->lastName);
            return pHead;
		}
        pHead = pHead->pNext;
	}
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;
    return e;
}

unsigned int hash(char *key){
	unsigned int hashVal = 0;
	//printf("%c\n",*key);
	while(*key != '\0')
		hashVal = (hashVal << 5) + *key++;
	//printf("hash index:%d\n",hashVal%42737);
	return hashVal % 42737;
}


