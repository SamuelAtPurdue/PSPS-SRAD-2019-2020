typedef struct {
  int n;        // number of the measurement when state is predicting
  int m;        // number when state was calculated

  double x0;    // x
  double x1;    // dx/dt
  double x2;    // d2x/dt2

  float alpha;  // alpha parameter
  float beta;   // beta parameter
  float gamma;  // gamma parameter
} State;

State predictState(State currentState, double deltaT);    // Predict the next state
State updateState(State previousState, double measuredX, double deltaT);    // update the state
