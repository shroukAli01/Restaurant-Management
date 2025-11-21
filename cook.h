#pragma once
#include <iostream>

using namespace std;

class Order;


class Cook
{
private:
    int ID;
    char Type;   // (V/N/G)      
    int Speed;

    int BO;      //Break Order   
    int BreakDuration;
    int BreakRemaining;
    int OrdersSinceBreak;
    bool Available;

    Order* CurrentOrder;
    int RemainingTime;

public:
    //Constructor 

    Cook(int id = 0, char type = 'N', int speed = 0, int bo = 0, int breakDur = 0)
    {
        ID = id;
        Type = type;
        Speed = speed;

        BO = bo;
        BreakDuration = breakDur;
        BreakRemaining = 0;
        OrdersSinceBreak = 0;
        Available = true;

        CurrentOrder = nullptr;
        RemainingTime = 0;
    }

    //setter
    void SetID(int id) { ID = id; }

    void SetType(char type) { Type = type; }

    void SetSpeed(int s) { Speed = s; }

    void SetBO(int bo) { BO = bo; }

    void SetBreakDuration(int bd) { BreakDuration = bd; }

    void SetAvailable(bool a) { Available = a; }

    //getter
    int  GetID() const { return ID; }
    char GetType() const { return Type; }
    int  GetSpeed() const { return Speed; }
    int  GetBO() const { return BO; }
    int  GetBreakDuration() const { return BreakDuration; }
    int  GetBreakRemaining() const { return BreakRemaining; }


    bool IsAvailable() const { return Available; }

    Order* GetCurrentOrder() const { return CurrentOrder; }
    int GetRemainingTime() const { return RemainingTime; }




    void AssignOrder(Order* o, int orderSize)
    {
        CurrentOrder = o;
        Available = false;

        RemainingTime = (orderSize + Speed - 1) / Speed;
    }

    void UpdateCooking()
    {
        if (!Available && RemainingTime > 0)
        {
            RemainingTime--;

            if (RemainingTime == 0)
            {
                CurrentOrder = nullptr;
                Available = true;
            }
        }
    }

    bool IsBusy() const
    {
        return !Available;
    }

    // break operations

    void StartBreak()
    {
        Available = false;
        BreakRemaining = BreakDuration;
    }

    void UpdateBreak()
    {
        if (BreakRemaining > 0)
        {
            BreakRemaining--;
            if (BreakRemaining == 0)
                ResetBreak();
        }
    }

    bool InBreak() const
    {
        return BreakRemaining > 0;
    }

    void ResetBreak()
    {
        BreakRemaining = 0;
        OrdersSinceBreak = 0;
        Available = true;
    }

    void OrderAssigned()
    {
        OrdersSinceBreak++;

        if (OrdersSinceBreak >= BO)
            StartBreak();
    }

    void SetAvailable(bool a)
    {
        Available = a;
    }


};
