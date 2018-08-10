#ifndef ENTITIES_OBJECTS_TABLE_HPP_
#define ENTITIES_OBJECTS_TABLE_HPP_

#include "../CompositeEntity.hpp"

namespace ExcellentPuppy {
	namespace Modeling {
		class Material;
	}
	namespace Entities {
		/**
		 * A table entity, made of 4 leg models and 1 table top model.
		 * The entity's origin is the table's floor plane, center of table
		 */
		class Table: public CompositeEntity {
			private:
				// The width (technically, height) of the table top
				static const GLfloat TABLE_TOP_WIDTH;
				// The x,z width of the leg
				static const GLfloat TABLE_LEG_WIDTH;
				// The height of each leg
				static const GLfloat TABLE_LEG_HEIGHT;
				// The width of the table (and also the table top model)
				static const GLfloat TABLE_WIDTH;
				// The depth of the table (and also the table top model)
				static const GLfloat TABLE_DEPTH;
				// The total height of the table
				static const GLfloat TABLE_HEIGHT;
				// The collision radius of the table legs
				static const GLfloat LEG_COLLISION_RADIUS;

				// The legs of this table
				std::list<Entity*> _tableLegs;

			public:
				std::list<Entity*> const & getTableLegs();

				Table(Modeling::Material* tableMaterial,
						const GEvector& position = {},
						const GEvector& rotation = {},
						const GEvector& scaling = {1, 1, 1});
				virtual ~Table();
		};
	
	} /* namespace Entities */
} /* namespace ExcellentPuppy */

#endif /* ENTITIES_OBJECTS_TABLE_HPP_ */
