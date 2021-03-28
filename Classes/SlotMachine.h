#ifndef __SLOT_MACHINE_SCENE_H__
#define __SLOT_MACHINE_SCENE_H__

#include "Header.h";

USING_NS_CC;

class SlotMachine : public Layer
{
private:
    SlotUser user;
    int index[LINE];
    Sprite* spr[LINE];
    int count = 0;
    std::string f;
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    Label* spinLabel;
    Label* coinLabel;
    Label* betLabel;
    Menu* m;
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    void spinEvent();
    void setImage(int i);
    void slotResult();
    void bettingUp();
    void bettingDown();

    CREATE_FUNC(SlotMachine);
};

#endif 
