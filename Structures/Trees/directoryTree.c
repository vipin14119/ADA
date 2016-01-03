/* This is code of directory tree system ,it builds a directory tree and then search for particular path
    This code runs with a input file ,file.txt included in repository 
	the file follows folling format
	1. group of set of lines represents directories to be made in file system
	2. a blank line  
	3. a path which needs to be checked in your directory tree
	4. then again a blank line(very important)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* Author : Vipin Chaudhary
*/

typedef struct TreeNode  // structure of directory tree node
{
	char name[20];  // stores name of directory
	struct TreeNode *array[5];  // assuming every directory can have maximum 5 directories
}node;
node* root;  // global variable of root of tree

typedef struct dir  // structure to store directoies in a particular path
{
	char name[20];
}dir;
dir tokens[5];  // array of 5 length ,because directory can have atmost 5 directory

node* createNode(char n[])  // function to create a new tree node
{
	node* newnode=(node*)malloc(sizeof(node));
	strcpy(newnode->name,n);  // copy the name 
	int i;
	for (i = 0; i < 5; ++i)
	{
		newnode->array[i]=NULL;  // initiates all address to NULL because node doesnt have any child in starting
	}
	return newnode;  // return its address
}

node* addNode(node* prevDir, char nextDir[])  // function to add a new node in a directory
{

	// here we want to create a directory named(nextDir) in the directory name prevDir(parent of nextDir)
	int i;
	for (i = 0; i < 5; ++i)  // loop through all five children locations of a node
	{
		if(prevDir->array[i]==NULL)  // if a NULL position strikes ,then parent doesnt have nextDir
		{
			prevDir->array[i]=createNode(nextDir);  // so create it in this empty position
			return prevDir->array[i];  // and return its address for next directory as a parent
		}
		else if(strcmp(prevDir->array[i]->name,nextDir)==0)  // if directory already exist then then return its address
		{
			return prevDir->array[i];  // return already existed directory address as a parent for next directory
		}
	}
}

int flag=-1;  // flag to check the status ,that directory exist or not

node* checkNode(node* prevDir,char nextDir[])  // function to check that nextDir exists in childrens of prevDir or not
{
	int i;
	flag=-1;  // initiates with -1 ,assuming nextDir doest exist and change to 0 is we find the directory

	for (i = 0; i < 5; ++i)
	{
		if(prevDir->array[i]==NULL)  // if hits a null then returns with flag=-1 as it doesnt exist 
		{
			return ;
		}
		else if(strcmp(prevDir->array[i]->name,nextDir)==0)  // if founded then change flag value and return its address for next directory as a parent
		{
			flag=0;
			return prevDir->array[i];
		}
	}

}

void clear()  // function to clear the list of directories
{
	int i;
	for (i = 0; i < 5; ++i)
	{
		strcpy(tokens[i].name,"\0");
	}
}

int main()
{
	root=createNode("Root");  // create a root directory with nothing inside in it
	node* prev;  // to store the returned address as a parent
	int mode=0;  // to know the directory making mode or path cheking mode , initially to addnode mode in tree
	int tokenCount=0;  // to count the tokens found in the line
	FILE *fp ;
    fp = fopen("./file.txt", "r");  // input file name file.txt
    if (fp!=NULL)
    {
    	char line[100];  // assuming , file doesnt have line greater than 100 length
    	while (fgets(line,sizeof line,fp)!= NULL)  // read full line at a time 
 		{
 			line[strlen(line)-1]='\0';  // strip the trailing endline character
 			tokenCount=0;  // initiate token count with 0
 			clear();  // wipe the previous data stored in list 
 			if (strlen(line)<=2)  // this checks the blank line in the file ,and if blank line hitted then change to path finding mode
 			{
 				mode=1;  // mode changed
 			}
 			else  
 			{
 				char* token = strtok(line,"/");  // tokenize the line according to / 
				int i=0;
				while (token)
				{
					strcpy(tokens[i++].name,token);  // stores them in the list of token
    				token = strtok(NULL, "/");
    				tokenCount++;  // increase tokencount
    			}
    			if (mode==0)  // if mode is addnode
    			{
    				int j;
    				prev=addNode(root,tokens[0].name);  // always first token should be add to rootnode
    				for (j = 1; j < tokenCount; ++j)  
    				{
    					prev=addNode(prev,tokens[j].name);  // remaining tokens to be add in the previuous returned address
    				}	
    			}
    			else  // if mode is path checking
    			{
    				int j;
    				prev=checkNode(root,tokens[0].name);   // always first token should be checked in the rootnode
    				for (j = 1; j < tokenCount; ++j)
    					{
    						prev=checkNode(prev,tokens[j].name);  // remaining tokens to be checked in the previuous returned address
    						if (flag==-1)  // every time check that whether the token existed or not , if not then break the loop , as there is no point to check the rest of path
    						{
    							printf("Path Doesnt exist\n");  
    							break;
    						}
    					}
    				if (flag==0)  // if flag comes out to be 0 after checking all the tokens ,that means path exist
					{
						printf("Correct Path .It does exist\n");
					}
    			}
 			}
 		}
 		fclose(fp);  //clsoe the file
    }
	return 0;
}
