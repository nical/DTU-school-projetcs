// 02562 Rendering Framework
// Code from GEL (http://www.imm.dtu.dk/GEL/)
// Modified by Jeppe Revall Frisvad to suit framework 
// and to use CUDA/OptiX matrix-vector types.
// Copyright (c) DTU Informatics 2011

#ifndef TRIMESH_H
#define TRIMESH_H

#include <string>
#include <vector>
#include <optix_world.h>
#include "IndexedFaceSet.h"
#include "ObjMaterial.h"
#include "HitInfo.h"
#include "Object3D.h"

/** \brief A Triangle Mesh struct. 

    This struct contains three indexed face sets, one for geometry,
		textures, and normals. It also contains a vector of materials and a
		vector of texture maps.

		A number of functions are defined allowing for rendering of the triangle
		mesh. */
class TriMesh : public Object3D
{
	public:
	
	// ------- DATA -------

	/// Name of model
	std::string name;
	
	/// Indexed face set for the actual geometry
	IndexedFaceSet geometry;

	/// Indexed face set for the normals
	IndexedFaceSet normals;

	/// Indexed face set for the texture coordinates.
	IndexedFaceSet texcoords;

	/// Material indices for all faces
	std::vector<int> mat_idx;

	/// Texture indices for all faces
	std::vector<int> tex_idx;

	/// Vector of materials
	std::vector<ObjMaterial> materials;

	// -------- FUNCTIONS -----------

  /// Compute intersection of ray with a triangle in the mesh
  virtual bool intersect(const optix::Ray& r, HitInfo& hit, unsigned int prim_idx) const;

  /// Apply a transformation matrix to the mesh
  virtual void transform(const optix::Matrix4x4& m);

  /// Get an axis aligned bounding box for the model.
  virtual optix::Aabb compute_bbox() const;

  /// Get number of triangles in mesh
  virtual unsigned int get_no_of_primitives() const { return geometry.no_faces(); }

  /// Get the bounding box of a triangle in the mesh
  virtual optix::Aabb get_primitive_bbox(unsigned int prim_idx) const;

	/// Returns true if at least one normal has been defined.
	bool has_normals() const 
	{
		return normals.no_faces()>0;
	}
	
	/// Find a material from its name
	unsigned int find_material(const std::string&) const;

	/// Compute normals for the mesh. Does not check if there are normals.
	void compute_normals();
};

#endif // TRIMESH_H
