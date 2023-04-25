#include "stage.h"

void Stage::drawShape(const Shape* s, std::ostream & out) const {
    for (int y=_heigh; y>=0; y--) {
        out << y << ":\t";
        for (int x=0; x<=_width; x++)
            if (s->isIn(x,y)) out << _sign;
            else out << " ";
        out << "\n";
    }
}