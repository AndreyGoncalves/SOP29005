#include "FileSystem.h"

class File {
public:
    File(char * file_name); // para ser chamado apenas pelo FileSystem
    ~File(); // deve fechar o arquivo

    int read(void * buf, size_t bytes); // lê no máximo 'bytes' bytes do arquivo e armazena em 'buf'
    int write(void * buf, size_t bytes); // escreve 'bytes' bytes de 'buf' para o arquivo
    int size(); // retorna o tamanho do arquivo
    int lseek(int offset); // move o apontador do arquivo de acordo com o parâmetro offset (offset pode ser negativo)
};
