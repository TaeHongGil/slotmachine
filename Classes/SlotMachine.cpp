#include "SlotMachine.h";

Scene* SlotMachine::createScene()
{
    Scene* scene = Scene::create();
    SlotMachine* layer1 = SlotMachine::create();
    scene->addChild(layer1);
    return scene;
}

bool SlotMachine::init()
{
    if (!Layer::init())
    {
        return false;
    }

    float x, y;
    //spin
    spinLabel = Label::createWithTTF("SPIN", "fonts/Marker Felt.ttf", 20);
    auto spinItem = MenuItemLabel::create(spinLabel, CC_CALLBACK_0(SlotMachine::spinEvent, this));
    x = origin.x + visibleSize.width / 2;
    y = origin.y + visibleSize.height / 6;
    spinItem->setPosition(Vec2(x, y));

    //betting
    f = StringUtils::format("Betting : %d", user.getBet());
    betLabel = Label::createWithTTF(f, "fonts/Marker Felt.ttf", 15);
    x = origin.x + visibleSize.width / 1.7;
    y = origin.y + visibleSize.height / 1.1;
    betLabel->setPosition(Vec2(x, y));
    this->addChild(betLabel, 1);

    auto betLabel1 = Label::createWithTTF("up","fonts/Marker Felt.ttf", 15);
    auto betItem1 = MenuItemLabel::create(betLabel1, CC_CALLBACK_0(SlotMachine::bettingUp, this));
    x = origin.x + visibleSize.width / 1.3;
    betItem1->setPosition(Vec2(x, y));
    auto betLabel2 = Label::createWithTTF("down", "fonts/Marker Felt.ttf", 15);
    auto betItem2 = MenuItemLabel::create(betLabel2, CC_CALLBACK_0(SlotMachine::bettingDown, this));
    x = origin.x + visibleSize.width / 1.2;
    betItem2->setPosition(Vec2(x, y));

    m = Menu::create(spinItem, betItem1, betItem2,NULL);
    m->setPosition(Vec2::ZERO);
    this->addChild(m, 1);

    //coin
    f = StringUtils::format("Coin : %d", user.getCoin());
    coinLabel = Label::createWithTTF(f, "fonts/Marker Felt.ttf", 20);
    x = origin.x + visibleSize.width / 9;
    y = origin.y + visibleSize.height / 1.1;
    coinLabel->setPosition(Vec2(x, y));
    this->addChild(coinLabel, 1);

    //초기 이미지 
    x = origin.x + visibleSize.width / 2.9;
    y = origin.y + visibleSize.height / 2;
    for (int i = 0; i < LINE; ++i) {
        std::string f = StringUtils::format("%d_0.png", i + 1); 
        spr[i] = Sprite::create(f);
        spr[i]->setScale(0.3);
        spr[i]->setPosition(Vec2(x, y));
        this->addChild(spr[i], 1);
        x += spr[0]->getContentSize().width / 2;
    }

    //슬롯머신 이미지
    x = origin.x + visibleSize.width / 1.9;
    y = origin.y + visibleSize.height / 2.04;
    auto back1 = Sprite::create("machine.png");
    back1->setScale(0.4);
    back1->setScaleY(0.25);
    back1->setPosition(Vec2(x, y));
    this->addChild(back1, 0);

    return true;
}

void SlotMachine::spinEvent()
{
    float random[LINE];
    Sequence* seq;
    Animation* animation;
    Animate* animate;
    Repeat* rep;
    std::vector<int> vList{ 92,2,2,2,2 };
    count = 0;
    user.setCoin(user.getCoin() - (1 * user.getBet()));

    m->setEnabled(false);
    f = StringUtils::format("coin : %d", user.getCoin());
    coinLabel->setString(f);

    //가중치사용 랜덤
    for (int i = 0; i < LINE; i++) {
        index[i] = makeRandNum(vList) + 1;
    }
    CallFunc* callback2 = CallFunc::create(CC_CALLBACK_0(SlotMachine::slotResult, this));

    for (int i = 0; i < LINE; i++) {
        CallFunc* callback1 = CallFunc::create(CC_CALLBACK_0(SlotMachine::setImage, this, i));
        random[i] = makeRandNum() / 500.0;
        animation = Animation::create();
        animation->setDelayPerUnit(random[i]);
        for (int j = 1; j < 6; j++) {
            f = StringUtils::format("%d_0.png", j);
            animation->addSpriteFrameWithFile(f);
            f = StringUtils::format("%d_1.png", j);
            animation->addSpriteFrameWithFile(f);
        }
        animate = Animate::create(animation);
        rep = Repeat::create(animate, 4);
        seq = Sequence::create(rep, callback1, callback2, nullptr);
        spr[i]->runAction(seq);
    }
}

void SlotMachine::setImage(int i){
    f = StringUtils::format("%d_0.png", index[i]);
    spr[i]->setTexture(f);
}

void SlotMachine::slotResult() {
    int check;

    count++;
    if (count == LINE) {
        m->setEnabled(true);
        switch (indexCheck(index)) 
        {
            case 1:
                user.setCoin(user.getCoin() + (5 * user.getBet()));
                break;
            case 2:
                user.setCoin(user.getCoin() + (10 * user.getBet()));
                break;
            case 3:
                user.setCoin(user.getCoin() + (50 * user.getBet()));
                break;
            case 4:
                user.setCoin(user.getCoin() + (200 * user.getBet()));
                break;
            case 5:
                user.setCoin(user.getCoin() + (7777 * user.getBet()));
                break;
            default:
                break;
        }
        f = StringUtils::format("coin : %d", user.getCoin());
        coinLabel->setString(f);
        if (user.getCoin() < user.getBet())
        {
            user.setBet(1);
            f = StringUtils::format("Betting : %d", user.getBet());
            betLabel->setString(f);
        }
        if (user.getCoin() <= 0)
        {
            spinLabel->setString("Game Over");
            spinLabel->setPosition(Vec2(-visibleSize.width / 15, 0));
            m->setEnabled(false);
        }
    }
}

void SlotMachine::bettingUp() {
    if (user.getBet() < user.getCoin())
        user.setBet(user.getBet() + 1);
    f = StringUtils::format("Betting : %d", user.getBet());
    betLabel->setString(f);
}

void SlotMachine::bettingDown() {
    if (user.getBet() > 1)
        user.setBet(user.getBet() - 1);
    f = StringUtils::format("Betting : %d", user.getBet());
    betLabel->setString(f);
}