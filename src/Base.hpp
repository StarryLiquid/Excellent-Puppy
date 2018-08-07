#ifndef EXCELLENTPUPPY_BASE_HPP_
#define EXCELLENTPUPPY_BASE_HPP_

#include <unordered_set>

namespace ExcellentPuppy {
	/**
	 * A base class for all classes in the engine.
	 * Holds a list of objects to delete along this object
	 */
	class Base {
		private:
			// Dependents objects to delete when this object deletes
			std::unordered_set<Base *> _dependents;
			// Dependents object arrayss to delete when this object deletes
			std::unordered_set<Base *> _dependentArrays;

		public:
			std::unordered_set<Base *>* const getDependents();
			std::unordered_set<Base *>* const getDependentArrays();

			Base();
			virtual ~Base();
	};
} /* namespace ExcellentPuppy */

#endif /* BASE_HPP_ */
