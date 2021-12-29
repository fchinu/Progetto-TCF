#ifndef GRIGLIA_H
#define GRIGLIA_H
#include "Navi.h"
#include "Navi2.h"
#include <vector>
using std::vector;


class Griglia
{
public:
    Griglia(int);

    void DrawEnemy() const;
    void DrawAlly() const;
    vector<vector<*Navi> > grid;

private:
    // vector<vector<*Navi> > grid;
};
#endif