#ifndef CFG_H_INCLUDED
#define CFG_H_INCLUDED

class cfg
{
    public:
        cfg();
        virtual ~cfg();
        int xres;
        int yres;
        float gravity;
        float speed;
        double maxHorizontalMovement;
        double maxVerticalMovement;
        float terminalVelocity;
        float terminalHorizontalVelocity;

    protected:
    private:
};

#endif // CFG_H_INCLUDED
