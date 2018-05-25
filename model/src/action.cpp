#include "../includes/action.h"

ActionMove::ActionMove(int depX, int depY): Action() {
    this->deplacementX = depX;
    this->deplacementY = depY;
}

ActionFight::ActionFight(NormalPerso *fighter, NormalPerso *defender) {
    this->fighter = fighter;
    this->defender = defender;
}
