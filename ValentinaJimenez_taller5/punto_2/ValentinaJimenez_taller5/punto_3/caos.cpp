#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

double e = 0.001;

// funciones

double dq1(double p1){
  return p1;
}

double dq2(double p2){
  return p2;
}

double dp1(double q1){

  double u;
  u = 4*(q1*q1) + (e*e);
  double dp;
  dp= -2*q1/pow(u,3/2);
  return dp;
}

double dp2(double q1, double q2){
  double a,w, b, q, i, l, z,c;
  q= q1+q2;
  w= q1-q2;
  i= pow(q, 2);
  l= pow(w,2);
  z= q / pow((i+ pow(e,2)/4.0),3/2);
  c= w / pow((l+ pow(e,2)/4.0),3/2);
  double dp2;
  dp2 = c-z;
  return dp2;
}

int main(){

  double dt, t, n, a, q1, q2, q10, p1, p2;

  dt = 0.006;
  t = 3000.0;
  n = t/dt;
  a = 1.0/(2.0*sqrt(2.0));

  q1 = a;
  q10 = 0;
  q2 = -1.0*a;
  double q20=0.0;

  p1 = 0;
  p2 = 0;


  for(int i = 1; i < n; i++){

    double qant=q1;
    double k1q1 = dq1(p1);
    double k1q2 = dq2(p2);
    double k1p1 = dp1(q1);
    double k1p2 = dp2(q1,q2);

    double k2q1 = dq1(p1+k1q1*(dt/2.0));
    double k2q2 = dq2(p2+k1q2*(dt/2.0));
    double k2p1 = dp1(q1+k1p1*(dt/2.0));
    double k2p2 = dp2(q1+k1p2*(dt/2.0),q2+k1p2*(dt/2.0));

    double k3q1 = dq1(p1+k2q1*(dt/2.0));
    double k3q2 = dq2(p2+k2q2*(dt/2.0));
    double k3p1 = dp1(q1+k2p1*(dt/2.0));
    double k3p2 = dp2(q1+k2p2*(dt/2.0),q2+k2p2*(dt/2.0));

    double k4q1 = dq1(p1+k3q1*dt);
    double k4q2 = dq2(p2+k3q2*dt);
    double k4p1 = dp1(q1+k3p1*dt);
    double k4p2 = dp2(q1+k3p2*dt,q2+k3p2*dt);

    q1 += (dt/6.0)*(k1q1+2*k2q1+2*k3q1+k4q1);
    q2 += (dt/6.0)*(k1q2+2*k2q2+2*k3q2+k4q2);
    p1 += (dt/6.0)*(k1p1+2*k2p1+2*k3p1+k4p1);
    p2 += (dt/6.0)*(k1p2+2*k2p2+2*k3p2+k4p2);

    /*cout << i*dt << " " << p2 << " " << q2 << " " << q1 << endl;*/

    if( q1*q2 <0 ){
      cout << q2 << " " << p2 << endl;
      }
  
    }

  return 0;

}
