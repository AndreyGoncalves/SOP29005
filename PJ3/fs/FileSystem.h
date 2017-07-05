#include "VirtualDisk.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


class FileSystem {
private:
    FileSystem(char * disk_name);

public:
    static int create_file_system(char * disk_name);

    ~FileSystem();

    int create_file(char * file_name);
    int delete_file(char * file_name);
    int first_free_block();

    static FileSystem * instance() { return _fs; }

    VirtualDisk * disk() { return &_disk; }

    int MAX_FILES=40;
    int BLOCKS_PER_FILE=1;

private:
    VirtualDisk _disk;
    static FileSystem * _fs;
    char buf2[VirtualDisk::BLOCK_SIZE];
    
    struct stc_file{
        int32_t active;
        int32_t first_block;
        int32_t offset_read;
        int32_t offset_write;
           
    };
    
    struct stc_bloco{
	int32_t dir;
	int32_t dir_len;
	int32_t data_ind;
    };

    struct stc_diretorio{
	int32_t used;
	char name[20];
	int32_t size;
	int32_t head;
	int32_t ref_count;
	int32_t num_blocks;
    };
    
    stc_diretorio* dir;
    stc_bloco fsys;
};
