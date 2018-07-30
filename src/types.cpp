#include "types.hpp"

// Check that the compiler did not pad any of the  structs
static_assert(sizeof(GEtexCoords) == sizeof(GLfloat)*2, "Struct GEtexCoords is padded ");
static_assert(sizeof(GEvector) == sizeof(GLfloat)*3, "Struct GEvector is padded ");
static_assert(sizeof(GErotation) == sizeof(GEvector) + sizeof(GLfloat), "Struct GErotation is padded ");
