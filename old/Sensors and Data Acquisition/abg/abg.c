#include "abg.h"

/*
 * predictState:
 * predict the next state using the state extrapolation equations
 * returns the state prediction
 */
State predictState(State currentState, double deltaT)
{
  State predictedState;   // Create predicted state

  predictedState.n = currentState.n+1;
  predictedState.m = currentState.m;

  // Update x, x', and x'' with state update equation 1
  predictedState.x0 = currentState.x0 + (currentState.x1 * deltaT) + currentState.x2 * (deltaT * deltaT);
  predictedState.x1 = currentState.x1 + currentState.x2 * deltaT;
  predictedState.x2 = currentState.x2;

  // copy over alpha beta and gamma
  predictedState.alpha = currentState.alpha;
  predictedState.beta = currentState.beta;
  predictedState.gamma = currentState.gamma;

  return predictedState;
}

/*
 * updateState:
 * use the state update equations to update the current state
 * returns the current state estimate
 */
State updateState(State previousState, double measuredX, double deltaT)
{
  State stateEstimate;

  stateEstimate.n = previousState.n;
  stateEstimate.m = previousState.m+1;
  
  // Update the state
  stateEstimate.x0 = previousState.x0 + previousState.alpha * (measuredX - previousState.x0);
  stateEstimate.x1 = previousState.x1 + previousState.beta * ((measuredX - previousState.x0) / deltaT);
  stateEstimate.x2 = previousState.x2 + 
   previousState.gamma * ((measuredX - previousState.x0) / ((deltaT*deltaT) / 2));

  // copy over alpha beta and gamma
  stateEstimate.alpha = previousState.alpha;
  stateEstimate.beta = previousState.beta;
  stateEstimate.gamma = previousState.gamma;

  return stateEstimate;
}
