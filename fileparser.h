#ifndef FILEPARSER_H
#define FILEPARSER_H

class FileParser
{
private:
    char *file_contents;
    unsigned long file_size;
    char *p;
    char *parseString( char term );
    void skip();
    bool skip( char c );
    struct stunde parseStunde();
public:
    FileParser();
    void loadFile( char *path );
    struct tag parseFile();
    //void parseFile();
};

struct tag {
    char *name;
    struct stunde *std;
    unsigned int stunden;
};

struct stunde {
    char *fach;
    char *lehrer;
    char *raum;
};

#endif // FILEPARSER_H
