#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;
  
  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;
  
  prev_cte = 0.0;
  
  

}

void PID::UpdateError(double cte) {
  p_error = cte;
  d_error = cte - prev_cte;
  i_error += cte;
  
  prev_cte = cte;
  

}

double PID::TotalError() {
  return ( p_error * Kp ) + (d_error * Kd) + (i_error * Ki);
}