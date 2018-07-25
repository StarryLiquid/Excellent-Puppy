#ifndef MODELS_GEOMETRY_HPP_
#define MODELS_GEOMETRY_HPP_

namespace ExcellentPuppy {
	namespace Modeling {
		/**
		 * The geometry of a model, usually expressed by a list of face vertices
		 */
		class Geometry {
			public:
				Geometry();
				virtual ~Geometry();

				// Render the geometry
				virtual void render() const=0;
		};
	} /* namespace Modeling */
} /* namespace ExcelllentPuppy */

#endif /* MODELS_GEOMETRY_HPP_ */
