#include "MainScene.h";
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")

Scene* Main::createScene()
{
    Scene* scene = Scene::create();
    Main* layer1 = Main::create();
    MainMenu* layer2 = MainMenu::create();
    scene->addChild(layer1);
    scene->addChild(layer2);
    return scene;
}

bool Main::init()
{
    if (!Layer::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    float x;
    float y;

    auto nameLabel = Label::createWithTTF("SLOT MACHINE", "fonts/Marker Felt.ttf", 24);
    x = origin.x + visibleSize.width / 2;
    y = origin.y + visibleSize.height/1.2;
    nameLabel->setPosition(Vec2(x, y));
    this->addChild(nameLabel, 1);

    x = origin.x + visibleSize.width/2;
    y = origin.y + visibleSize.height / 2;

    auto spr = Sprite::create("1_0.png");
    spr->setPosition(Vec2(x, y));
    this->addChild(spr, 1);

    auto animation = Animation::create();
    animation->setDelayPerUnit(0.3f);
    for (int i = 1; i < 6; i++) {
        std::string fileName = StringUtils::format("%d_0.png", i);
        animation->addSpriteFrameWithFile(fileName);
    }
    auto animate = Animate::create(animation);
    auto rep = RepeatForever::create(animate);
    spr->runAction(rep);
    return true;
}
