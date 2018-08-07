#include "types2d.hpp"

// Check that the compiler did not pad any of the  structs
static_assert(sizeof(GE2Dvector) == sizeof(GLdouble)*2, "Struct GE2DVector is padded ");
