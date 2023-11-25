#ifndef IView_h
#define IView_h



class IView
{
public:
    virtual void update() = 0;
    virtual void updateChooseLevel() = 0;
    virtual void updateInvalidLevel() = 0;
    virtual void updateEndGame() = 0;
};


#endif