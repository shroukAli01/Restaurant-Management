#pragma once
#include <iostream>

using name space std;


class Cook
{
private:
    int ID;             
    char Type;   // (V/N/G)      
    int Speed;          

    int BO;             
    int BreakDuration;  
    int BreakRemaining; 
   
    int OrdersSinceBreak;
    bool Available;     

public:
//Constructor 
    Cook(int id = 0, char type = 'N', int speed = 0,
        int bo = 0, int breakDur = 0);
//setter
    void SetID(int id);
    void SetType(char type);
    void SetSpeed(int s);
    void SetBO(int bo);
    void SetBreakDuration(int bd);
    void SetAvailable(bool a);

//gette
    int  GetID() const;
    char GetType() const;
    int  GetSpeed() const;
    int  GetBO() const;
    int  GetBreakDuration() const;
    int  GetBreakRemaining() const;



 //  Break operation
   void StartBreak();        
   void UpdateBreak();         // update remaining break time
   bool InBreak() const;    
   void ResetBreak();          // Reset after finishing break
   
   void OrderAssigned();    

   bool IsAvailable() const;
