#ifndef __MAIN_MENU_H__
#define __MAIN_MENU_H__

#include "Header.h";
USING_NS_CC;

class MainMenu : public Layer
{
public:
    virtual bool init();

    // a selector callback
    void start(Ref* pSender);
    void exit(Ref* pSender);

    CREATE_FUNC(MainMenu);

};

#endif 
