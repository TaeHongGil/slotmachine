#include "MainMenu.h";

bool MainMenu::init()
{
    if (!Layer::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    float x;
    float y;

    auto startLabel = Label::createWithTTF("START", "fonts/Marker Felt.ttf", 24);
    auto startItem = MenuItemLabel::create(startLabel, CC_CALLBACK_1(MainMenu::start, this));
    x = origin.x + visibleSize.width / 3;
    y = origin.y + visibleSize.height / 6;
    startItem->setPosition(Vec2(x, y));
    auto closeLabel = Label::createWithTTF("EXIT", "fonts/Marker Felt.ttf", 24);
    auto closeItem = MenuItemLabel::create(closeLabel, CC_CALLBACK_1(MainMenu::exit, this));
    x = origin.x + visibleSize.width / 1.5;
    y = origin.y + visibleSize.height / 6;
    closeItem->setPosition(Vec2(x, y));

    auto menu = Menu::create(startItem, closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    return true;
}

void MainMenu::start(cocos2d::Ref* pSender)
{
    auto scene = SlotMachine::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(1, scene, Color3B(0, 0, 0)));
}

void MainMenu::exit(Ref* pSender)
{
    Director::getInstance()->end();
}
