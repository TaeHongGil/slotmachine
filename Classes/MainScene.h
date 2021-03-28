#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "Header.h";
USING_NS_CC;

class Main : public Layer
{
public:
    static Scene* createScene();

    virtual bool init();

    CREATE_FUNC(Main);
};

#endif 
