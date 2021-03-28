#ifndef __USER_H__
#define __USER_H__

class SlotUser
{
private:
    int coin;
    int betting;
public:
    SlotUser();
    SlotUser(int c);
    ~SlotUser();
    int getCoin();
    void setCoin(int c);
    int getBet();
    void setBet(int c);
};

#endif 
