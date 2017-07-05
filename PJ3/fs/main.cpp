#include <cstdlib>

#include "FileSystem.h"

using namespace std;

int main(int argc, char** argv) {
    char disco = 'F';
    FileSystem::create_file_system(&disco);
    return 0;
}

