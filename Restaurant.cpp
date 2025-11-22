#include "Restaurant.h"




void Restaurant::SimpleSimulator()
{

    currentTimeStep = 1;

    while (!events.isEmpty() ||
           !waitingNormal.isEmpty() ||
           !waitingVegan.isEmpty()  ||
           !waitingVIP.isEmpty()    ||
           !inService.isEmpty())
    {
        ExecuteEvents();
      
        MoveOrdersToInService();

        if (currentTimeStep % 5 == 0)
            MoveToFinishedEvery5Steps();
      
        PrintState();
        waitForClick();

        currentTimeStep++;
    }
}

void Restaurant::ExecuteEvents()
{
  
}
void Restaurant::MoveOrdersToInService()
{
  
}

void Restaurant::MoveOneOrderToFinished()
{
  
}
void Restaurant::PrintState()
{
  
}
