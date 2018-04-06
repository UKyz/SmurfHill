#include "view.h"
#include "controller.h"
#include "model.h"
#include "decor.h"

Model::Model()
{
}

Village *Model::setVillage(View *view) {

    Village *villageS = new Village(100,100, view);
    return villageS;

}

void Model::actionPerso(int x, int y, int nbS) {
    listS->at(0)->moveTo(x, y);
}
