// 02562 Rendering Framework
// Written by Jeppe Revall Frisvad, 2011
// Copyright (c) DTU Informatics 2011

#include <optix_world.h>
#include "HitInfo.h"
#include "ObjMaterial.h"
#include "fresnel.h"
#include "RayTracer.h"

using namespace optix;

bool RayTracer::trace_reflected(const Ray& in, const HitInfo& in_hit, Ray& out, HitInfo& out_hit) const
{
  // Initialize the reflected ray and trace it. Set out_hit.ray_ior and out_hit.trace_depth.
  // Return true if the reflected ray hit anything.
  return false;
}

bool RayTracer::trace_refracted(const Ray& in, const HitInfo& in_hit, Ray& out, HitInfo& out_hit) const
{
  // Initialize the refracted ray and trace it. Set out_hit.ray_ior and out_hit.trace_depth.
  // Return true if the refracted ray hit anything.
  // Remember that the function must handle total internal reflection.
  return false;
}

bool RayTracer::trace_refracted(const Ray& in, const HitInfo& in_hit, Ray& out, HitInfo& out_hit, float& R) const
{
  // Initialize the refracted ray and trace it. Set out_hit.ray_ior and out_hit.trace_depth.
  // Compute the Fresnel reflectance (see fresnel.h) and return it in R.
  // Return true if the refracted ray hit anything.
  // Remember that the function must handle total internal reflection.
  return false;
}

float RayTracer::get_ior_out(const Ray& in, const HitInfo& in_hit, float3& dir, float3& normal, float& cos_theta_in) const
{
  normal = in_hit.shading_normal;
  dir = -in.direction;
  cos_theta_in = dot(normal, dir);
	if(cos_theta_in < 0.0)
	{
    normal = -normal;
		cos_theta_in = -cos_theta_in;
    return 1.0f;
  }
  const ObjMaterial* m = in_hit.material;
  return m ? m->ior : 1.0f;
}
