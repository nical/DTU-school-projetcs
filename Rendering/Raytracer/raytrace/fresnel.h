// 02562 Rendering Framework
// Written by Jeppe Revall Frisvad, 2011
// Copyright (c) DTU Informatics 2011

#ifndef FRESNEL_H
#define FRESNEL_H

inline double fresnel_r_s(double cos_theta1, double cos_theta2, double ior1, double ior2)
{
  // Compute the perpendicularly polarized component of the Fresnel reflectance
  return 0.0;
}

inline double fresnel_r_p(double cos_theta1, double cos_theta2, double ior1, double ior2)
{
  // Compute the parallelly polarized component of the Fresnel reflectance
  return 0.0;
}

inline double fresnel_R(double cos_theta1, double cos_theta2, double ior1, double ior2)
{
  // Compute the Fresnel reflectance using fresnel_r_s(...) and fresnel_r_p(...)
  return 0.0;
}

#endif // FRESNEL_H
