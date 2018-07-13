#ifndef MODELS_GEOMETRY_HPP_
#define MODELS_GEOMETRY_HPP_

namespace ExcellentPuppy {
	namespace Modeling {
		class Geometry {
			public:
				Geometry();
				virtual ~Geometry();

				virtual void render() const=0;
		};
	} /* namespace Modeling */
} /* namespace ExcelllentPuppy */

#endif /* MODELS_GEOMETRY_HPP_ */
