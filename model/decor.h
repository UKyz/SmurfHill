#ifndef DECOR_H
#define DECOR_H

#include "autre.h"
#include "view.h"
#include <QtDebug>

class View;
class ImageSetting;

class Setting : public QObject {
    Q_OBJECT
    public:
        Setting(QString type, int posX, int posY, View *view);
        QString getType() {return this->type;}
        int getPosX() {return this->posX;}
        int getPosY() {return this->posY;}
    protected:
        QString type;
        int posX;
        int posY;
        View *view;
};

class Village : public Setting
{
    Q_OBJECT
    public:
        Village(QString type, int posX, int posY, View *view);
        // Houses
        ImageSetting *getPapaSmurf() {return this->papaSmurf;}
        ImageSetting *getBrainy() {return this->brainy;}
        ImageSetting *getDoctor() {return this->doctor;}
        ImageSetting *getHouse1() {return this->house1;}
        ImageSetting *getHouse2() {return this->house2;}
        ImageSetting *getHouse3() {return this->house3;}
        ImageSetting *getHouse4() {return this->house4;}
        ImageSetting *getHouse5() {return this->house5;}
        ImageSetting *getHouse6() {return this->house6;}
        ImageSetting *getHouse7() {return this->house7;}
        ImageSetting *getHouse8() {return this->house8;}
        ImageSetting *getHouse9() {return this->house9;}
        ImageSetting *getHouse10() {return this->house10;}
        ImageSetting *getHouse11() {return this->house11;}
        ImageSetting *getHouse12() {return this->house12;}
        ImageSetting *getHouseSmurfette() {return this->houseSmurfette;}
        ImageSetting *getHouseHefty() {return this->houseHefty;}
        ImageSetting *getHouseFarmer() {return this->houseFarmer;}
        ImageSetting *getHouseMusician() {return this->houseMusician;}
        ImageSetting *getHouseBaker() {return this->houseBaker;}
        ImageSetting *getMill() {return this->mill;}
        ImageSetting *getWell() {return this->well;}
        ImageSetting *getInventory() {return this->inventory;}
        // Trees
        ImageSetting *getTree1() {return this->tree1;}
        ImageSetting *getTree2() {return this->tree2;}
        ImageSetting *getTree3() {return this->tree3;}
        ImageSetting *getTree4() {return this->tree4;}
        ImageSetting *getTree5() {return this->tree5;}
        ImageSetting *getTree6() {return this->tree6;}
        ImageSetting *getTree7() {return this->tree7;}
        ImageSetting *getTree8() {return this->tree8;}
        ImageSetting *getTree9() {return this->tree9;}
        ImageSetting *getTree10() {return this->tree10;}
        ImageSetting *getTree11() {return this->tree11;}
        ImageSetting *getTree12() {return this->tree12;}
        ImageSetting *getTree13() {return this->tree13;}
        ImageSetting *getTree14() {return this->tree14;}
        ImageSetting *getTree15() {return this->tree15;}
        // Bushs
        ImageSetting *getBush1() {return this->bush1;}
        ImageSetting *getBush2() {return this->bush2;}
        ImageSetting *getBush3() {return this->bush3;}
        ImageSetting *getBush4() {return this->bush4;}
        ImageSetting *getBush5() {return this->bush5;}
        ImageSetting *getBush6() {return this->bush6;}
        ImageSetting *getBush7() {return this->bush7;}
        ImageSetting *getBush8() {return this->bush8;}
        ImageSetting *getBush9() {return this->bush9;}
    private:
        ImageSetting *house1, *house2, *house3, *house4, *house5, *house6, *house7, *house8, *house9, *house10, *house11, *house12;
        ImageSetting *papaSmurf, *brainy, *doctor, *houseSmurfette, *houseHefty, *houseMusician, *houseFarmer, *houseBaker;
        ImageSetting *mill, *well, *inventory;
        ImageSetting *tree1, *tree2, *tree3, *tree4, *tree5, *tree6, *tree7, *tree8, *tree9, *tree10, *tree11, *tree12, *tree13, *tree14, *tree15;
        ImageSetting *bush1, *bush2, *bush3, *bush4, *bush5, *bush6, *bush7, *bush8, *bush9;
};

class Forest : public Setting {
    Q_OBJECT
    public:
        Forest(QString type, int posX, int posY, View *view): Setting(type, posX, posY, view) {}
        int getPosXAcorn() {return this->posXAcorn;}
        int getPosYAcorn() {return this->posYAcorn;}
        int getPosXBerries() {return this->posXBerries;}
        int getPosYBerries() {return this->posYBerries;}
        int getPosXWheat() {return this->posXWheat;}
        int getPosYWheat() {return this->posYWheat;}
        int getPosXSarsaparilla() {return this->posXSarsaparilla;}
        int getPosYSarsaparilla() {return this->posYSarsaparilla;}
    protected:
        ImageSetting *acorn, *berries, *wheat;
        int nbAcorn, nbBerry, nbWheat;
        int posXAcorn, posYAcorn;
        int posXBerries, posYBerries;
        int posXWheat, posYWheat;
        int posXSarsaparilla, posYSarsaparilla;
};

class Forest1 : public Forest {
    Q_OBJECT
    public:
        Forest1(QString type, int posX, int posY, View *view);
        ImageSetting *getTree1() {return this->tree1;}
        ImageSetting *getTree2() {return this->tree2;}
        ImageSetting *getTree3() {return this->tree3;}
        ImageSetting *getTree4() {return this->tree4;}
        ImageSetting *getTree5() {return this->tree5;}
        ImageSetting *getTree6() {return this->tree6;}
        ImageSetting *getTree7() {return this->tree7;}
        ImageSetting *getTree8() {return this->tree8;}
        ImageSetting *getTree9() {return this->tree9;}
        ImageSetting *getTree10() {return this->tree10;}
        ImageSetting *getTree11() {return this->tree11;}
        ImageSetting *getTree12() {return this->tree12;}
        ImageSetting *getTree13() {return this->tree13;}
        ImageSetting *getTree14() {return this->tree14;}
        ImageSetting *getTree15() {return this->tree15;}
        ImageSetting *getTree16() {return this->tree16;}
        ImageSetting *getTree17() {return this->tree17;}
        ImageSetting *getBush1() {return this->bush1;}
        ImageSetting *getBush2() {return this->bush2;}
        ImageSetting *getBushBerries1() {return this->bushBerries1;}
        ImageSetting *getBushBerries2() {return this->bushBerries2;}
    private:
        ImageSetting *tree1, *tree2, *tree3, *tree4, *tree5, *tree6, *tree7, *tree8;
        ImageSetting *tree9, *tree10, *tree11, *tree12, *tree13, *tree14, *tree15, *tree16, *tree17;
        ImageSetting *bush1, *bush2, *bushBerries1, *bushBerries2;
};

class Forest2 : public Forest {
    Q_OBJECT
    public:
        Forest2(QString type, int posX, int posY, View *view);
        ImageSetting *getTree01() {return this->tree01;}
        ImageSetting *getTree02() {return this->tree02;}
        ImageSetting *getTree03() {return this->tree03;}
        ImageSetting *getTree04() {return this->tree04;}
        ImageSetting *getTree05() {return this->tree05;}
        ImageSetting *getTree06() {return this->tree06;}
        ImageSetting *getTree07() {return this->tree07;}
        ImageSetting *getTree1() {return this->tree1;}
        ImageSetting *getTree2() {return this->tree2;}
        ImageSetting *getTree3() {return this->tree3;}
        ImageSetting *getTree4() {return this->tree4;}
        ImageSetting *getTree5() {return this->tree5;}
        ImageSetting *getTree6() {return this->tree6;}
        ImageSetting *getTree7() {return this->tree7;}
        ImageSetting *getTree8() {return this->tree8;}
        ImageSetting *getTree9() {return this->tree9;}
        ImageSetting *getTree10() {return this->tree10;}
        ImageSetting *getTree11() {return this->tree11;}
        ImageSetting *getTree12() {return this->tree12;}
        ImageSetting *getTree13() {return this->tree13;}
        ImageSetting *getTree14() {return this->tree14;}
        ImageSetting *getBushBerries1() {return this->bushBerries1;}
        ImageSetting *getBush1() {return this->bush1;}
        ImageSetting *getBush2() {return this->bush2;}
        ImageSetting *getBush3() {return this->bush3;}
    private:
        ImageSetting *tree01, *tree02, *tree03, *tree04, *tree05, *tree06, *tree07;
        ImageSetting *tree1, *tree2, *tree3, *tree4, *tree5, *tree6, *tree7, *tree8, *tree9, *tree10;
        ImageSetting *tree11, *tree12, *tree13, *tree14;
        ImageSetting *bushBerries1, *bush1, *bush2, *bush3;
};

class Forest3 : public Forest {
    Q_OBJECT
    public:
        Forest3(QString type, int posX, int posY, View *view);
        ImageSetting *getTree01() {return this->tree01;}
        ImageSetting *getTree02() {return this->tree02;}
        ImageSetting *getTree1() {return this->tree1;}
        ImageSetting *getTree2() {return this->tree2;}
        ImageSetting *getTree3() {return this->tree3;}
        ImageSetting *getTree4() {return this->tree4;}
        ImageSetting *getTree5() {return this->tree5;}
        ImageSetting *getTree6() {return this->tree6;}
        ImageSetting *getTree7() {return this->tree7;}
        ImageSetting *getTree8() {return this->tree8;}
        ImageSetting *getTree9() {return this->tree9;}
        ImageSetting *getTree10() {return this->tree10;}
        ImageSetting *getTree11() {return this->tree11;}
        ImageSetting *getTree12() {return this->tree12;}
        ImageSetting *getTree13() {return this->tree13;}
        ImageSetting *getTree14() {return this->tree14;}
        ImageSetting *getTree15() {return this->tree15;}
        ImageSetting *getTree16() {return this->tree16;}
        ImageSetting *getTree17() {return this->tree17;}
        ImageSetting *getBushBerries1() {return this->bushBerries1;}
        ImageSetting *getBushBerries2() {return this->bushBerries2;}
        ImageSetting *getBushBerries3() {return this->bushBerries3;}
        ImageSetting *getBush1() {return this->bush1;}
        ImageSetting *getBush2() {return this->bush2;}
        ImageSetting *getSouche1() {return this->souche1;}
    private:
        ImageSetting *tree01, *tree02;
        ImageSetting *tree1, *tree2, *tree3, *tree4, *tree5, *tree6, *tree7, *tree8, *tree9;
        ImageSetting *tree10, *tree11, *tree12, *tree13, *tree14, *tree15, *tree16, *tree17;
        ImageSetting *bushBerries1, *bushBerries2, *bushBerries3, *bush1, *bush2, *souche1;
};

class Forest4 : public Forest {
    Q_OBJECT
    public:
        Forest4(QString type, int posX, int posY, View *view);
        ImageSetting *getTree1() {return this->tree1;}
        ImageSetting *getTree2() {return this->tree2;}
        ImageSetting *getTree3() {return this->tree3;}
        ImageSetting *getTree4() {return this->tree4;}
        ImageSetting *getTree5() {return this->tree5;}
        ImageSetting *getTree6() {return this->tree6;}
        ImageSetting *getTree7() {return this->tree7;}
        ImageSetting *getTree8() {return this->tree8;}
        ImageSetting *getTree9() {return this->tree9;}
        ImageSetting *getTree10() {return this->tree10;}
        ImageSetting *getTree11() {return this->tree11;}
        ImageSetting *getTree12() {return this->tree12;}
        ImageSetting *getTree13() {return this->tree13;}
        ImageSetting *getTree14() {return this->tree14;}
        ImageSetting *getTree15() {return this->tree15;}
        ImageSetting *getTree16() {return this->tree16;}
        ImageSetting *getTree17() {return this->tree17;}
        ImageSetting *getTree18() {return this->tree18;}
        ImageSetting *getTree19() {return this->tree19;}
        ImageSetting *getTree20() {return this->tree20;}
        ImageSetting *getTree21() {return this->tree21;}
        ImageSetting *getTree22() {return this->tree22;}
        ImageSetting *getTree23() {return this->tree23;}
        ImageSetting *getTree24() {return this->tree24;}
        ImageSetting *getTree25() {return this->tree25;}
        ImageSetting *getBushBerries1() {return this->bushBerries1;}
        ImageSetting *getBush1() {return this->bush1;}
        ImageSetting *getBush2() {return this->bush2;}
        ImageSetting *getBush3() {return this->bush3;}
        ImageSetting *getBush4() {return this->bush4;}
        ImageSetting *getBush5() {return this->bush5;}
        ImageSetting *getBush6() {return this->bush6;}
        ImageSetting *getBush7() {return this->bush7;}
        ImageSetting *getBush8() {return this->bush8;}
        ImageSetting *getBush9() {return this->bush9;}
    private:
        ImageSetting *tree1, *tree2, *tree3, *tree4, *tree5, *tree6, *tree7, *tree8, *tree9, *tree10;
        ImageSetting *tree11, *tree12, *tree13, *tree14, *tree15, *tree16, *tree17, *tree18, *tree19, *tree20;
        ImageSetting *tree21, *tree22, *tree23, *tree24, *tree25;
        ImageSetting *bushBerries1, *bush1, *bush2, *bush3, *bush4, *bush5, *bush6, *bush7, *bush8, *bush9;
};

class Forest5 : public Forest {
    Q_OBJECT
    public:
        Forest5(QString type, int posX, int posY, View *view);
        ImageSetting *getTree1() {return this->tree1;}
        ImageSetting *getTree2() {return this->tree2;}
        ImageSetting *getTree3() {return this->tree3;}
        ImageSetting *getTree4() {return this->tree4;}
        ImageSetting *getTree5() {return this->tree5;}
        ImageSetting *getTree6() {return this->tree6;}
        ImageSetting *getTree7() {return this->tree7;}
        ImageSetting *getTree8() {return this->tree8;}
        ImageSetting *getTree9() {return this->tree9;}
        ImageSetting *getTree10() {return this->tree10;}
        ImageSetting *getTree11() {return this->tree11;}
        ImageSetting *getTree12() {return this->tree12;}
        ImageSetting *getTree13() {return this->tree13;}
        ImageSetting *getTree14() {return this->tree14;}
        ImageSetting *getTree15() {return this->tree15;}
        ImageSetting *getTree16() {return this->tree16;}
        ImageSetting *getTree17() {return this->tree17;}
        ImageSetting *getTree18() {return this->tree18;}
        ImageSetting *getTree19() {return this->tree19;}
        ImageSetting *getTree20() {return this->tree20;}
        ImageSetting *getTree21() {return this->tree21;}
        ImageSetting *getTree22() {return this->tree22;}
        ImageSetting *getTree23() {return this->tree23;}
        ImageSetting *getTree24() {return this->tree24;}
        ImageSetting *getTree25() {return this->tree25;}
        ImageSetting *getTree26() {return this->tree26;}
        ImageSetting *getTree27() {return this->tree27;}
        ImageSetting *getTree28() {return this->tree28;}
        ImageSetting *getTree29() {return this->tree29;}
        ImageSetting *getTree30() {return this->tree30;}
        ImageSetting *getBushBerries1() {return this->bushBerries1;}
        ImageSetting *getBushBerries2() {return this->bushBerries2;}
    private:
        ImageSetting *tree1, *tree2, *tree3, *tree4, *tree5, *tree6, *tree7, *tree8, *tree9, *tree10;
        ImageSetting *tree11, *tree12, *tree13, *tree14, *tree15, *tree16, *tree17, *tree18, *tree19, *tree20;
        ImageSetting *tree21, *tree22, *tree23, *tree24, *tree25, *tree26, *tree27, *tree28, *tree29, *tree30;
        ImageSetting *bushBerries1, *bushBerries2;
};

class Forest6 : public Forest {
    Q_OBJECT
    public:
        Forest6(QString type, int posX, int posY, View *view);
        ImageSetting *getTree1() {return this->tree1;}
        ImageSetting *getTree2() {return this->tree2;}
        ImageSetting *getTree3() {return this->tree3;}
        ImageSetting *getTree4() {return this->tree4;}
        ImageSetting *getTree5() {return this->tree5;}
        ImageSetting *getTree6() {return this->tree6;}
        ImageSetting *getTree7() {return this->tree7;}
        ImageSetting *getTree8() {return this->tree8;}
        ImageSetting *getTree9() {return this->tree9;}
        ImageSetting *getTree10() {return this->tree10;}
        ImageSetting *getTree11() {return this->tree11;}
        ImageSetting *getTree12() {return this->tree12;}
        ImageSetting *getTree13() {return this->tree13;}
        ImageSetting *getTree14() {return this->tree14;}
        ImageSetting *getTree15() {return this->tree15;}
        ImageSetting *getTree16() {return this->tree16;}
        ImageSetting *getTree17() {return this->tree17;}
        ImageSetting *getTree18() {return this->tree18;}
        ImageSetting *getTree19() {return this->tree19;}
        ImageSetting *getTree20() {return this->tree20;}
        ImageSetting *getTree21() {return this->tree21;}
        ImageSetting *getTree22() {return this->tree22;}
        ImageSetting *getTree23() {return this->tree23;}
        ImageSetting *getTree24() {return this->tree24;}
        ImageSetting *getTree25() {return this->tree25;}
        ImageSetting *getTree26() {return this->tree26;}
        ImageSetting *getTree27() {return this->tree27;}
        ImageSetting *getTree28() {return this->tree28;}
        ImageSetting *getTree29() {return this->tree29;}
        ImageSetting *getTree30() {return this->tree30;}
        ImageSetting *getBushBerries1() {return this->bushBerries1;}
        ImageSetting *getBush1() {return this->bush1;}
    private:
        ImageSetting *tree1, *tree2, *tree3, *tree4, *tree5, *tree6, *tree7, *tree8, *tree9, *tree10;
        ImageSetting *tree11, *tree12, *tree13, *tree14, *tree15, *tree16, *tree17, *tree18, *tree19, *tree20;
        ImageSetting *tree21, *tree22, *tree23, *tree24, *tree25, *tree26, *tree27, *tree28, *tree29, *tree30;
        ImageSetting *bushBerries1, *bush1;
};

class Forest7 : public Forest {
    Q_OBJECT
    public:
        Forest7(QString type, int posX, int posY, View *view);
        ImageSetting *getTree1() {return this->tree1;}
        ImageSetting *getTree2() {return this->tree2;}
        ImageSetting *getTree3() {return this->tree3;}
        ImageSetting *getTree4() {return this->tree4;}
        ImageSetting *getTree5() {return this->tree5;}
        ImageSetting *getTree6() {return this->tree6;}
        ImageSetting *getTree7() {return this->tree7;}
        ImageSetting *getTree8() {return this->tree8;}
        ImageSetting *getTree9() {return this->tree9;}
        ImageSetting *getTree10() {return this->tree10;}
        ImageSetting *getTree11() {return this->tree11;}
        ImageSetting *getTree12() {return this->tree12;}
        ImageSetting *getTree13() {return this->tree13;}
        ImageSetting *getTree14() {return this->tree14;}
        ImageSetting *getTree15() {return this->tree15;}
        ImageSetting *getTree16() {return this->tree16;}
        ImageSetting *getTree17() {return this->tree17;}
        ImageSetting *getTree18() {return this->tree18;}
        ImageSetting *getTree19() {return this->tree19;}
        ImageSetting *getTree20() {return this->tree20;}
        ImageSetting *getTree21() {return this->tree21;}
        ImageSetting *getTree22() {return this->tree22;}
        ImageSetting *getTree23() {return this->tree23;}
        ImageSetting *getTree24() {return this->tree24;}
        ImageSetting *getTree25() {return this->tree25;}
        ImageSetting *getTree26() {return this->tree26;}
        ImageSetting *getTree27() {return this->tree27;}
        ImageSetting *getTree28() {return this->tree28;}
        ImageSetting *getTree29() {return this->tree29;}
        ImageSetting *getTree30() {return this->tree30;}
        ImageSetting *getBushBerries1() {return this->bushBerries1;}
        ImageSetting *getBushBerries2() {return this->bushBerries2;}
        ImageSetting *getBushBerries3() {return this->bushBerries3;}
        ImageSetting *getBush1() {return this->bush1;}
        ImageSetting *getBush2() {return this->bush2;}
        ImageSetting *getBush3() {return this->bush3;}
        ImageSetting *getBush4() {return this->bush4;}
        ImageSetting *getBush5() {return this->bush5;}
        ImageSetting *getBush6() {return this->bush6;}
        ImageSetting *getBush7() {return this->bush7;}
        ImageSetting *getSouche1() {return this->souche1;}
        ImageSetting *getSouche2() {return this->souche2;}
        ImageSetting *getSouche3() {return this->souche3;}
    private:
        ImageSetting *tree1, *tree2, *tree3, *tree4, *tree5, *tree6, *tree7, *tree8, *tree9, *tree10;
        ImageSetting *tree11, *tree12, *tree13, *tree14, *tree15, *tree16, *tree17, *tree18, *tree19, *tree20;
        ImageSetting *tree21, *tree22, *tree23, *tree24, *tree25, *tree26, *tree27, *tree28, *tree29, *tree30;
        ImageSetting *bushBerries1, *bushBerries2, *bushBerries3, *bush1, *bush2, *bush3, *bush4, *bush5, *bush6, *bush7;
        ImageSetting *souche1, *souche2, *souche3;
};

#endif // Setting_H
