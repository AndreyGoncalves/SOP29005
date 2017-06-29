#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#include "FileSystem.h"
#include "VirtualDisk.h"

using namespace std;

int FileSystem::create_file_system(char * disk_name){

	if (!disk_name) {
		fprintf(stderr, "invalid filesystem name\n");
		return 0;
	}
	
	int BLOCK_SIZE = 4096;
	char buf2[BLOCK_SIZE];
	
	VirtualDisk::create_disk(disk_name);//cria disco
	VirtualDisk * fs = new VirtualDisk(disk_name);//abre disco
	VirtualDisk::write_block(0,buf2);//metadados
}

//FileSystem::FileSystem(char * disk_name){}

int FileSystem::delete_file(char * file_name){}

int FileSystem::create_file(char * file_name){}

FileSystem::~FileSystem(){}
