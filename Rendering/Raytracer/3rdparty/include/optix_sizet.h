
/*
 * Copyright (c) 2010 NVIDIA Corporation.  All rights reserved.
 *
 * NVIDIA Corporation and its licensors retain all intellectual property and proprietary
 * rights in and to this software, related documentation and any modifications thereto.
 * Any use, reproduction, disclosure or distribution of this software and related
 * documentation without an express license agreement from NVIDIA Corporation is strictly
 * prohibited.
 *
 * TO THE MAXIMUM EXTENT PERMITTED BY APPLICABLE LAW, THIS SOFTWARE IS PROVIDED *AS IS*
 * AND NVIDIA AND ITS SUPPLIERS DISCLAIM ALL WARRANTIES, EITHER EXPRESS OR IMPLIED,
 * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE.  IN NO EVENT SHALL NVIDIA OR ITS SUPPLIERS BE LIABLE FOR ANY
 * SPECIAL, INCIDENTAL, INDIRECT, OR CONSEQUENTIAL DAMAGES WHATSOEVER (INCLUDING, WITHOUT
 * LIMITATION, DAMAGES FOR LOSS OF BUSINESS PROFITS, BUSINESS INTERRUPTION, LOSS OF
 * BUSINESS INFORMATION, OR ANY OTHER PECUNIARY LOSS) ARISING OUT OF THE USE OF OR
 * INABILITY TO USE THIS SOFTWARE, EVEN IF NVIDIA HAS BEEN ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGES
 */

#ifndef __optix_sizet_h__
#define __optix_sizet_h__

#if !defined(_WIN32)
  #include <sys/types.h>
#endif

#include "internal/optix_declarations.h"  /* For RT_HOSTDEVICE */
#include "optixu/optixu_vector_functions.h"
#include "optixu/optixu_math_namespace.h"

#ifdef __cplusplus
namespace optix {
#endif
  
#if defined(__x86_64) || defined(AMD64) || defined(_M_AMD64)

  typedef struct {
    size_t x;
  } size_t1;
  typedef struct size_t2 {
#ifdef __cplusplus
    RT_HOSTDEVICE size_t2() { }
    RT_HOSTDEVICE explicit size_t2( size_t s ) { x = y = s; }
    RT_HOSTDEVICE size_t2( uint2 u ) { x = u.x; y = u.y; }
#endif
    size_t x,y;
  } size_t2;
  typedef struct size_t3 {
#ifdef __cplusplus
    RT_HOSTDEVICE size_t3() { }
    RT_HOSTDEVICE explicit size_t3( size_t s ) { x = y = z = s; }
    RT_HOSTDEVICE size_t3( uint3 u ) { x = u.x; y = u.y; z = u.z; }
#endif
    size_t x,y,z;
  } size_t3;
  typedef struct size_t4 {
#ifdef __cplusplus
    RT_HOSTDEVICE size_t4() { }
    RT_HOSTDEVICE explicit size_t4( size_t s ) { x = y = z = w = s; }
    RT_HOSTDEVICE size_t4( uint4 u ) { x = u.x; y = u.y; z = u.z; w = u.w; }
#endif
    size_t x,y,z,w;
  } size_t4;

  __inline__ RT_HOSTDEVICE size_t2 make_size_t2( size_t x, size_t y ) {
    size_t2 ret;
    ret.x = x;
    ret.y = y;
    return ret;
  }
  __inline__ RT_HOSTDEVICE size_t3 make_size_t3( size_t x, size_t y, size_t z ) {
    size_t3 ret;
    ret.x = x;
    ret.y = y;
    ret.z = z;
    return ret;
  }
  __inline__ RT_HOSTDEVICE size_t4 make_size_t4( size_t x, size_t y, size_t z, size_t w ) {
    size_t4 ret;
    ret.x = x;
    ret.y = y;
    ret.z = z;
    ret.w = w;
    return ret;
  }
  
  /* additional constructors */
  inline RT_HOSTDEVICE size_t4 make_size_t4(unsigned int s)
  {
      return make_size_t4(s, s, s, s);
  }
  inline RT_HOSTDEVICE size_t3 make_size_t3(unsigned int s)
  {
      return make_size_t3(s, s, s);
  }
  inline RT_HOSTDEVICE size_t2 make_size_t2(unsigned int s)
  {
      return make_size_t2(s, s);
  }
  inline RT_HOSTDEVICE size_t2 make_size_t2(size_t4 st)
  {
      return make_size_t2(st.x, st.y);
  }
  inline RT_HOSTDEVICE size_t make_size_t(size_t4 v0)
  {
      return (size_t) v0.x;
  }

  inline RT_HOSTDEVICE size_t4 make_size_t4(uint4 s)
  {
      return make_size_t4(s.x, s.y, s.z, s.w);
  }
  
  inline RT_HOSTDEVICE float2 make_float2(size_t2 st)
  {
    return make_float2( (float) st.x, (float) st.y );
  }

#else
  typedef uint1 size_t1;
  typedef uint2 size_t2;
  typedef uint3 size_t3;
  typedef uint4 size_t4;
  #define make_size_t4 make_uint4
  #define make_size_t3 make_uint3
  #define make_size_t2 make_uint2
  #define make_size_t1 make_uint1
#endif

#ifdef __cplusplus
}
#endif

#endif
