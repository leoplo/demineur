#ifndef ELEMENTGRILLE_H_INCLUDED
#define ELEMENTGRILLE_H_INCLUDED

struct elementGrille {
    int presenceMine; // 1 si true et 0 si false
    int presenceDrapeau; // 1 si true et 0 si false
    int caseRevelee; // 1 si true et 0 si false
};

typedef struct elementGrille ElementGrille;
#endif // ELEMENTGRILLE_H_INCLUDED
